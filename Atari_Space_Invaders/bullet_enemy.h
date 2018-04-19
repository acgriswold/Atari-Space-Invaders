#ifndef BULLET_ENEMY_H
#define BULLET_ENEMY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class bullet_enemy : public QGraphicsItem
{
public:
    bullet_enemy(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

private:
    qreal speed;
    int acceleration;
    QBrush brush;
    QTimer *advnce;

};

#endif // BULLET_ENEMY_H
