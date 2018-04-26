#include "Jelly.h"

Jelly::Jelly(QGraphicsScene *scne){
    if(qrand()%2 >= 1) dir = lft;
    else dir = rght;

    int startX;
    if(dir == lft) startX = 620;
    else startX = -620;

    int startY = -285;
    setPos(startX, startY);

    if(dir == lft) speed = -5;
    else speed = 5;

    scene = scne;
    counter = 0;

    jelly_score=(qrand() % ((10 + 1) - 1) + 1)*50;

    brush.setTexture(QPixmap(":/foes/jelly_t1.png").scaledToWidth(33, Qt::SmoothTransformation));
}

QRectF Jelly::boundingRect() const{
    return QRect(0, 0, 33, 33);
}

void Jelly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();

    cycle_sprite();

    painter->fillRect(rect, brush);
}

void Jelly::advance(int phase){
    if(!phase) return;

    setPos(mapToParent(speed, 0));

    if(!scene->collidingItems(this).isEmpty()){
        qDebug() << "collision!!" << scene->collidingItems(this)[0]->type();
        hit();
    }
    if(this->x() < -636){delete this;}
}

void Jelly::hit(){
    qDebug() << "hit!";
    emit enemy_hit_j(jelly_score);
    scene->removeItem(scene->collidingItems(this)[0]);
    scene->removeItem(this);
    delete this;
}

void Jelly::cycle_sprite(){
    //qDebug() << counter;
    if(counter%10 < 5)
     brush.setTexture(QPixmap(":/foes/jelly_t1.png").scaledToWidth(33, Qt::SmoothTransformation));
    else
     brush.setTexture(QPixmap(":/foes/jelly_t2.png").scaledToWidth(33, Qt::SmoothTransformation));
    counter++;
    if(counter >= 10)
    {counter=0;}
}
