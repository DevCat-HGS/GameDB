#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "objective.h"
#include "physicsmodel.h"

class Level {
public:
    Level();
    Level(int levelNumber, const std::string& description);
    
    int getLevelNumber() const;
    std::string getDescription() const;
    std::vector<Objective> getObjectives() const;
    std::vector<PhysicsModel> getPhysics() const;
    
    void setLevelNumber(int levelNumber);
    void setDescription(const std::string& description);
    void addObjective(const Objective& objective);
    void addPhysicsModel(const PhysicsModel& physicsModel);
    
    void loadLevel(); // Carga los recursos y configuración del nivel
    bool checkCompletion(); // Verifica si todos los objetivos del nivel se han completado
    
private:
    int levelNumber;
    std::string description;
    std::vector<Objective> objectives;
    std::vector<PhysicsModel> physics;
};

#endif // LEVEL_H