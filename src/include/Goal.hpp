#ifndef __FRAPU_GOAL_HPP__
#define __FRAPU_GOAL_HPP__
#include "typedefs.hpp"
#include "utils.hpp"

namespace frapu
{
class Goal
{
public:
    Goal() {

    }

    virtual bool isSatisfied(frapu::RobotStateSharedPtr& state) const = 0;

};

class SpatialGoal: public Goal
{
public:
    SpatialGoal(std::vector<double>& center):
        Goal(),
        center_(center) {

    }

    virtual double distanceCenter(const std::vector<double>& point) const = 0;
    
    virtual getGoalArea(std::vector<double> &goalArea) const = 0;

protected:
    std::vector<double> center_;

};

class SphereGoal: public SpatialGoal
{
public:
    SphereGoal(std::vector< double >& center, double& radius):
        SpatialGoal(center),
        radius_(radius) {

    }

    virtual double distanceCenter(const std::vector<double>& point) const override {
	return euclideanDistance(point, center_);
    }
    
    virtual bool isSatisfied(frapu::RobotStateSharedPtr& state) const override {
	return false;
    }
    
    virtual double isSatisfied(const std::vector<double>& point) const {
	if (distanceCenter(point) < radius_) {
	    return true;
	}
	
	return false;
    }
    
    virtual getGoalArea(std::vector<double> &goalArea) const override {
	goalArea = std::vector<double>(4);	
	goalArea[0] = center_[0];
	goalArea[1] = center_[1];
	goalArea[2] = center_[2];
	goalArea[3] = radius_;	
    }

protected:
    double radius_;

};

}

#endif
