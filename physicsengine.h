#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <QList>
#include <QGraphicsItem>
#include "physicsmodel.h"

class PhysicsEngine
{
public:
    PhysicsEngine();
    ~PhysicsEngine();
    
    // Método según el diagrama UML
    void applyPhysics(QGraphicsItem *entity);
    
    // Getters y setters
    QList<PhysicsModel*> getModels() const { return models; }
    void addModel(PhysicsModel *model);
    
private:
    // Atributos según el diagrama UML
    QList<PhysicsModel*> models;
};

#endif // PHYSICSENGINE_H