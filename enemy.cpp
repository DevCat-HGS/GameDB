#include "enemy.h"
#include <QDebug>
#include <QtMath>

Enemy::Enemy(QString enemyType, QObject *parent) : QObject(parent)
{
    // Inicializar atributos
    type = enemyType;
    position = QPointF(0, 0);
    velocity = QPointF(0, 0);
    movementPhase = 0;
    isAttacking = false;
    
    // Configurar comportamiento según el tipo
    if (type == "jabali") {
        behavior = "charge";
        idleSprite = QPixmap(":/images/enemies/enemy1_idle.svg");
        attackingSprite = QPixmap(":/images/enemies/enemy1_attacking.svg");
    } else if (type == "basic") {
        behavior = "patrol";
        idleSprite = QPixmap(":/images/enemies/enemy1_idle.svg");
        attackingSprite = QPixmap(":/images/enemies/enemy1_attacking.svg");
    } else if (type == "soldier") {
        behavior = "pursue";
        idleSprite = QPixmap(":/images/enemies/enemy2_idle.svg");
        attackingSprite = QPixmap(":/images/enemies/enemy2_attacking.svg");
    } else if (type == "boss") {
        behavior = "aggressive";
        idleSprite = QPixmap(":/images/enemies/enemy2_idle.svg");
        attackingSprite = QPixmap(":/images/enemies/enemy2_attacking.svg");
    }
    
    // Establecer sprite inicial
    setPixmap(idleSprite);
    
    // Configurar timer para movimiento
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::act()
{
    // Actualizar posición
    position = QPointF(x(), y());
    
    // Implementar comportamiento según el tipo
    if (behavior == "charge" && qrand() % 100 < 2) { // 2% de probabilidad
        attackPlayer();
    } else if (behavior == "pursue") {
        // Buscar al jugador y perseguirlo (simplificado)
        QList<QGraphicsItem*> items = scene()->items();
        for (QGraphicsItem* item : items) {
            if (dynamic_cast<class Player*>(item)) {
                // Mover hacia el jugador
                QPointF playerPos = item->pos();
                if (playerPos.x() < x()) {
                    velocity.setX(-2);
                    setTransform(QTransform().scale(-1, 1)); // Voltear sprite
                } else {
                    velocity.setX(2);
                    setTransform(QTransform()); // Restaurar sprite
                }
                
                // Atacar si está cerca
                if (qAbs(playerPos.x() - x()) < 50) {
                    attackPlayer();
                }
                break;
            }
        }
    } else if (behavior == "aggressive" && qrand() % 100 < 5) { // 5% de probabilidad
        attackPlayer();
    }
}

void Enemy::attackPlayer()
{
    if (!isAttacking) {
        isAttacking = true;
        setPixmap(attackingSprite);
        
        qDebug() << "Enemigo" << type << "está atacando!";
        
        // Restaurar estado después de un tiempo
        QTimer::singleShot(800, this, [this]() {
            isAttacking = false;
            setPixmap(idleSprite);
        });
    }
}

void Enemy::move()
{
    if (isAttacking) {
        return; // No moverse mientras ataca
    }
    
    // Implementar movimiento según el comportamiento
    if (behavior == "patrol") {
        // Movimiento oscilatorio horizontal
        movementPhase += 0.1;
        velocity.setX(3 * qSin(movementPhase));
        
        // Cambiar dirección del sprite
        if (velocity.x() < 0) {
            setTransform(QTransform().scale(-1, 1));
        } else {
            setTransform(QTransform());
        }
    } else if (behavior == "charge") {
        // Movimiento de carga ocasional
        if (qrand() % 100 < 1) { // 1% de probabilidad
            velocity.setX(velocity.x() == 0 ? -8 : 0); // Alternar entre quieto y carga
            
            if (velocity.x() < 0) {
                setTransform(QTransform().scale(-1, 1));
            }
        }
    }
    
    // Aplicar movimiento
    setPos(x() + velocity.x(), y() + velocity.y());
    
    // Limitar movimiento dentro de los límites de la escena
    if (scene()) {
        if (x() < 0) {
            setPos(0, y());
            velocity.setX(-velocity.x()); // Rebotar
            setTransform(QTransform()); // Restaurar sprite
        } else if (x() > scene()->width() - pixmap().width()) {
            setPos(scene()->width() - pixmap().width(), y());
            velocity.setX(-velocity.x()); // Rebotar
            setTransform(QTransform().scale(-1, 1)); // Voltear sprite
        }
        
        // Aplicar gravedad si está en el aire
        if (y() < scene()->height() - pixmap().height()) {
            velocity.setY(velocity.y() + 0.5); // Gravedad
        } else {
            setPos(x(), scene()->height() - pixmap().height());
            velocity.setY(0);
        }
    }
}