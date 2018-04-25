#ifndef JELLY_H
#define JELLY_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>

class Jelly  : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Jelly(QGraphicsScene *scne);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void hit();

protected:
    void advance(int phase);

private:
    QBrush brush;
    QGraphicsScene *scene;

    int speed;
    int jelly_score;

signals:
    void enemy_hit_j(int);
};

#endif // JELLY_H
