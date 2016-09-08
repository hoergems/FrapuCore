#ifndef __FRAPU_COLLISION_REPORT_HPP__
#define __FRAPU_COLLISION_REPORT_HPP__
#include "typedefs.hpp"

namespace frapu
{

class CollisionReport
{
public:
    CollisionReport() {

    }

    // Continuous collision check
    bool continuousCollisionCheck = false;

    // Ignore unobservable obstacles when doing collision checking
    bool ignoreUnobservableObstacles = false;

    // Did we collide?
    bool collides = false;

    // The previous state
    frapu::RobotStateSharedPtr state1;

    // The next state
    frapu::RobotStateSharedPtr state2;

    // The obstacle we collided with
    std::string collidingObstacle;

    // Did we collide with an traversable obstacle?
    bool obstacleTraversable = false;
};

}

#endif
