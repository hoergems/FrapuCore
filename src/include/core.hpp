#ifndef __FRAPU_CORE_HPP__
#define __FRAPU_CORE_HPP__
#include "typedefs.hpp"
#include "interface.hpp"
#include "Obstacle.hpp"
#include "PathPlanner.hpp"
#include "utils.hpp"
#include "Goal.hpp"
#include "logging.hpp"

namespace frapu
{

class EnvironmentInfo
{
public:
    EnvironmentInfo():
        scene() {

    };

    frapu::EnvironmentInfoSharedPtr copy() const {
        frapu::EnvironmentInfoSharedPtr copiedEnvironmentInfo = std::make_shared<frapu::EnvironmentInfo>();
        copiedEnvironmentInfo->scene = scene;
        return copiedEnvironmentInfo;
    }

    frapu::SceneSharedPtr scene;
};





}

#endif
