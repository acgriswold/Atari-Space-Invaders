#include "squad.h"

Squad::Squad(QGraphicsScene *scne, int lvl)
{
    scene = scne;
    speed = 50;
    fire_rate = 10;
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

    Typee tpe;

    int currentX = startX;
    int currentY = startY;
    //display the invaders
    for(int rows = 0; rows <= 4; rows++)
    {
        if(rows==0){tpe = Dolphin;}
        else if(rows==1||rows==2){tpe = Star;}
        else if(rows == 3 ||rows ==4){tpe = Octo;}

        for(int cols = 0; cols <= 10; cols++)
        {
            Invader *item = new Invader(scene, currentX, currentY, tpe);
            invader[rows][cols] = item;
            scene->addItem(invader[rows][cols]);
            currentX = currentX + 40;
            connect(invader[rows][cols], SIGNAL(enemy_hit(int)),this,SLOT(enemy_value(int)));
        }
        currentY = currentY + 40;
        currentX = startX;
    }

    invader_count = 55;
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
                if(invader[rows][cols]->x() + invader[rows][cols]->boundingRect().width() > maxX){maxX = invader[rows][cols]->x() + invader[rows][cols]->boundingRect().width();}

                if(invader[rows][cols]->x() < minX){minX = invader[rows][cols]->x();}

                invader[rows][cols]->cycle_sprite(speed);
            }
        }
        //set the position for the next y move
        currentY = currentY + 40;
        currentX = startX;
    }
    //change the direction if the squad is at one of the sides
    if((maxX + speed >= 650) || (minX + speed <= -650)){
        startY = startY + 40;
        speed = speed * -1;
    }
    else{
        startX = startX + speed;
    }
}

void Squad::fireSquad(){
    if(rand()%100 <= fire_rate){
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
}

void Squad::enemy_value(int b){
    emit add_score(b);
    invader_count--;
    if(invader_count <= 0){
        emit level_complete();

        if(fire_rate <= 75)fire_rate+=5;
    }
}

