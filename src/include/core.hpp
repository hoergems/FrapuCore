#ifndef __FRAPU_CORE_HPP__
#define __FRAPU_CORE_HPP__
#include "typedefs.hpp"
#include "interface.hpp"
#include "Obstacle.hpp"
#include "PathPlanner.hpp"
#include "utils.hpp"

namespace frapu
{

class EnvironmentInfo {
public:
    EnvironmentInfo():
        obstacles() {

    };
    
    frapu::EnvironmentInfoSharedPtr copy() const {
	frapu::EnvironmentInfoSharedPtr copiedEnvironmentInfo = std::make_shared<frapu::EnvironmentInfo>();
	copiedEnvironmentInfo->obstacles = obstacles;
	return copiedEnvironmentInfo;
    }
    
    std::vector<ObstacleSharedPtr> obstacles;
};





}

#endif
