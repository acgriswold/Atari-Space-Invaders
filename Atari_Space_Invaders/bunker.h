#ifndef BUNKER_H
#define BUNKER_H

#include "tile.h"

class Bunker
{
public:
    Bunker(QGraphicsScene *scne, int startX, int startY);

    QGraphicsItem* get_tile(int i);

private:
     QGraphicsScene *scene;

     Tile *(tile[10]);
};

#endif // BUNKER_H
