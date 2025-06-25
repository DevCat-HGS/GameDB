#include "TigerItem.h"
#include <QPixmap>
#include <QTimer>
#include <QtMath>

TigerItem::TigerItem() : direction(1), amplitude(40) {
    normalPixmap = QPixmap(":/Img/Enemigos/Tigre.png");
    attackPixmap = QPixmap(":/Img/Enemigos/Tigre_Ataca.png");
    setPixmap(normalPixmap);
    baseX = x();
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &TigerItem::moveOscillate);
    moveTimer->start(50);
}

void TigerItem::moveOscillate() {
    static qreal t = 0;
    t += 0.1;
    setX(baseX + amplitude * qSin(t));
}
