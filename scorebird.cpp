#include "scorebird.h"

#include <QPainter>


ScoreBoard::ScoreBoard(QGraphicsItem *parent)
{
}

QRectF ScoreBoard::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2,
                  800 + penWidth/2, 600 + penWidth/2);
}

void ScoreBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPixmap pixmap;
    pixmap.load(":/resource/images/game_is_over.png");
//    painter->drawPixmap(0,0,345,177,pixmap,0,4,345,177);
    painter->drawPixmap(0, 0, pixmap);
}
