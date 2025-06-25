#ifndef FRUITITEM_H
#define FRUITITEM_H
#include <QGraphicsPixmapItem>

class FruitItem : public QGraphicsPixmapItem {
public:
    FruitItem(qreal x, qreal y) {
        setPixmap(QPixmap(":/Img/Elementos/Fruta.png"));
        setPos(x, y);
    }
};

#endif // FRUITITEM_H 