#ifndef GAME_H
#define GAME_H

#include <vector>
#include "player.h"
#include "enemy.h"
#include "physicsengine.h"
#include "level.h"

class Game {
public:
    Game();
    
    int getCurrentLevel() const;
    Player getPlayer() const;
    std::vector<Enemy> getEnemies() const;
    PhysicsEngine getPhysicsEngine() const;
    
    void setCurrentLevel(int level);
    void setPlayer(const Player& player);
    void addEnemy(const Enemy& enemy);
    void removeEnemy(int index);
    void setPhysicsEngine(const PhysicsEngine& physicsEngine);
    
    void startGame(); // Inicia el juego
    void nextLevel(); // Avanza al siguiente nivel
    void update(); // Actualiza el estado del juego
    
    void loadLevels(); // Carga todos los niveles del juego
    void initializePhysics(); // Inicializa los modelos físicos
    
private:
    int currentLevel;
    Player player;
    std::vector<Enemy> enemies;
    PhysicsEngine physicsEngine;
    std::vector<Level> levels;
};

#endif // GAME_H