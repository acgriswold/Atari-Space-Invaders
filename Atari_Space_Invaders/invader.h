#ifndef INVADER_H
#define INVADER_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QObject>

enum Typee{Dolphin, Star, Octo, Jelly};

class Invader : public QObject, public QGraphicsItem
{Q_OBJECT
public:
    Invader(QGraphicsScene *scne, int startX, int startY, Typee tye);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);



private slots:
    void advance(int phase);

signals:

    void enemy_hit(int);
private:
    QGraphicsScene *scene;
    QBrush brush;
    Invader *invader[5][11];
    Typee body;

    void hit();
};

#endif // INVADER_H
