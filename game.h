#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "PhysicsEngine.h"

class Game {
public:
    int currentLevel;
    Player player;
    std::vector<Enemy> enemies;
    PhysicsEngine physicsEngine;

    void startGame();
    void nextLevel();
    void update();
};

#endif // GAME_H 