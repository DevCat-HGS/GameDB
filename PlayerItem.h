#ifndef PLAYERITEM_H
#define PLAYERITEM_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class PlayerItem : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    PlayerItem();
    void moveLeft();
    void moveRight();
    void jump();
    void attack();
    void applyGravity();
    void setOnGround(bool onGround);

protected:
    void advance(int phase) override;

private:
    QPixmap standPixmap, jumpPixmap, attackPixmap;
    qreal velocityY;
    bool jumping, onGround;
    QTimer* animationTimer;
};

#endif // PLAYERITEM_H