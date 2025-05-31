#ifndef PHYSICSMODEL_H
#define PHYSICSMODEL_H

#include <string>

class PhysicsModel {
public:
    PhysicsModel();
    PhysicsModel(const std::string& name, const std::string& formula);
    
    std::string getName() const;
    std::string getFormula() const;
    
    void setName(const std::string& name);
    void setFormula(const std::string& formula);
    
    void simulate();
    
private:
    std::string name;
    std::string formula;
};

#endif // PHYSICSMODEL_H