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

class Scene;
typedef std::shared_ptr<frapu::Scene> SceneSharedPtr;

struct EnvironmentInfo;
typedef std::shared_ptr<frapu::EnvironmentInfo> EnvironmentInfoSharedPtr;
typedef std::unique_ptr<frapu::EnvironmentInfo> EnvironmentInfoUniquePtr;

typedef std::shared_ptr<fcl::CollisionObject> CollisionObjectSharedPtr;

class CollisionReport;
typedef std::shared_ptr<CollisionReport> CollisionReportSharedPtr;

class CollisionChecker;
typedef std::shared_ptr<CollisionChecker> CollisionCheckerSharedPtr;

class Robot;
typedef std::shared_ptr<frapu::Robot> RobotSharedPtr;
typedef std::unique_ptr<frapu::Robot> RobotUniquePtr;

class RobotState;
class VectorState;
typedef std::shared_ptr<frapu::RobotState> RobotStateSharedPtr;
typedef std::shared_ptr<const frapu::RobotState> ConstRobotStateSharedPtr;
typedef std::shared_ptr<frapu::VectorState> VectorStateSharedPtr;

class RobotEnvironment;
typedef std::shared_ptr<frapu::RobotEnvironment> RobotEnvironmentSharedPtr;

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

class HeuristicInfo;
typedef std::shared_ptr<frapu::HeuristicInfo> HeuristicInfoSharedPtr;

class HeuristicFunction;
typedef std::shared_ptr<frapu::HeuristicFunction> HeuristicFunctionSharedPtr;

class Belief;
typedef std::shared_ptr<frapu::Belief> BeliefSharedPtr;

class Particle;
typedef std::shared_ptr<frapu::Particle> ParticleSharedPtr;

class Serializer;
typedef std::shared_ptr<frapu::Serializer> SerializerSharedPtr;

class PathPlanner;
typedef std::shared_ptr<frapu::PathPlanner> PathPlannerSharedPtr;

class Trajectory;
typedef std::shared_ptr<frapu::Trajectory> TrajectorySharedPtr;

class RewardModel;
typedef std::shared_ptr<frapu::RewardModel> RewardModelSharedPtr;

class Goal;
typedef std::shared_ptr<frapu::Goal> GoalSharedPtr;


}

#endif
