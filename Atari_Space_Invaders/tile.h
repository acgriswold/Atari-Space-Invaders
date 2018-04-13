#ifndef TILE_H
#define TILE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>

class Tile  : public QGraphicsItem
{
public:
    Tile(QGraphicsScene *scne, int startX, int startY);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int get_width();
    int get_height();

    void hit();

protected:
    void advance(int phase);

private:
    QBrush brush;
    QGraphicsScene *scene;

    int health;
};

#endif // TILE_H
