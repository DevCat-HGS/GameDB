#include "player.h"
#include <QDebug>

Player::Player(QObject *parent) : QObject(parent)
{
    // Inicializar atributos
    name = "Goku";
    position = QPointF(0, 0);
    velocity = QPointF(0, 0);
    health = 100;
    
    // Inicializar estados
    isMovingLeft = false;
    isMovingRight = false;
    isJumping = false;
    isAttacking = false;
    
    // Cargar sprites
    idleSprite = QPixmap(":/images/characters/goku_idle.png");
    runningSprite = QPixmap(":/images/characters/goku_running.png");
    jumpingSprite = QPixmap(":/images/characters/goku_jumping.png");
    attackingSprite = QPixmap(":/images/characters/goku_attacking.png");
    
    // Establecer sprite inicial
    setPixmap(idleSprite);
}

void Player::move()
{
    // Actualizar posición basada en velocidad
    setPos(x() + velocity.x(), y() + velocity.y());
    position = QPointF(x(), y());
    
    // Cambiar sprite según el estado
    if (isAttacking) {
        setPixmap(attackingSprite);
    } else if (isJumping) {
        setPixmap(jumpingSprite);
    } else if (isMovingLeft || isMovingRight) {
        setPixmap(runningSprite);
        
        // Voltear sprite según dirección
        if (isMovingLeft) {
            setTransform(QTransform().scale(-1, 1));
        } else {
            setTransform(QTransform());
        }
    } else {
        setPixmap(idleSprite);
    }
    
    // Limitar movimiento dentro de los límites de la escena
    if (scene()) {
        if (x() < 0) {
            setPos(0, y());
        } else if (x() > scene()->width() - pixmap().width()) {
            setPos(scene()->width() - pixmap().width(), y());
        }
        
        // Aplicar gravedad si está en el aire
        if (y() < scene()->height() - pixmap().height()) {
            velocity.setY(velocity.y() + 0.5); // Gravedad
        } else {
            setPos(x(), scene()->height() - pixmap().height());
            velocity.setY(0);
            isJumping = false;
        }
    }
}

void Player::attack()
{
    isAttacking = true;
    
    // Implementar lógica de ataque
    qDebug() << name << "está atacando!";
    
    // Restaurar estado después de un tiempo (podría usar QTimer)
    QTimer::singleShot(500, this, [this]() {
        isAttacking = false;
    });
}

void Player::collectItem()
{
    // Implementar lógica para recolectar objetos
    qDebug() << name << "ha recogido un objeto!";
}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        isMovingLeft = true;
        velocity.setX(-5);
        break;
    case Qt::Key_Right:
        isMovingRight = true;
        velocity.setX(5);
        break;
    case Qt::Key_Up:
    case Qt::Key_Space:
        if (!isJumping) {
            isJumping = true;
            velocity.setY(-15); // Impulso hacia arriba
        }
        break;
    case Qt::Key_Z:
        attack();
        break;
    case Qt::Key_X:
        collectItem();
        break;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        isMovingLeft = false;
        if (!isMovingRight) {
            velocity.setX(0);
        }
        break;
    case Qt::Key_Right:
        isMovingRight = false;
        if (!isMovingLeft) {
            velocity.setX(0);
        }
        break;
    }
}