#ifndef TIGERITEM_H
#define TIGERITEM_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class TigerItem : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    TigerItem();
    void moveOscillate();
private:
    QPixmap normalPixmap, attackPixmap;
    QTimer* moveTimer;
    int direction;
    qreal amplitude, baseX;
};

#endif // TIGERITEM_H 