#include "game.h"
#include <iostream>

Game::Game() : currentLevel(0) {
    loadLevels();
    initializePhysics();
}

int Game::getCurrentLevel() const {
    return currentLevel;
}

Player Game::getPlayer() const {
    return player;
}

std::vector<Enemy> Game::getEnemies() const {
    return enemies;
}

PhysicsEngine Game::getPhysicsEngine() const {
    return physicsEngine;
}

void Game::setCurrentLevel(int level) {
    if (level >= 0 && level < static_cast<int>(levels.size())) {
        currentLevel = level;
    }
}

void Game::setPlayer(const Player& player) {
    this->player = player;
}

void Game::addEnemy(const Enemy& enemy) {
    enemies.push_back(enemy);
}

void Game::removeEnemy(int index) {
    if (index >= 0 && index < static_cast<int>(enemies.size())) {
        enemies.erase(enemies.begin() + index);
    }
}

void Game::setPhysicsEngine(const PhysicsEngine& physicsEngine) {
    this->physicsEngine = physicsEngine;
}

void Game::startGame() {
    std::cout << "¡Iniciando juego!" << std::endl;
    
    // Inicializar el jugador (Goku)
    player = Player("Goku", Vector2D(100, 100), Vector2D(0, 0), 100);
    
    // Limpiar enemigos anteriores
    enemies.clear();
    
    // Establecer el nivel inicial
    currentLevel = 0;
    
    // Cargar el primer nivel
    if (!levels.empty()) {
        levels[currentLevel].loadLevel();
        std::cout << "Nivel 1: " << levels[currentLevel].getDescription() << std::endl;
    }
}

void Game::nextLevel() {
    // Avanzar al siguiente nivel
    currentLevel++;
    
    if (currentLevel < static_cast<int>(levels.size())) {
        // Limpiar enemigos del nivel anterior
        enemies.clear();
        
        // Cargar el nuevo nivel
        levels[currentLevel].loadLevel();
        std::cout << "Nivel " << (currentLevel + 1) << ": " << levels[currentLevel].getDescription() << std::endl;
    } else {
        // El jugador ha completado todos los niveles
        std::cout << "¡Felicidades! Has completado todos los niveles del juego." << std::endl;
    }
}

void Game::update() {
    // Actualizar el estado del juego
    
    // Actualizar al jugador
    if (player.isAlive()) {
        player.move();
    } else {
        std::cout << "Game Over: El jugador ha sido derrotado" << std::endl;
        return;
    }
    
    // Actualizar enemigos
    for (auto& enemy : enemies) {
        enemy.act();
    }
    
    // Aplicar física
    physicsEngine.applyPhysics(&player);
    for (auto& enemy : enemies) {
        physicsEngine.applyPhysics(&enemy);
    }
    
    // Verificar si se ha completado el nivel actual
    if (currentLevel < static_cast<int>(levels.size()) && levels[currentLevel].checkCompletion()) {
        std::cout << "¡Nivel " << (currentLevel + 1) << " completado!" << std::endl;
        nextLevel();
    }
}

void Game::loadLevels() {
    // Crear y configurar los niveles del juego según la descripción
    
    // Nivel 1: Montañas de Goku
    Level level1(1, "Montañas de Goku");
    level1.addObjective(Objective("Recolectar frutas colgantes"));
    level1.addObjective(Objective("Derrotar un jabalí"));
    level1.addPhysicsModel(PhysicsModel("Salto", "Movimiento parabólico"));
    level1.addPhysicsModel(PhysicsModel("Enemigo Abeja", "Movimiento oscilatorio"));
    level1.addPhysicsModel(PhysicsModel("Suelo Rocoso", "Fricción"));
    levels.push_back(level1);
    
    // Nivel 2: Camino al Encuentro
    Level level2(2, "Camino al Encuentro");
    level2.addObjective(Objective("Resolver puzzles para cruzar el río"));
    level2.addObjective(Objective("Recuperar una cápsula oculta"));
    level2.addPhysicsModel(PhysicsModel("Objetos Lanzados", "Trayectoria parabólica"));
    level2.addPhysicsModel(PhysicsModel("Colisiones", "Colisiones físicas"));
    level2.addPhysicsModel(PhysicsModel("Plataformas Móviles", "Movimiento sinusoidal"));
    levels.push_back(level2);
    
    // Nivel 3: Aldea del Terror
    Level level3(3, "Aldea del Terror");
    level3.addObjective(Objective("Derrotar al mini-jefe del nivel"));
    level3.addObjective(Objective("Rescatar 3 aldeanos escondidos"));
    level3.addPhysicsModel(PhysicsModel("Combate", "Colisiones dinámicas"));
    level3.addPhysicsModel(PhysicsModel("Explosiones", "Propagación radial"));
    level3.addPhysicsModel(PhysicsModel("Caída de Objetos", "Caída desde estructuras"));
    levels.push_back(level3);
}

void Game::initializePhysics() {
    // Inicializar los modelos físicos del juego
    
    // Movimiento parabólico (saltos, objetos lanzados)
    PhysicsModel parabolicModel("Parabólico", "y = y0 + v0*sin(angle)*t - 0.5*g*t^2");
    physicsEngine.addModel(parabolicModel);
    
    // Movimiento oscilatorio (enemigos como abejas)
    PhysicsModel oscillatoryModel("Oscilatorio", "x = x0 + A*sin(w*t)");
    physicsEngine.addModel(oscillatoryModel);
    
    // Fricción (movimiento en suelo rocoso)
    PhysicsModel frictionModel("Fricción", "v = v0 * (1 - mu)");
    physicsEngine.addModel(frictionModel);
    
    // Movimiento sinusoidal (plataformas móviles)
    PhysicsModel sinusoidalModel("Sinusoidal", "y = y0 + A*sin(w*t)");
    physicsEngine.addModel(sinusoidalModel);
    
    // Propagación radial (explosiones)
    PhysicsModel radialModel("Radial", "r = r0 + v*t");
    physicsEngine.addModel(radialModel);
}