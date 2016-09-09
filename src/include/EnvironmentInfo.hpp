#ifndef __ENVIRONMENT_INFO_HPP__
#define __ENVIRONMENT_INFO_HPP__
#include "typedefs.hpp"
#include "Obstacle.hpp"

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
