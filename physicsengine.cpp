#include "physicsengine.h"
#include <algorithm>
#include <iostream>
#include <cmath>

PhysicsEngine::PhysicsEngine() {}

void PhysicsEngine::addModel(const PhysicsModel& model) {
    models.push_back(model);
}

void PhysicsEngine::removeModel(const std::string& modelName) {
    models.erase(
        std::remove_if(models.begin(), models.end(),
            [&modelName](const PhysicsModel& model) { return model.getName() == modelName; }),
        models.end());
}

PhysicsModel* PhysicsEngine::getModel(const std::string& modelName) {
    for (auto& model : models) {
        if (model.getName() == modelName) {
            return &model;
        }
    }
    return nullptr;
}

void PhysicsEngine::applyPhysics(void* entity) {
    // Esta función aplicará el modelo físico apropiado a la entidad
    // En una implementación real, se determinaría qué modelo aplicar basado en el tipo de entidad
    std::cout << "Aplicando física a entidad" << std::endl;
    
    // Aquí se llamaría a los métodos específicos según el tipo de física requerida
}

void PhysicsEngine::applyParabolicMotion(void* entity, float initialVelocity, float angle) {
    // Implementación del movimiento parabólico (saltos, objetos lanzados)
    // En una implementación real, se actualizaría la posición de la entidad según las ecuaciones del movimiento parabólico
    std::cout << "Aplicando movimiento parabólico" << std::endl;
    
    // Ejemplo de ecuaciones para movimiento parabólico:
    // x = x0 + v0 * cos(angle) * t
    // y = y0 + v0 * sin(angle) * t - 0.5 * g * t^2
}

void PhysicsEngine::applyOscillatoryMotion(void* entity, float amplitude, float frequency) {
    // Implementación del movimiento oscilatorio (enemigos como abejas)
    // En una implementación real, se actualizaría la posición de la entidad según las ecuaciones del movimiento oscilatorio
    std::cout << "Aplicando movimiento oscilatorio" << std::endl;
    
    // Ejemplo de ecuaciones para movimiento oscilatorio:
    // x = x0 + amplitude * sin(frequency * t)
}

void PhysicsEngine::applyFriction(void* entity, float frictionCoefficient) {
    // Implementación de la fricción (movimiento en suelo rocoso)
    // En una implementación real, se reduciría la velocidad de la entidad según el coeficiente de fricción
    std::cout << "Aplicando fricción" << std::endl;
    
    // Ejemplo de ecuación para fricción:
    // v = v0 * (1 - frictionCoefficient)
}

void PhysicsEngine::applySinusoidalMotion(void* entity, float amplitude, float frequency) {
    // Implementación del movimiento sinusoidal (plataformas móviles)
    // En una implementación real, se actualizaría la posición de la entidad según las ecuaciones del movimiento sinusoidal
    std::cout << "Aplicando movimiento sinusoidal" << std::endl;
    
    // Ejemplo de ecuaciones para movimiento sinusoidal:
    // y = y0 + amplitude * sin(frequency * t)
}

void PhysicsEngine::applyRadialPropagation(void* entity, float initialRadius, float propagationSpeed) {
    // Implementación de la propagación radial (explosiones)
    // En una implementación real, se afectaría a todas las entidades dentro de un radio creciente
    std::cout << "Aplicando propagación radial" << std::endl;
    
    // Ejemplo de ecuación para propagación radial:
    // radius = initialRadius + propagationSpeed * t
}