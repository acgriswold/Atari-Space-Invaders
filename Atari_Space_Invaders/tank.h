#ifndef TANK_H
#define TANK_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>

#include "bullet.h"

enum Move{Left, Right, Fire};

class Tank : public QGraphicsItem
{
public:
    Tank(QGraphicsScene *scne);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void movement();

    void set_move(Move mve);
    void disable_move(Move mve);

protected:
    void advance(int phase);

private:
    QGraphicsScene *scene;
    qreal speed;
    int acceleration;
    QBrush brush;
    bool left;
    bool fire;
    bool right;
};

#endif // TANK_H
