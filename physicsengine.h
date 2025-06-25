#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>
#include "PhysicsModel.h"

class PhysicsEngine {
public:
    std::vector<PhysicsModel> models;
    void applyPhysics(void* entity);
};

#endif // PHYSICSENGINE_H 