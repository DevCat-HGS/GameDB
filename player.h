#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "vector2d.h"

class Player {
public:
    Player();
    Player(const std::string& name, const Vector2D& position, const Vector2D& velocity, int health);
    
    std::string getName() const;
    Vector2D getPosition() const;
    Vector2D getVelocity() const;
    int getHealth() const;
    
    void setName(const std::string& name);
    void setPosition(const Vector2D& position);
    void setVelocity(const Vector2D& velocity);
    void setHealth(int health);
    
    void move(); // Mueve al jugador según su velocidad y las entradas del usuario
    void attack(); // Realiza un ataque
    void collectItem(); // Recoge un ítem
    
    void takeDamage(int amount); // Reduce la salud del jugador
    void heal(int amount); // Aumenta la salud del jugador
    bool isAlive() const; // Verifica si el jugador sigue vivo
    
private:
    std::string name;
    Vector2D position;
    Vector2D velocity;
    int health;
};

#endif // PLAYER_H