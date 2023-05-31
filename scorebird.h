#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsWidget>

class ScoreBoard : public QGraphicsObject
{
public:
    ScoreBoard(QGraphicsItem *parent=0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};
#endif // SCOREBOARD_H
