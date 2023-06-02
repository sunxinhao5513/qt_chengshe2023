#include "gameover.h"
#include <QPainter>

GameOver::GameOver(QGraphicsItem *parent)
{
}

QRectF GameOver::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  800 + penWidth/2, 600 + penWidth/2);
}

void GameOver::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap;
    pixmap.load(":/resource/images/game_is_over.png");
//    painter->drawPixmap(0,0,300,90,pixmap,0,80,300,90);
    painter->drawPixmap(0, 0, pixmap);
}
