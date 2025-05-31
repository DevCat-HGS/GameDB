#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void on_resetButton_clicked();
    void on_actionNuevo_Juego_triggered();
    void on_actionPausar_triggered();
    void on_actionSalir_triggered();
    void on_actionControles_triggered();
    void on_actionAcerca_de_triggered();
    
    void updateGame();
    void updateUI();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Game *game;
    QTimer *gameTimer;
    bool gamePaused;
    
    void setupGameView();
    void connectSignals();
};

#endif // MAINWINDOW_H