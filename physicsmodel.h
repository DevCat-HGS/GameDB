#ifndef PHYSICSMODEL_H
#define PHYSICSMODEL_H

#include <string>

class PhysicsModel {
public:
    std::string name;
    std::string formula;

    void simulate();
};

#endif // PHYSICSMODEL_H 