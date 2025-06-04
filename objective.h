#ifndef OBJECTIVE_H
#define OBJECTIVE_H

#include <QString>

class Objective
{
public:
    Objective(const QString &desc, bool isComplete = false);
    
    // Método según el diagrama UML
    bool check();
    
    // Getters y setters
    QString getDescription() const { return description; }
    bool isCompleted() const { return completed; }
    void setCompleted(bool value) { completed = value; }
    
private:
    // Atributos según el diagrama UML
    QString description;
    bool completed;
};

#endif // OBJECTIVE_H