#ifndef SQUAD_H
#define SQUAD_H

#include "invader.h"

class Squad
{
public:
    Squad(QGraphicsScene *scne, int lvl);

    void moveSquad();
    void fireSquad();

private:
     QGraphicsScene *scene;
     int speed;
     int startX;
     int startY;

     Invader *(invader[5][11]);
};

#endif // SQUAD_H
