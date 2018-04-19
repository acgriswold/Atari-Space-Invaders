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
    Typee tye;
    for(int rows = 0; rows <= 4; rows++)
    {
        if(rows==0){tye = Dolphin;}
        else if(rows==1||rows==2){tye = Star;}
        else if(rows == 3 ||rows ==4){tye = Octo;}
        for(int cols = 0; cols <= 10; cols++)
        {
            Invader *item = new Invader(scene, startX, startY, tye);
            invader[rows][cols] = item;
            scene->addItem(invader[rows][cols]);
            startX = startX + 50;
            connect(invader[rows][cols], SIGNAL(enemy_hit(int)),this,SLOT(enemy_value(int)));

        }
        startY = startY + 50;
        startX = -600;
    }
}

void Squad::enemy_value(int b)
{
    emit add_score(b);
}

/*Squad::moveSquad(QGraphicsScene * scne)
{
    scene = scne;

}*/
