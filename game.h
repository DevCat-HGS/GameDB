#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "player.h"
#include "enemy.h"
#include "physicsengine.h"
#include "level.h"

class Game : public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

    void startGame();
    void nextLevel();

public slots:
    void update();

private:
    QGraphicsScene *scene;
    QTimer *timer;
    int currentLevel;
    Player *player;
    QList<Enemy*> enemies;
    PhysicsEngine *physicsEngine;
    Level *level;

    void setupLevel(int levelNumber);
    void cleanupLevel();
};

#endif // GAME_H