#ifndef INVADER_H
#define INVADER_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>

#include "bullet_enemy.h"

class Invader : public QGraphicsItem
{
public:
    Invader(QGraphicsScene *scne, int startX, int startY);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void fire();
    void move(int x, int y);

private slots:
    void advance(int phase);

private:
    QGraphicsScene *scene;
    QBrush brush;

    void hit();
};

#endif // INVADER_H
