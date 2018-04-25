#include "Jelly.h"

Jelly::Jelly(QGraphicsScene *scne){
    int startX = 0;
    int startY = -285;
    setPos(startX, startY);

    speed = 0;

    scene = scne;

    brush.setTexture(QPixmap(":/friendlies/sand_tile_init.png").scaledToWidth(32, Qt::SmoothTransformation));
}

QRectF Jelly::boundingRect() const{
    return QRect(0, 0, 32, 32);
}

void Jelly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();

    painter->fillRect(rect, brush);
}

void Jelly::advance(int phase){
    if(!phase) return;

    setPos(mapToParent(speed, 0));

    if(!scene->collidingItems(this).isEmpty()){
        qDebug() << "collision!!" << scene->collidingItems(this)[0]->type();
        hit();
    }
    if(this->x() > 500){delete this;}
}

void Jelly::hit(){
    qDebug() << "hit!";
    scene->removeItem(scene->collidingItems(this)[0]);
    scene->removeItem(this);
    delete this;
}
