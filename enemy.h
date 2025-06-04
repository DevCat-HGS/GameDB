#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QString>
#include <QPointF>
#include <QTimer>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Enemy(QString enemyType, QObject *parent = nullptr);
    
    // Métodos según el diagrama UML
    void act();
    void attackPlayer();
    
    // Getters
    QString getType() const { return type; }
    QPointF getPosition() const { return position; }
    QString getBehavior() const { return behavior; }
    
    // Setters
    void setPosition(const QPointF &pos) { position = pos; }
    
public slots:
    void move();
    
private:
    // Atributos según el diagrama UML
    QString type;
    QPointF position;
    QString behavior;
    
    // Variables adicionales
    QTimer *timer;
    QPixmap idleSprite;
    QPixmap attackingSprite;
    
    // Movimiento
    QPointF velocity;
    float movementPhase; // Para movimiento oscilatorio
    bool isAttacking;
};

#endif // ENEMY_H