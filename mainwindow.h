#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include "Level.h"
#include <vector>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "PlayerItem.h"
#include "FruitItem.h"
#include "TigerItem.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playButton_clicked();
    void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;
    Game game;
    std::vector<Level> levels;
    int currentLevelIndex;
    QGraphicsScene* scene;
    PlayerItem* player;
    TigerItem* tiger;
    QList<FruitItem*> fruits;
    int currentLevel = 1;
    QGraphicsPixmapItem* bulma = nullptr;
    QList<QGraphicsPixmapItem*> balas;
    QTimer* balaTimer = nullptr;
    void setupLevels();
    void startLevel(int index);
    void showLevelInfo(int index);
    void setupLevel1();
    void setupLevel2();
    void setupLevel3();
    void keyPressEvent(QKeyEvent* event) override;
};

#endif // MAINWINDOW_H 