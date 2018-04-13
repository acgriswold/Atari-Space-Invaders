#include "invader.h"

Invader::Invader(QGraphicsScene *scne, int startX, int startY){

    //finding scene
    scene = scne;

    setPos(startX, startY);

    brush.setTexture(QPixmap(":/friendlies/sand_tile_init.png").scaledToWidth(44, Qt::SmoothTransformation));
}

QRectF Invader::boundingRect() const{
    return QRect(0, 0, 44, 44);
}

void Invader::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();
    painter->fillRect(rect, brush);
}

void Invader::advance(int phase){
    if(!phase){return;}
    if(!scene->collidingItems(this).isEmpty()){
        qDebug() << "collision!!" << scene->collidingItems(this)[0]->type();
        hit();
    }
}

void Invader::hit(){
    scene->removeItem(scene->collidingItems(this)[0]);

    scene->removeItem(this);
    delete this;
}
