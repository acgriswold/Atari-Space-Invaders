#include "invader.h"

Invader::Invader(QGraphicsScene *scne, int startX, int startY){

    //finding scene
    scene = scne;

    setPos(startX, startY);

    brush.setTexture(QPixmap(":/friendlies/tank_temp.png").scaledToWidth(44, Qt::SmoothTransformation));
}

QRectF Invader::boundingRect() const{
    return QRect(0, 0, 44, 44);
}

void Invader::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();
    painter->fillRect(rect, brush);
}
