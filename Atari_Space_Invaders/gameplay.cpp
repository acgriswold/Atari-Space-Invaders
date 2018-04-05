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
    renderAlien(level);
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

}

void Gameplay::renderAlien(int lvl){

}

void Gameplay::propose_move(Move mve){
    tank->set_move(mve);
}

void Gameplay::propose_disable(Move mve){
    tank->disable_move(mve);
}

void Gameplay::logic(){
    tank->movement();
}
