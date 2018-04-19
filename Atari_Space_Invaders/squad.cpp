#include "squad.h"

Squad::Squad(QGraphicsScene *scne, int lvl)
{
    scene = scne;
    speed = 50;
    //set the position based on the level
    int levelPos = lvl * 10;

    //set the position
    startX = -600;
    startY = -250;

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
            startX = startX + 40;
        }
        startY = startY + 40;
        startX = -600;
    }
}

void Squad::moveSquad(){
    int currentX = startX;
        int currentY = startY;
        int maxX = -650;
        int minX = 650;
        for(int rows = 0; rows <= 4; rows++)
        {
            for(int cols = 0; cols <= 10; cols++)
            {
                //set the postition for the next x move
                currentX = currentX + 40;
                if(scene->items().indexOf(invader[rows][cols]) >= 0)
                {
                    //move the invader
                    invader[rows][cols]->move(currentX,currentY);
                    //check if the squad is at all the way to either side of the scene
                    if(invader[rows][cols]->x() + invader[rows][cols]->boundingRect().width() > maxX)
                    {
                        maxX = invader[rows][cols]->x() + invader[rows][cols]->boundingRect().width();
                    }
                    else if(invader[rows][cols]->x() < minX)
                    {
                        minX = invader[rows][cols]->x();
                    }
                }
            }
            //set the position for the next y move
            currentY = currentY + 40;
            currentX = startX;
        }
        //change the direction if the squad is at one of the sides
        if((maxX + speed >= 650) || (minX + speed <= -650))
        {
            startY = startY + 40;
            speed = speed * -1;
        }
        else
        {
            startX = startX + speed;
        }
}

void Squad::fireSquad(){
    int cols = rand()%11;
    int lowest_row = -1;
    for(int rows = 0; rows <= 4; rows++)
    {
        if(scene->items().indexOf(invader[rows][cols]) >= 0){
            lowest_row = rows;
        }
    }
    if(scene->items().indexOf(invader[lowest_row][cols]) >= 0){
        invader[lowest_row][cols]->fire();
    }
}
