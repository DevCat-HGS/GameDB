#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QPixmap>
#include <QKeyEvent>

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

PlayerItem::PlayerItem() : velocityY(0), jumping(false), onGround(true) {
    standPixmap = QPixmap(":/Img/Goku/Goku.png");
    jumpPixmap = QPixmap(":/Img/Goku/Goku_Saltar.png");
    attackPixmap = QPixmap(":/Img/Goku/Goku_Ataca.png");
    setPixmap(standPixmap);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void PlayerItem::moveLeft() { setX(x() - 10); }
void PlayerItem::moveRight() { setX(x() + 10); }
void PlayerItem::jump() {
    if (onGround) {
        velocityY = -18;
        jumping = true;
        onGround = false;
        setPixmap(jumpPixmap);
    }
}
void PlayerItem::attack() { setPixmap(attackPixmap); }
void PlayerItem::applyGravity() {
    if (!onGround) {
        velocityY += 1.2; // gravity
        setY(y() + velocityY);
        if (y() >= 350) { // ground level
            setY(350);
            velocityY = 0;
            onGround = true;
            setPixmap(standPixmap);
        }
    }
}
void PlayerItem::setOnGround(bool g) { onGround = g; }
void PlayerItem::advance(int phase) {
    if (!phase) return;
    applyGravity();
}
