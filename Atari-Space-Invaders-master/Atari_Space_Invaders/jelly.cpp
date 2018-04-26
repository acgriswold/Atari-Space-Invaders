#include "Jelly.h"

Jelly::Jelly(QGraphicsScene *scne){
    int startX = 620;//650
    int startY = -285;
    setPos(startX, startY);

    speed = 5;

    scene = scne;

    jelly_score=(qrand() % ((10 + 1) - 1) + 1)*50;


    brush.setTexture(QPixmap(":/friendlies/jelly_t1.png").scaledToWidth(33, Qt::SmoothTransformation));

}

QRectF Jelly::boundingRect() const{
    return QRect(0, 0, 33, 33);
}

void Jelly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();

    painter->fillRect(rect, brush);
}

void Jelly::advance(int phase){
    if(!phase) return;
    cycle_sprite();

    setPos(mapToParent(-speed, 0));


    if(!scene->collidingItems(this).isEmpty()){
        qDebug() << "collision!!" << scene->collidingItems(this)[0]->type();
        hit();
    }
    if(this->x() < -630){delete this;}
}

void Jelly::hit(){
    qDebug() << "hit!";
    emit enemy_hit_j(jelly_score);
    scene->removeItem(scene->collidingItems(this)[0]);
    scene->removeItem(this);
    delete this;
}

void Jelly::cycle_sprite(){
    qDebug() << counter;
    if(counter%5==0)
     brush.setTexture(QPixmap(":/friendlies/jelly_t1.png").scaledToWidth(33, Qt::SmoothTransformation));
    else
     brush.setTexture(QPixmap(":/friendlies/jelly_t2.png").scaledToWidth(33, Qt::SmoothTransformation));
    counter++;
    if(counter>=10)
    {counter=0;}
}
