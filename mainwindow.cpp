#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Level.h"
#include <vector>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::on_playButton_clicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::on_exitButton_clicked);
    ui->gameView->hide(); // Oculta el juego al inicio
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showLevelInfo(int index) {
    if (index >= 0 && static_cast<size_t>(index) < levels.size()) {
        QMessageBox::information(this, QString("Nivel %1").arg(levels[index].levelNumber), QString::fromStdString(levels[index].description));
    }
}

void MainWindow::startLevel(int index) {
    if (index >= 0 && static_cast<size_t>(index) < levels.size()) {
        currentLevelIndex = index;
        showLevelInfo(index);
        // Aquí podrías agregar lógica para simular el reto o marcar el nivel como completado
        if (QMessageBox::question(this, "¿Completaste el nivel?", "¿Deseas avanzar al siguiente nivel?") == QMessageBox::Yes) {
            if (index + 1 < static_cast<int>(levels.size())) {
                startLevel(index + 1);
            } else {
                QMessageBox::information(this, "¡Felicidades!", "¡Has completado todos los niveles!");
            }
        }
    }
}

void MainWindow::on_playButton_clicked()
{
    ui->playButton->hide();
    ui->exitButton->hide();
    ui->gameView->show();
    setupLevel1();
}

void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::setupLevel1() {
    currentLevel = 1;
    scene = new QGraphicsScene(this);
    ui->gameView->setScene(scene);
    scene->setSceneRect(0, 0, 800, 480);
    scene->setBackgroundBrush(Qt::gray);

    // Fondo
    QPixmap fondoPixmap(":/Img/Mapas/1/Fondo.jpg");
    QGraphicsPixmapItem* fondo = scene->addPixmap(fondoPixmap);
    fondo->setZValue(-2);

    // Piso
    QPixmap pisoPixmap(":/Img/Mapas/1/Piso.jpg");
    QGraphicsPixmapItem* piso = scene->addPixmap(pisoPixmap);
    piso->setPos(0, 400);
    piso->setZValue(-1);

    // Goku
    player = new PlayerItem();
    player->setPos(100, 350);
    scene->addItem(player);

    // Fruta
    fruits.clear();
    FruitItem* fruta = new FruitItem(600, 350);
    fruits.append(fruta);
    scene->addItem(fruta);

    // Tigre
    tiger = new TigerItem();
    tiger->setPos(750, 350);
    scene->addItem(tiger);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(20);

    // Timer para ataque del tigre
    QTimer* tigerAttackTimer = new QTimer(this);
    connect(tigerAttackTimer, &QTimer::timeout, this, [this]() {
        if (!player || !tiger) return;
        if (tiger->x() > player->x()) tiger->setX(tiger->x() - 2);
        else if (tiger->x() < player->x()) tiger->setX(tiger->x() + 2);
        if (player->collidesWithItem(tiger)) {
            QMessageBox::warning(this, "¡Perdiste!", "El tigre te atrapó");
            qApp->exit();
        }
    });
    tigerAttackTimer->start(40);
}

void MainWindow::setupLevel2() {
    qDebug() << "Entrando a setupLevel2()";
    currentLevel = 2;
    if (scene) { qDebug() << "Eliminando escena anterior"; delete scene; scene = nullptr; }
    player = nullptr;
    tiger = nullptr;
    bulma = nullptr;
    fruits.clear();
    scene = new QGraphicsScene(this);
    ui->gameView->setScene(scene);
    scene->setSceneRect(0, 0, 800, 480);
    scene->setBackgroundBrush(Qt::gray);
    QPixmap fondoPixmap(":/Img/Mapas/1/Fondo.jpg");
    QGraphicsPixmapItem* fondo = scene->addPixmap(fondoPixmap);
    fondo->setZValue(-2);
    QPixmap pisoPixmap(":/Img/Mapas/1/Piso.jpg");
    QGraphicsPixmapItem* piso = scene->addPixmap(pisoPixmap);
    piso->setPos(0, 400);
    piso->setZValue(-1);
    player = new PlayerItem();
    player->setPos(100, 350);
    scene->addItem(player);
    FruitItem* fruta = new FruitItem(600, 350);
    fruits.append(fruta);
    scene->addItem(fruta);
    bulma = new QGraphicsPixmapItem(QPixmap(":/Img/Bulma/Bulma_Salvar.png"));
    bulma->setPos(600, 290);
    scene->addItem(bulma);
    // Timer para detectar colisión con fruta y Bulma
    QTimer* frutaBulmaTimer = new QTimer(this);
    connect(frutaBulmaTimer, &QTimer::timeout, this, [this, fruta, frutaBulmaTimer]() {
        if (player && fruta && player->collidesWithItem(fruta)) {
            QMessageBox::information(this, "¡Nivel completado!", "¡Has rescatado a Bulma!");
            frutaBulmaTimer->stop();
        }
    });
    //frutaBulmaTimer->start(30);
    qDebug() << "setupLevel2() completado";
}

void MainWindow::setupLevel3() {
    qDebug() << "Entrando a setupLevel3()";
    currentLevel = 3;
    if (scene) { delete scene; scene = nullptr; }
    player = nullptr;
    bulma = nullptr;
    tiger = nullptr;
    fruits.clear();
    for (auto b : balas) delete b;
    balas.clear();
    if (balaTimer) { balaTimer->stop(); delete balaTimer; balaTimer = nullptr; }

    scene = new QGraphicsScene(this);
    ui->gameView->setScene(scene);
    scene->setSceneRect(0, 0, 800, 480);
    scene->setBackgroundBrush(Qt::gray);
    QPixmap fondoPixmap(":/Img/Mapas/1/Fondo.jpg");
    QGraphicsPixmapItem* fondo = scene->addPixmap(fondoPixmap);
    fondo->setZValue(-2);
    QPixmap pisoPixmap(":/Img/Mapas/1/Piso.jpg");
    QGraphicsPixmapItem* piso = scene->addPixmap(pisoPixmap);
    piso->setPos(0, 400);
    piso->setZValue(-1);
    // Player
    player = new PlayerItem();
    player->setPos(100, 350);
    scene->addItem(player);
    // Fruta
    FruitItem* fruta = new FruitItem(700, 350);
    fruits.append(fruta);
    scene->addItem(fruta);
    // Timer para físicas
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(20);
    // Timer para balas
    balaTimer = new QTimer(this);
    connect(balaTimer, &QTimer::timeout, this, [this]() {
        static int phase = 0;
        QPixmap balaPixmap(":/Img/Elementos/Bala.png");
        QGraphicsPixmapItem* bala = new QGraphicsPixmapItem(balaPixmap);
        bala->setZValue(1);
        if (phase < 3) {
            // De arriba a abajo
            int x = 100 + rand() % 600;
            bala->setPos(x, 0);
            scene->addItem(bala);
            balas.append(bala);
            QTimer* moveTimer = new QTimer(this);
            connect(moveTimer, &QTimer::timeout, this, [this, bala, moveTimer]() {
                bala->setY(bala->y() + 10);
                if (bala->y() > 480) { scene->removeItem(bala); balas.removeOne(bala); delete bala; moveTimer->stop(); moveTimer->deleteLater(); }
                else if (player && bala->collidesWithItem(player)) {
                    QMessageBox::warning(this, "¡Perdiste!", "Te golpeó una bala");
                    qApp->exit();
                }
            });
            moveTimer->start(30);
        } else if (phase < 6) {
            // De derecha a izquierda
            int y = 50 + rand() % 350;
            bala->setPos(800, y);
            scene->addItem(bala);
            balas.append(bala);
            QTimer* moveTimer = new QTimer(this);
            connect(moveTimer, &QTimer::timeout, this, [this, bala, moveTimer]() {
                bala->setX(bala->x() - 10);
                if (bala->x() < 0) { scene->removeItem(bala); balas.removeOne(bala); delete bala; moveTimer->stop(); moveTimer->deleteLater(); }
                else if (player && bala->collidesWithItem(player)) {
                    QMessageBox::warning(this, "¡Perdiste!", "Te golpeó una bala");
                    qApp->exit();
                }
            });
            moveTimer->start(30);
        }
        phase++;
        if (phase >= 6) { balaTimer->stop(); }
    });
    balaTimer->start(1000); // Cada segundo una bala

    // --- NUEVO: Espera antes de activar la colisión con la fruta ---
    bool* frutaColisionActiva = new bool(false); // Usar puntero para lambda
    QTimer::singleShot(1000, this, [frutaColisionActiva]() { *frutaColisionActiva = true; });

    QTimer* frutaTimer = new QTimer(this);
    connect(frutaTimer, &QTimer::timeout, this, [this, fruta, frutaTimer, frutaColisionActiva]() {
        if (*frutaColisionActiva && player && fruta && player->collidesWithItem(fruta)) {
            QMessageBox::information(this, "¡Ganaste!", "¡Has esquivado las balas y recogido la fruta!\n¡Juego terminado!");
            frutaTimer->stop();
            delete frutaColisionActiva;
            qApp->exit();
        }
    });
    frutaTimer->start(30);
    qDebug() << "[LOG] Player en (" << player->x() << "," << player->y() << ")";
    qDebug() << "[LOG] Fruta en (" << fruta->x() << "," << fruta->y() << ")";
    qDebug() << "setupLevel3() completado";
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    qDebug() << "keyPressEvent: currentLevel=" << currentLevel;
    if (!player) { qDebug() << "player es nullptr"; return; }
    switch (event->key()) {
        case Qt::Key_A: player->moveLeft(); qDebug() << "Goku mueve izquierda"; break;
        case Qt::Key_D: player->moveRight(); qDebug() << "Goku mueve derecha"; break;
        case Qt::Key_W: player->jump(); qDebug() << "Goku salta"; break;
        case Qt::Key_X: player->attack(); qDebug() << "Goku ataca"; break;
    }
    for (auto f : fruits) {
        qDebug() << "[LOG] Revisando colisión con fruta en nivel" << currentLevel << ", player en (" << player->x() << "," << player->y() << ") fruta en (" << f->x() << "," << f->y() << ")";
        if (player->collidesWithItem(f)) {
            qDebug() << "[LOG] Colisión detectada con fruta en nivel" << currentLevel;
            scene->removeItem(f);
            fruits.removeOne(f);
            delete f;
            if (currentLevel == 1) {
                qDebug() << "[LOG] Transición a nivel 2";
                QTimer::singleShot(0, this, [this]() { setupLevel2(); });
                return;
            } else if (currentLevel == 2) {
                if (bulma) {
                    bulma->setPixmap(QPixmap(":/Img/Bulma/Bulma.png"));
                    qDebug() << "[LOG] Bulma liberada";
                }
                QMessageBox::information(this, "¡Salvaste a Bulma!", "¡Bulma es libre!");
                qDebug() << "[LOG] Fin del juego tras liberar a Bulma";
                fruits.clear();
                QTimer::singleShot(0, this, [this]() { setupLevel3(); });
                return;
            } else if (currentLevel == 3) {
                qDebug() << "[LOG] ¡Ganaste! Fruta recogida en nivel 3";
                QMessageBox::information(this, "¡Ganaste!", "¡Has esquivado las balas y recogido la fruta!\n¡Juego terminado!");
                fruits.clear();
                qApp->exit();
                return;
            }
            break;
        }
    }
} 