#ifndef __HEURISTIC_FUNCTION_HPP__
#define __HEURISTIC_FUNCTION_HPP__
#include "typedefs.hpp"
#include "logging.hpp"
#include "trajectory.hpp"
#include "RewardModel.hpp"
#include "EnvironmentInfo.hpp"

namespace frapu
{

class HeuristicInfo
{
public:
    HeuristicInfo():
        currentBelief(nullptr),
        currentState(nullptr),
        rewardModel(nullptr) {

    }

    frapu::BeliefSharedPtr currentBelief;

    frapu::RobotStateSharedPtr currentState;

    frapu::RewardModelSharedPtr rewardModel;

    double timeout;

    unsigned int currentStep;

};

class HeuristicFunction
{
public:
    HeuristicFunction():
        robot_(nullptr),
        pathPlanner_(nullptr),
        collisionChecker_(nullptr),
        terminalFunction_(nullptr) {

    }

    virtual double operator()(frapu::HeuristicInfoSharedPtr& heuristicInfo) const = 0;

    virtual bool requiresRobot() const = 0;

    virtual bool requiresPathPlanner() const = 0;
    
    virtual void setPathPlanner(frapu::PathPlannerSharedPtr &pathPlanner) {
	pathPlanner_ = pathPlanner;
    }
    
    virtual void setCollisionChecker(frapu::CollisionCheckerSharedPtr &collisionChecker) {
	collisionChecker_ = collisionChecker;	
    }
    
    virtual void setTerminalFunction(std::function<bool(frapu::RobotStateSharedPtr)> terminalFunction) {
	terminalFunction_ = terminalFunction;
    }
    
    virtual void setRobot(frapu::RobotSharedPtr &robot) {
	robot_ = robot;
    }
    
protected:
    frapu::RobotSharedPtr robot_;

    frapu::PathPlannerSharedPtr pathPlanner_;
    
    frapu::CollisionCheckerSharedPtr collisionChecker_;
    
    frapu::EnvironmentInfoSharedPtr environmentInfo_;
    
    std::function<bool(frapu::RobotStateSharedPtr)> terminalFunction_;

};

class RRTHeuristicFunction: public HeuristicFunction
{
public:
    RRTHeuristicFunction():
        HeuristicFunction() {

    }
    
    virtual bool requiresRobot() const override {
	return true;
    }

    virtual bool requiresPathPlanner() const override {
	return true;
    }

    virtual double operator()(frapu::HeuristicInfoSharedPtr& heuristicInfo) const override {
        if (!heuristicInfo->rewardModel) {
            frapu::WARNING("Reward model is nullptr. Did you forget to set a reward model in your HeuristicInfo? Returning 0.0");
            return 0.0;
        }
        
        if (!pathPlanner_) {
	    frapu::ERROR("RRTHeuristicFunction: PathPlanner has not been set");
	}
	
	if (!collisionChecker_) {
	    frapu::ERROR("RRTHeuristicFunction: CollisionChecker has not been set");
	}
	
	if (!terminalFunction_) {
	    frapu::ERROR("RRTHeuristicFunction: terminalFunction has not been set");
	}

        frapu::RewardModelSharedPtr rewardModel = heuristicInfo->rewardModel;
        frapu::TrajectorySharedPtr trajectory =
            pathPlanner_->solve(heuristicInfo->currentState, heuristicInfo->timeout);
        if (!trajectory) {
            return 0.0;
        }

        frapu::CollisionReportSharedPtr collisionReport = std::make_shared<frapu::CollisionReport>();
        collisionReport->continuousCollisionCheck = false;
        collisionReport->state1 = nullptr;
        collisionReport->ignoreUnobservableObstacles = true;
        double reward = 0.0;
        for (size_t i = 0; i < trajectory->stateTrajectory.size(); i++) {
            if (terminalFunction_(trajectory->stateTrajectory[i])) {
                reward += std::pow(rewardModel->discountFactor, heuristicInfo->currentStep + i) * rewardModel->exitReward;
                break;
            }

            collisionReport->state2 = trajectory->stateTrajectory[i];
            collisionChecker_->makeCollisionReport(collisionReport);
            if (collisionReport->collides) {
                if (collisionReport->obstacleTraversable) {
                    frapu::ObstacleSharedPtr obstacle =
                        environmentInfo_->scene->getObstacle(collisionReport->collidingObstacle);
                    double traversalCost = obstacle->getTerrain()->getTraversalCost();
                    reward += reward += std::pow(rewardModel->discountFactor, heuristicInfo->currentStep + i) * traversalCost;
                } else {
                    frapu::ERROR("WE collide!");
                    reward -= std::pow(rewardModel->discountFactor, heuristicInfo->currentStep + i) * rewardModel->illegalActionPenalty;
                }
            }
        }

        return reward;
    }

};

}

#endif
