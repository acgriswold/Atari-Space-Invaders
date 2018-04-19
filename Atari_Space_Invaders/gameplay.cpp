#include "gameplay.h"

Gameplay::Gameplay(QGraphicsScene *scne){
    scene = scne;

    lives = 3;
    level = 0;
    score = 0;
}

Gameplay::~Gameplay(){
    delete tank;
    delete bunker;
}

void Gameplay::renderGame(){
    renderBorder();
    renderTank();
    renderBunker();
    renderSquad(level);
}

void Gameplay::renderBorder(){
    QPen mypen = QPen(Qt::gray);

    QLineF TopLine(scene->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomRight(), scene->sceneRect().bottomLeft());

    scene->addLine(TopLine,mypen);
    scene->addLine(LeftLine,mypen);
    scene->addLine(RightLine,mypen);
    scene->addLine(BottomLine,mypen);
}

void Gameplay::renderTank(){
    Tank *item = new Tank(scene);
    tank = item;
    scene->addItem(tank);
}

void Gameplay::renderBunker(){
    int startX = -505, startY = 75, cnt = 4;
    int adder = 290;
    for(int i = 0; i < cnt; i++){
        bunker = new Bunker(scene, startX, startY);
        startX += adder;
        //spacing correction
        if(i%2 == 0){adder += 15;}
        else if(i%2 == 1){adder = 285;}
    }
}

void Gameplay::renderSquad(int lvl){
    squad = new Squad(scene, lvl);
    connect(squad, SIGNAL(add_score(int)),this,SLOT(new_score(int)));
}

void Gameplay::propose_move(Move mve){
    if(scene->items().indexOf(tank) >= 0){
        if(mve == Hit){ squad->fireSquad();}//tank->hit(); lives--;}
        else{
            tank->set_move(mve);
        }
    }
}

void Gameplay::propose_disable(Move mve){
    if(scene->items().indexOf(tank) >= 0){
        tank->disable_move(mve);
    }
}

void Gameplay::friendly_logic(){
    if(scene->items().indexOf(tank) >= 0){
        tank->movement();
        if(!scene->collidingItems(tank).isEmpty()){
            qDebug() << "collision!!" << scene->collidingItems(tank)[0]->type();
            tank->hit();
            lives--;
            if(lives >= 0){
                renderTank();
            }
            else{emit collision();}
        }
    }
}

void Gameplay::squad_logic(){
    squad->moveSquad();
    squad->fireSquad();
}

int Gameplay::get_current_score(){
    return score;
}

int Gameplay::get_current_lives(){
    return lives;
}

void Gameplay::new_score(int a){
    score+=a;
}
