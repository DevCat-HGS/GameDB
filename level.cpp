#include "level.h"
#include <iostream>
#include <algorithm>

Level::Level() : levelNumber(0), description("") {}

Level::Level(int levelNumber, const std::string& description)
    : levelNumber(levelNumber), description(description) {}

int Level::getLevelNumber() const {
    return levelNumber;
}

std::string Level::getDescription() const {
    return description;
}

std::vector<Objective> Level::getObjectives() const {
    return objectives;
}

std::vector<PhysicsModel> Level::getPhysics() const {
    return physics;
}

void Level::setLevelNumber(int levelNumber) {
    this->levelNumber = levelNumber;
}

void Level::setDescription(const std::string& description) {
    this->description = description;
}

void Level::addObjective(const Objective& objective) {
    objectives.push_back(objective);
}

void Level::addPhysicsModel(const PhysicsModel& physicsModel) {
    physics.push_back(physicsModel);
}

void Level::loadLevel() {
    // Esta función cargará los recursos y configuración específicos del nivel
    std::cout << "Cargando nivel " << levelNumber << ": " << description << std::endl;
    
    // Aquí se cargarían los recursos gráficos, enemigos, objetos, etc.
    // También se configurarían los modelos físicos específicos del nivel
    
    // Configuración específica para cada nivel según la descripción del juego
    switch (levelNumber) {
        case 1: // Montañas de Goku
            // Configurar física de salto (movimiento parabólico)
            // Configurar física de enemigos (movimiento oscilatorio para abejas)
            // Configurar física de fricción en suelo rocoso
            break;
            
        case 2: // Camino al Encuentro
            // Configurar física de objetos lanzados (trayectorias parabólicas)
            // Configurar colisiones entre objetos móviles y estructuras
            // Configurar plataformas móviles (movimiento sinusoidal)
            break;
            
        case 3: // Aldea del Terror
            // Configurar física de combate (colisiones dinámicas)
            // Configurar explosiones (propagación radial)
            // Configurar física de caída de objetos
            break;
            
        default:
            std::cout << "Nivel desconocido" << std::endl;
            break;
    }
}

bool Level::checkCompletion() {
    // Verificar si todos los objetivos del nivel se han completado
    return std::all_of(objectives.begin(), objectives.end(), 
                      [](const Objective& obj) { return obj.isCompleted(); });
}