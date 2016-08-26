#ifndef __FRAPU_OBSTACLE_HPP__
#define __FRAPU_OBSTACLE_HPP__
#include "includes.hpp"
#include "typedefs.hpp"

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

}

#endif
