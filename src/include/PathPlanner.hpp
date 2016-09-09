#ifndef __FRAPU_PATH_PLANNER_HPP__
#define __FRAPU_PATH_PLANNER_HPP__
#include "typedefs.hpp"

namespace frapu
{

class PathPlanner
{
public:
    PathPlanner() {

    }

    virtual TrajectorySharedPtr solve(const RobotStateSharedPtr& robotState,
                                      double timeout) = 0;

    //virtual void setup(frapu::SceneSharedPtr& scene, frapu::RobotSharedPtr& robot) = 0;


};

class CollisionChecker
{
public:
    CollisionChecker() {

    }

    virtual void makeCollisionReport(frapu::CollisionReportSharedPtr& collisionReport) const = 0;

};

}

#endif
