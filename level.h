#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include "Objective.h"
#include "PhysicsModel.h"

class Level {
public:
    int levelNumber;
    std::string description;
    std::vector<Objective> objectives;
    std::vector<PhysicsModel> physics;

    void loadLevel();
    bool checkCompletion();
};

#endif // LEVEL_H 