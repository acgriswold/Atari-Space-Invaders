#include "bullet_enemy.h"

bullet_enemy::bullet_enemy(int x, int y){
    setPos((x+20), y);

    speed = 25;

    brush.setTexture(QPixmap(":/friendlies/bubble.png").scaledToWidth(16, Qt::SmoothTransformation));
}

QRectF bullet_enemy::boundingRect() const{
    return QRect(0, 0, 16, 32);
}

void bullet_enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();

    painter->fillRect(rect, brush);
}

void bullet_enemy::advance(int phase){
    if(!phase) return;

    setPos(mapToParent(0, speed));
    if(this->y() > 250){delete this;}
}
