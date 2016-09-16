#ifndef __FRAPU_OBSTACLE_HPP__
#define __FRAPU_OBSTACLE_HPP__
#include "includes.hpp"
#include "typedefs.hpp"

using std::cout;
using std::endl;

namespace frapu
{

class Terrain
{
public:
    Terrain(bool& traversable, bool& observable):
        traversable_(traversable),
        observable_(observable) {

    }

    const bool isTraversable() const {
        return traversable_;
    }

    const bool isObservable() const {
        return observable_;
    }

    virtual const double getTraversalCost() const = 0;

protected:
    bool traversable_;

    bool observable_;

};

class Obstacle
{
public:
    Obstacle(std::string& name, TerrainSharedPtr& terrain):
        terrain_(terrain),
        name_(name),
        collisionObject_(nullptr) {

    }

    virtual void createCollisionObject() = 0;

    virtual bool inCollision(std::vector<CollisionObjectSharedPtr>& collisionObjects) const = 0;

    virtual bool inCollisionContinuous(CollisionObjectSharedPtr& collisionObjectStart,
                                       CollisionObjectSharedPtr& collisionObjectGoal) const = 0;

    virtual void getDimensions(std::vector<double>& dimensions) const = 0;

    CollisionObjectSharedPtr getCollisionObject() const {
        return collisionObject_;
    }

    std::string getName() {
        return name_;
    }

    frapu::TerrainSharedPtr getTerrain() {
        return terrain_;
    }

protected:
    std::string name_;

    frapu::TerrainSharedPtr terrain_;

    frapu::CollisionObjectSharedPtr collisionObject_;

};

class Scene
{
public:
    Scene():
        obstacles_() {

    }

    void setObstacles(std::vector<frapu::ObstacleSharedPtr>& obstacles) {
        obstacles_ = obstacles;
    }

    void addObstacle(frapu::ObstacleSharedPtr& obstacle) {
        for (size_t i = 0; i < obstacles_.size(); i++) {
            if (obstacles_[i]->getName() == obstacle->getName()) {
                cout << "Scene addObstacle: Obstacle '" << obstacle->getName() << "' already exist. Replacing current instance." << endl;
                removeObstacle(obstacle->getName());
            }
        }

        obstacles_.push_back(obstacle);
    }

    bool removeObstacle(std::string obstacleName) {
        for (size_t i = 0; i < obstacles_.size(); i++) {
            if (obstacles_[i]->getName() == obstacleName) {
                obstacles_.erase(obstacles_.begin() + i);
                return true;
            }
        }

        cout << "Scene: Couldn't remove obstacle '" << obstacleName << "'. Obstacle doesn't exist" << endl;
        return true;
    }

    bool removeObstacles(std::vector<std::string>& obstacle_names) {
        for (auto & k : obstacle_names) {
            removeObstacle(k);
        }

        return true;
    }

    void getObstacles(std::vector<frapu::ObstacleSharedPtr>& obstacles) const {
        obstacles = obstacles_;
    }

    frapu::ObstacleSharedPtr getObstacle(std::string name) const {
        for (size_t i = 0; i < obstacles_.size(); i++) {
            if (obstacles_[i]->getName() == name) {
                return obstacles_[i];
            }
        }

        cout << "Scene: Warning: Obstacle '" << name << "' doesn't exist";
        return nullptr;
    }

    void getTraversableObstacles(std::vector<frapu::ObstacleSharedPtr>& traversableObstacles) const {
        traversableObstacles.clear();
        for (size_t i = 0; i < obstacles_.size(); i++) {
            if (obstacles_[i]->getTerrain()->isTraversable()) {
                traversableObstacles.push_back(obstacles_[i]);
            }
        }
    }

    void getObservableObstacles(std::vector<frapu::ObstacleSharedPtr>& obstacles) const {
        obstacles.clear();
        for (size_t i = 0; i < obstacles_.size(); i++) {
            if (obstacles_[i]->getTerrain()->isObservable()) {
                obstacles.push_back(obstacles_[i]);
            }
        }
    }

private:
    std::vector<frapu::ObstacleSharedPtr> obstacles_;
};

}

#endif
