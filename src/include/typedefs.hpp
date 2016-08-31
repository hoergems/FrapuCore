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
class VectorState;
typedef std::shared_ptr<frapu::RobotState> RobotStateSharedPtr;
typedef std::shared_ptr<const frapu::RobotState> ConstRobotStateSharedPtr;
typedef std::shared_ptr<frapu::VectorState> VectorStateSharedPtr;

class Action;
class VectorAction;
typedef std::shared_ptr<frapu::Action> ActionSharedPtr;
typedef std::unique_ptr<frapu::Action> ActionUniquePtr;
typedef std::shared_ptr<const frapu::Action> ConstActionSharedPtr;
typedef std::shared_ptr<frapu::VectorAction> VectorActionSharedPtr;
typedef std::unique_ptr<frapu::VectorAction> VectorActionUniquePtr;

class Observation;
class VectorObservation;
typedef std::shared_ptr<frapu::Observation> ObservationSharedPtr;
typedef std::unique_ptr<frapu::Observation> ObservationUniquePtr;
typedef std::shared_ptr<const frapu::Observation> ConstObservationSharedPtr;
typedef std::shared_ptr<frapu::VectorObservation> VectorObservationSharedPtr;
typedef std::unique_ptr<frapu::VectorObservation> VectorObservationUniquePtr;

class ActionSpace;
typedef std::shared_ptr<frapu::ActionSpace> ActionSpaceSharedPtr;
class StateSpace;
typedef std::shared_ptr<frapu::StateSpace> StateSpaceSharedPtr;
class ObservationSpace;
typedef std::shared_ptr<frapu::ObservationSpace> ObservationSpaceSharedPtr;

class ActionLimits;
typedef std::shared_ptr<frapu::ActionLimits> ActionLimitsSharedPtr;

class StateLimits;
typedef std::shared_ptr<frapu::StateLimits> StateLimitsSharedPtr;


}

#endif
