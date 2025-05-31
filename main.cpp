#include <QApplication>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include "game.h"

class GameView : public QGraphicsView {
public:
    GameView(QWidget* parent = nullptr) : QGraphicsView(parent) {
        // Configurar la escena
        scene = new QGraphicsScene(this);
        setScene(scene);
        
        // Configurar la vista
        setRenderHint(QPainter::Antialiasing);
        setBackgroundBrush(QBrush(Qt::black));
        setFrameShape(QFrame::NoFrame);
        
        // Inicializar el juego
        game = new Game();
        game->startGame();
        
        // Configurar el temporizador para actualizar el juego
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &GameView::updateGame);
        timer->start(16); // Aproximadamente 60 FPS
    }
    
    ~GameView() {
        delete game;
    }
    
private:
    QGraphicsScene* scene;
    Game* game;
    QTimer* timer;
    
    void updateGame() {
        // Actualizar el estado del juego
        game->update();
        
        // Actualizar la escena (en una implementación real, se renderizarían los elementos del juego)
        scene->update();
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // Crear la ventana principal
    QMainWindow window;
    window.setWindowTitle("Dragon Ball: Secret of the Dragon Ball");
    
    // Crear la vista del juego
    GameView* gameView = new GameView(&window);
    window.setCentralWidget(gameView);
    
    // Configurar el tamaño de la ventana
    window.resize(800, 600);
    
    // Mostrar la ventana
    window.show();
    
    return app.exec();
}