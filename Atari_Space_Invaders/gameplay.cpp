#include "gameplay.h"

Gameplay::Gameplay(QGraphicsScene *scne){
    scene = scne;

    level = 0;
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
}

void Gameplay::propose_move(Move mve){
    tank->set_move(mve);
}

void Gameplay::propose_disable(Move mve){
    tank->disable_move(mve);
}

void Gameplay::friendly_logic(){
    tank->movement();
}

void Gameplay::squad_logic(){
    squad->moveSquad();
}
