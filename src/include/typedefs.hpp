#ifndef __FRAPU_TYPEDEFS_HPP__
#define __FRAPU_TYPEDEFS_HPP__
#include "includes.hpp"

namespace frapu
{

class Terrain;
class Obstacle;
typedef std::shared_ptr<frapu::Obstacle> ObstacleSharedPtr;
typedef std::unique_ptr<frapu::Obstacle> ObstacleUniquePtr;

typedef std::shared_ptr<frapu::Terrain> TerrainSharedPtr;
typedef std::unique_ptr<frapu::Terrain> TerrainUniquePtr;

struct EnvironmentInfo;
typedef std::shared_ptr<frapu::EnvironmentInfo> EnvironmentInfoSharedPtr;
typedef std::unique_ptr<frapu::EnvironmentInfo> EnvironmentInfoUniquePtr;

typedef std::shared_ptr<fcl::CollisionObject> CollisionObjectSharedPtr;

class RobotState;
typedef std::shared_ptr<frapu::RobotState> RobotStateSharedPtr;


}

#endif
