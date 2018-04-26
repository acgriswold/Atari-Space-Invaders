#ifndef JELLY_H
#define JELLY_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>

enum Dir{lft, rght};

class Jelly  : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Jelly(QGraphicsScene *scne);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void hit();

    void cycle_sprite();
protected:
    void advance(int phase);

private:
    QBrush brush;
    QGraphicsScene *scene;

    int speed;
    int jelly_score;
    int counter;

    Dir dir;

signals:
    void enemy_hit_j(int);
};

#endif // JELLY_H
