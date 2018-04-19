#include "invader.h"

Invader::Invader(QGraphicsScene *scne, int startX, int startY, Typee tpe){

    //finding scene
    scene = scne;

    setPos(startX, startY);

    if(body == Dolphin){
        brush.setTexture(QPixmap(":/friendlies/dolphin.png").scaledToWidth(33, Qt::SmoothTransformation));
    }
    else if (body == Star){
        brush.setTexture(QPixmap(":/friendlies/star.png").scaledToWidth(33, Qt::SmoothTransformation));
    }
    else if (body == Octo){
        brush.setTexture(QPixmap(":/friendlies/octopus.png").scaledToWidth(33, Qt::SmoothTransformation));
    }
    else if (body == Jelly){
        brush.setTexture(QPixmap(":/friendlies/bubble.png").scaledToWidth(33, Qt::SmoothTransformation));
    }
}

QRectF Invader::boundingRect() const{
    return QRect(0, 0, 33, 33);
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

    if(body == Dolphin){emit enemy_hit(40);}
    else if(body == Star){emit enemy_hit(20);}
    else if(body == Octo){emit enemy_hit(10);}
    else if(body == Jelly){emit enemy_hit(150);}
}

void Invader::move(int x, int y){
    setPos(x, y);
}

void Invader::fire(){
    qDebug() << "Enemy Fire!";
    bullet_enemy *bullt = new bullet_enemy(this->x(), (this->y()+this->boundingRect().height()));
    scene->addItem(bullt);
}
