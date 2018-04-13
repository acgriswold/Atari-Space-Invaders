#ifndef INVADER_H
#define INVADER_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>


class Invader : public QGraphicsItem
{
public:
    Invader(QGraphicsScene *scne, int startX, int startY);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QGraphicsScene *scene;
    QBrush brush;
    Invader *invader[5][11];
};

#endif // INVADER_H
