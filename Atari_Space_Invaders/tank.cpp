#include "tank.h"

Tank::Tank(QGraphicsScene *scne){
    //set moves
    left = false;
    right = false;
    fire = false;

    //finding scene
    scene = scne;

    //set speed
    speed = 1;
    //set x & y
    int startX;
    int startY = 245;
    if(rand()%2 == 0){
        startX = rand()%500;
    }
    else {
        startX = (-1*rand()%500);
    }

    setPos(startX, startY);

    brush.setTexture(QPixmap(":/friendlies/crab.png").scaledToHeight(64, Qt::SmoothTransformation));

    //set the firing sound for the tank
    fireSound = new QMediaPlayer();
    fireSound->setMedia(QUrl("qrc:/sounds/shoot.wav"));
    fireSound->setVolume(50);

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
        if((this->x()-speed) > ((scene->width()/2)*-1)){
            qDebug() << "Left!";
            setPos(mapToParent(-speed,0));
        }
    }
    else if(right){
        if((this->x()+this->boundingRect().width()+speed) < (scene->width()/2)){
            qDebug() << "Right!";
            setPos(mapToParent(speed,0));
        }
    }

    if(fire){
        //if there is no other bullet on the screne
        if(!(scene->items().indexOf(bullt) >= 0)){
            fireSound->stop();
            qDebug() << "Fire!";
            bullt = new bullet(this->x(), this->y());
            scene->addItem(bullt);
            fireSound->play();
        }
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

void Tank::hit(){
    qDebug() << "hit!";
    scene->removeItem(this);
    delete this;
}
