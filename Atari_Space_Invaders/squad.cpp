#include "squad.h"

Squad::Squad(QGraphicsScene *scne, int lvl)
{
    scene = scne;
    //set the position based on the level
    int levelPos = lvl * 10;

    //set the position
    int startX = -600, startY = -250;

    //check to make sure the invaders do not go past the bunkers
    if(lvl <= 10)
    {
        startY = startY + levelPos;
    }

    //display the invaders
    for(int rows = 0; rows <= 4; rows++)
    {
        for(int cols = 0; cols <= 10; cols++)
        {
            Invader *item = new Invader(scene, startX, startY);
            invader[rows][cols] = item;
            scene->addItem(invader[rows][cols]);
            startX = startX + 50;
        }
        startY = startY + 50;
        startX = -600;
    }
}

void Squad::moveSquad(){


}
