#ifndef LEVEL_H
#define LEVEL_H

#include <QString>
#include <QList>
#include "objective.h"

class Level
{
public:
    Level(int number);
    ~Level();
    
    // Métodos según el diagrama UML
    void loadLevel();
    bool checkCompletion();
    
    // Getters
    int getLevelNumber() const { return levelNumber; }
    QString getDescription() const { return description; }
    QList<Objective*> getObjectives() const { return objectives; }
    QString getPhysics() const { return physics; }
    
private:
    // Atributos según el diagrama UML
    int levelNumber;
    QString description;
    QList<Objective*> objectives;
    QString physics;
};

#endif // LEVEL_H