#ifndef SQUAD_H
#define SQUAD_H

#include "invader.h"
#include <QObject>

class Squad : public QObject
{
    Q_OBJECT
public:
    Squad(QGraphicsScene *scne, int lvl);

    void moveSquad();
    void fireSquad();

signals:
   void add_score(int);

private slots:
   void enemy_value(int);

private:
     QGraphicsScene *scene;
     int speed;
     int startX;
     int startY;

     Invader *(invader[5][11]);
};

#endif // SQUAD_H
