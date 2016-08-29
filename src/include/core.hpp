#ifndef __FRAPU_CORE_HPP__
#define __FRAPU_CORE_HPP__
#include "typedefs.hpp"
#include "interface.hpp"
#include "Obstacle.hpp"
#include "utils.hpp"

namespace frapu
{

struct EnvironmentInfo {
public:
    EnvironmentInfo() {};
    std::vector<ObstacleSharedPtr> obstacles;
};





}

#endif
