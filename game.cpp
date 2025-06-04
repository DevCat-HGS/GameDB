#include "game.h"
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QDebug>

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
    // Configuración de la vista
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);
    
    // Inicialización de variables
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    setScene(scene);
    
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    
    currentLevel = 0;
    player = nullptr;
    physicsEngine = nullptr;
    level = nullptr;
}

Game::~Game()
{
    cleanupLevel();
    delete scene;
    delete timer;
}

void Game::startGame()
{
    // Mostrar la vista
    show();
    
    // Inicializar el motor de física
    physicsEngine = new PhysicsEngine();
    
    // Configurar el primer nivel
    setupLevel(1);
    
    // Iniciar el bucle de juego
    timer->start(16); // Aproximadamente 60 FPS
}

void Game::nextLevel()
{
    // Limpiar el nivel actual
    cleanupLevel();
    
    // Incrementar el nivel
    currentLevel++;
    
    // Configurar el siguiente nivel
    if (currentLevel <= 3) { // Tenemos 3 niveles en total
        setupLevel(currentLevel);
    } else {
        // Fin del juego - Victoria
        qDebug() << "¡Juego completado!";
        // Aquí se podría mostrar una pantalla de victoria
    }
}

void Game::update()
{
    // Actualizar la física
    if (physicsEngine && player) {
        physicsEngine->applyPhysics(player);
        
        // Actualizar enemigos
        for (Enemy* enemy : enemies) {
            physicsEngine->applyPhysics(enemy);
            enemy->act();
        }
    }
    
    // Comprobar objetivos del nivel
    if (level && level->checkCompletion()) {
        nextLevel();
    }
}

void Game::setupLevel(int levelNumber)
{
    currentLevel = levelNumber;
    
    // Crear el nivel
    level = new Level(levelNumber);
    
    // Configurar el fondo según el nivel
    QGraphicsPixmapItem *background = nullptr;
    switch (levelNumber) {
    case 1:
        background = scene->addPixmap(QPixmap(":/images/backgrounds/level1_background.png"));
        break;
    case 2:
        background = scene->addPixmap(QPixmap(":/images/backgrounds/level2_background.png"));
        break;
    case 3:
        background = scene->addPixmap(QPixmap(":/images/backgrounds/level3_background.png"));
        break;
    }
    
    if (background) {
        background->setZValue(-1); // Colocar en el fondo
    }
    
    // Crear el jugador
    player = new Player();
    scene->addItem(player);
    player->setPos(50, 450); // Posición inicial
    
    // Crear enemigos según el nivel
    switch (levelNumber) {
    case 1: {
        // Nivel 1: Un jabalí
        Enemy *jabali = new Enemy("jabali");
        jabali->setPos(600, 450);
        scene->addItem(jabali);
        enemies.append(jabali);
        break;
    }
    case 2: {
        // Nivel 2: Algunos enemigos básicos
        for (int i = 0; i < 3; i++) {
            Enemy *enemy = new Enemy("basic");
            enemy->setPos(300 + i * 150, 450);
            scene->addItem(enemy);
            enemies.append(enemy);
        }
        break;
    }
    case 3: {
        // Nivel 3: Más enemigos y un mini-jefe
        for (int i = 0; i < 5; i++) {
            Enemy *enemy = new Enemy("soldier");
            enemy->setPos(200 + i * 100, 450);
            scene->addItem(enemy);
            enemies.append(enemy);
        }
        
        Enemy *boss = new Enemy("boss");
        boss->setPos(700, 400);
        scene->addItem(boss);
        enemies.append(boss);
        break;
    }
    }
    
    // Cargar el nivel
    level->loadLevel();
    
    // Dar el foco al jugador para recibir eventos de teclado
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
}

void Game::cleanupLevel()
{
    // Limpiar enemigos
    for (Enemy* enemy : enemies) {
        scene->removeItem(enemy);
        delete enemy;
    }
    enemies.clear();
    
    // Limpiar jugador
    if (player) {
        scene->removeItem(player);
        delete player;
        player = nullptr;
    }
    
    // Limpiar nivel
    if (level) {
        delete level;
        level = nullptr;
    }
    
    // Limpiar la escena
    scene->clear();
}