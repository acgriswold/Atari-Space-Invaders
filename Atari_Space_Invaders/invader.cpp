#include "invader.h"

Invader::Invader(QGraphicsScene *scne, int startX, int startY){

    //finding scene
    scene = scne;

    setPos(startX, startY);

    brush.setTexture(QPixmap(":/friendlies/sand_tile_init.png").scaledToWidth(32, Qt::SmoothTransformation));
}

QRectF Invader::boundingRect() const{
    return QRect(0, 0, 32, 32);
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

void Invader::move(int x, int y){
    setPos(x, y);
}

void Invader::fire(){
    qDebug() << "Enemy Fire!";
    bullet_enemy *bullt = new bullet_enemy(this->x(), (this->y()+this->boundingRect().height()));
    scene->addItem(bullt);
}
