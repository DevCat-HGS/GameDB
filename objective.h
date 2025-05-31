#ifndef OBJECTIVE_H
#define OBJECTIVE_H

#include <string>

class Objective {
public:
    Objective();
    Objective(const std::string& description);
    
    std::string getDescription() const;
    bool isCompleted() const;
    
    void setDescription(const std::string& description);
    void setCompleted(bool completed);
    
    bool check(); // Verifica si el objetivo se ha completado
    
private:
    std::string description;
    bool completed;
};

#endif // OBJECTIVE_H