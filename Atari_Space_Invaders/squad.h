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
   void level_complete();

private slots:
   void enemy_value(int);

private:
     QGraphicsScene *scene;
     int speed;
     int startX;
     int startY;

     int fire_rate;

     Invader *(invader[5][11]);

     int invader_count;
};

#endif // SQUAD_H
