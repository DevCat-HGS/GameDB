#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>
#include "physicsmodel.h"

class PhysicsEngine {
public:
    PhysicsEngine();
    
    void addModel(const PhysicsModel& model);
    void removeModel(const std::string& modelName);
    PhysicsModel* getModel(const std::string& modelName);
    
    void applyPhysics(void* entity); // En una implementación real, esto sería un tipo específico
    
    // Métodos para diferentes tipos de física mencionados en la descripción
    void applyParabolicMotion(void* entity, float initialVelocity, float angle);
    void applyOscillatoryMotion(void* entity, float amplitude, float frequency);
    void applyFriction(void* entity, float frictionCoefficient);
    void applySinusoidalMotion(void* entity, float amplitude, float frequency);
    void applyRadialPropagation(void* entity, float initialRadius, float propagationSpeed);
    
private:
    std::vector<PhysicsModel> models;
};

#endif // PHYSICSENGINE_H