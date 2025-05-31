#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    gamePaused(false)
{
    ui->setupUi(this);
    
    // Inicializar la escena y el juego
    scene = new QGraphicsScene(this);
    game = new Game();
    
    // Configurar la vista del juego
    setupGameView();
    
    // Configurar el temporizador para actualizar el juego
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &MainWindow::updateGame);
    gameTimer->start(16); // Aproximadamente 60 FPS
    
    // Conectar señales adicionales
    connectSignals();
    
    // Actualizar la interfaz de usuario
    updateUI();
    
    // Deshabilitar el botón de pausa al inicio
    ui->pauseButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}

void MainWindow::setupGameView()
{
    // Crear una vista de gráficos y añadirla al layout del frame de juego
    QGraphicsView *gameView = new QGraphicsView(scene, ui->gameFrame);
    gameView->setRenderHint(QPainter::Antialiasing);
    gameView->setBackgroundBrush(QBrush(Qt::black));
    gameView->setFrameShape(QFrame::NoFrame);
    gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    // Añadir la vista al layout
    ui->gameLayout->addWidget(gameView);
    
    // Ajustar el tamaño de la escena
    scene->setSceneRect(0, 0, 780, 480);
}

void MainWindow::connectSignals()
{
    // Conectar señales adicionales si es necesario
}

void MainWindow::updateGame()
{
    if (!gamePaused) {
        // Actualizar el estado del juego
        game->update();
        
        // Actualizar la escena (en una implementación real, se renderizarían los elementos del juego)
        scene->update();
        
        // Actualizar la interfaz de usuario
        updateUI();
    }
}

void MainWindow::updateUI()
{
    // Actualizar información del nivel
    ui->levelLabel->setText(QString("Nivel: %1").arg(game->getCurrentLevel() + 1));
    
    // Actualizar información de salud
    int health = game->getPlayer().getHealth();
    ui->healthLabel->setText(QString("Salud: %1").arg(health));
    ui->healthBar->setValue(health);
    
    // Cambiar el color de la barra de salud según el nivel de salud
    QString healthStyle;
    if (health > 70) {
        healthStyle = "QProgressBar::chunk { background-color: #2ecc71; }"; // Verde
    } else if (health > 30) {
        healthStyle = "QProgressBar::chunk { background-color: #f39c12; }"; // Naranja
    } else {
        healthStyle = "QProgressBar::chunk { background-color: #e74c3c; }"; // Rojo
    }
    ui->healthBar->setStyleSheet(ui->healthBar->styleSheet() + healthStyle);
}

void MainWindow::on_startButton_clicked()
{
    game->startGame();
    ui->startButton->setEnabled(false);
    ui->pauseButton->setEnabled(true);
    ui->resetButton->setEnabled(true);
    gamePaused = false;
}

void MainWindow::on_pauseButton_clicked()
{
    gamePaused = !gamePaused;
    if (gamePaused) {
        ui->pauseButton->setText("Reanudar");
    } else {
        ui->pauseButton->setText("Pausar");
    }
}

void MainWindow::on_resetButton_clicked()
{
    game->startGame(); // Reiniciar el juego
    ui->startButton->setEnabled(false);
    ui->pauseButton->setEnabled(true);
    ui->pauseButton->setText("Pausar");
    gamePaused = false;
}

void MainWindow::on_actionNuevo_Juego_triggered()
{
    on_resetButton_clicked();
}

void MainWindow::on_actionPausar_triggered()
{
    on_pauseButton_clicked();
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_actionControles_triggered()
{
    QMessageBox::information(this, "Controles",
                             "Controles del juego:\n\n"
                             "- Flechas: Mover al personaje\n"
                             "- Espacio: Atacar\n"
                             "- Z: Recoger objetos\n"
                             "- ESC: Pausar el juego");
}

void MainWindow::on_actionAcerca_de_triggered()
{
    QMessageBox::about(this, "Acerca de Dragon Ball: Secret of the Dragon Ball",
                       "Dragon Ball: Secret of the Dragon Ball\n\n"
                       "Un videojuego basado en el primer capítulo de Dragon Ball, "
                       "desarrollado con Qt Creator y C++.\n\n"
                       "© 2023 GameDB");
}