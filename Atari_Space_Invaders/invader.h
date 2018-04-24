#ifndef INVADER_H
#define INVADER_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QObject>

#include "bullet_enemy.h"

enum Typee{Dolphin, Star, Octo, Jelly};

class Invader : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Invader(QGraphicsScene *scne, int startX, int startY, Typee tpe);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void fire();
    void move(int x, int y);

    void cycle_sprite(int spd);

private slots:
    void advance(int phase);

signals:
    void enemy_hit(int);

private:
    QGraphicsScene *scene;
    QBrush brush;
    Typee body;
    int sprite_index;

    void hit();
};

#endif // INVADER_H
