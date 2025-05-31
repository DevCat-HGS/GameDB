#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "vector2d.h"

class Enemy {
public:
    Enemy();
    Enemy(const std::string& type, const Vector2D& position, const std::string& behavior);
    
    std::string getType() const;
    Vector2D getPosition() const;
    std::string getBehavior() const;
    
    void setType(const std::string& type);
    void setPosition(const Vector2D& position);
    void setBehavior(const std::string& behavior);
    
    void act(); // Realiza acciones según el comportamiento definido
    void attackPlayer(); // Ataca al jugador
    
private:
    std::string type;
    Vector2D position;
    std::string behavior;
};

#endif // ENEMY_H