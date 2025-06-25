#ifndef ENEMY_H
#define ENEMY_H

#include "Vector2D.h"
#include <string>

class Enemy {
public:
    std::string type;
    Vector2D position;
    std::string behavior;

    void act();
    void attackPlayer();
};

#endif // ENEMY_H 