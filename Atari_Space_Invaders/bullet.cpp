#include "bullet.h"

bullet::bullet(int x, int y){
    setPos((x+16), y-32);

    speed = 25;

    brush.setTexture(QPixmap(":/friendlies/bullet_temp.png").scaledToWidth(32, Qt::SmoothTransformation));
}

QRectF bullet::boundingRect() const{
    return QRect(0, 0, 32, 32);
}

void bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();

    painter->fillRect(rect, brush);
}

void bullet::advance(int phase){
    if(!phase) return;

    setPos(mapToParent(0, -speed));
    if(this->y() < -200){delete this;}
}
