#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class bullet : public QGraphicsItem
{
public:
    bullet(int x, int y);
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

#endif // BULLET_H
