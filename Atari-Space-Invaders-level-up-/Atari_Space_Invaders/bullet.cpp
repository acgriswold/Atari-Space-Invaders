#include "bullet.h"

bullet::bullet(int x, int y){
    setPos((x+20), y-32);

    speed = 32;

    brush.setTexture(QPixmap(":/friendlies/bullet_temp.png").scaledToWidth(16, Qt::SmoothTransformation));
}

QRectF bullet::boundingRect() const{
    return QRect(0, 0, 16, 32);
}

void bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();

    painter->fillRect(rect, brush);
}

void bullet::advance(int phase){
    if(!phase) return;

    setPos(mapToParent(0, -speed));
    if(this->y() < -300){delete this;}
}
