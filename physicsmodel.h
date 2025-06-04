#ifndef PHYSICSMODEL_H
#define PHYSICSMODEL_H

#include <QString>

class PhysicsModel
{
public:
    PhysicsModel(const QString &modelName, const QString &modelFormula);
    
    // Método según el diagrama UML
    void simulate();
    
    // Getters
    QString getName() const { return name; }
    QString getFormula() const { return formula; }
    
private:
    // Atributos según el diagrama UML
    QString name;
    QString formula;
};

#endif // PHYSICSMODEL_H