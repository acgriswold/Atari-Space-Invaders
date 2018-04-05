#include "tank.h"

Tank::Tank(QGraphicsScene *scne){
    //set moves
    left = false;
    right = false;
    fire = false;

    //finding scene
    scene = scne;

    //set speed
    speed = 10;
    //set x & y
    int startX = 0;
    int startY = 200;

    setPos(startX, startY);

    brush.setTexture(QPixmap(":/friendlies/tank_temp.png").scaledToWidth(64, Qt::SmoothTransformation));
}

QRectF Tank::boundingRect() const{
    return QRect(0, 0, 64, 64);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();

    painter->fillRect(rect, brush);
}

void Tank::advance(int phase){
    if(!phase) return;
}

void Tank::movement(){
    if(left){
        qDebug() << "Left!";
        setPos(mapToParent(-speed,0));
    }
    else if(right){
        qDebug() << "Right!";
        setPos(mapToParent(speed,0));
    }

    if(fire){
        qDebug() << "Fire!";
        bullet *item = new bullet(this->x(), this->y());
        scene->addItem(item);
    }
}

void Tank::set_move(Move mve){
    if(mve == Left){
        left  = true;
        right = false;
    }
    else if(mve == Right){
        right = true;
        left = false;

    }
    else if(mve == Fire){
        fire = true;
    }
}

void Tank::disable_move(Move mve){
    if(mve == Left){
        left  = false;
    }
    else if(mve == Right){
        right = false;
    }
    else if(mve == Fire){
        fire = false;
    }
}
