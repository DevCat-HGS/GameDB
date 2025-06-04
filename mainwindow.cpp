#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
    if (game) {
        delete game;
    }
}

void MainWindow::on_startButton_clicked()
{
    // Ocultar la ventana principal
    this->hide();
    
    // Crear e iniciar el juego
    if (game) {
        delete game;
    }
    
    game = new Game(this);
    game->startGame();
}