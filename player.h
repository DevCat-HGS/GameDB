#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QString>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player(QObject *parent = nullptr);
    
    // Métodos según el diagrama UML
    void move();
    void attack();
    void collectItem();
    
    // Propiedades según el diagrama UML
    QString getName() const { return name; }
    QPointF getPosition() const { return position; }
    QPointF getVelocity() const { return velocity; }
    int getHealth() const { return health; }
    
    // Setters
    void setVelocity(const QPointF &vel) { velocity = vel; }
    void setHealth(int h) { health = h; }
    
    // Manejo de eventos de teclado
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    
private:
    // Atributos según el diagrama UML
    QString name;
    QPointF position;
    QPointF velocity;
    int health;
    
    // Variables adicionales para el control del jugador
    bool isMovingLeft;
    bool isMovingRight;
    bool isJumping;
    bool isAttacking;
    
    // Sprites para diferentes estados
    QPixmap idleSprite;
    QPixmap runningSprite;
    QPixmap jumpingSprite;
    QPixmap attackingSprite;
};

#endif // PLAYER_H