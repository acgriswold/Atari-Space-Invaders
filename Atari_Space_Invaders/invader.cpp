#include "invader.h"

Invader::Invader(QGraphicsScene *scne, int startX, int startY, Typee tpe){

    //finding scene
    scene = scne;

    sprite_index = 0;

    setPos(startX, startY);

    body = tpe;

    if(body == Dolphin){
         brush.setTexture(QPixmap::fromImage(QPixmap(":/friendlies/dolphin2.png").scaledToWidth(33, Qt::SmoothTransformation).toImage().mirrored(true, false)));
    }
    else if (body == Star){
        brush.setTexture(QPixmap::fromImage(QPixmap(":/friendlies/star2.png").scaledToWidth(33, Qt::SmoothTransformation).toImage().mirrored(true, false)));
    }
    else if (body == Octo){
        brush.setTexture(QPixmap::fromImage(QPixmap(":/friendlies/octopus2.png").scaledToWidth(33, Qt::SmoothTransformation).toImage().mirrored(true, false)));
    }
    //set the firing sound for the invaders
    fireSound = new QMediaPlayer();
    fireSound->setMedia(QUrl("qrc:sounds/bubble.mp3"));
    fireSound->setVolume(75);
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

    if(body == Dolphin){emit enemy_hit(40);}
    else if(body == Star){emit enemy_hit(20);}
    else if(body == Octo){emit enemy_hit(10);}

    delete this;
}

void Invader::move(int x, int y){
    setPos(x, y);
}

void Invader::cycle_sprite(int spd){
    if(sprite_index == 1){
        if(spd < 0){
            if(body == Dolphin){
                brush.setTexture(QPixmap(":/friendlies/dolphin2.png").scaledToWidth(33, Qt::SmoothTransformation));
            }
            else if (body == Star){
                brush.setTexture(QPixmap(":/friendlies/star2.png").scaledToWidth(33, Qt::SmoothTransformation));
            }
            else if (body == Octo){
                brush.setTexture(QPixmap(":/friendlies/octopus2.png").scaledToWidth(33, Qt::SmoothTransformation));
            }
        }
        else {
            if(body == Dolphin){
                 brush.setTexture(QPixmap::fromImage(QPixmap(":/friendlies/dolphin2.png").scaledToWidth(33, Qt::SmoothTransformation).toImage().mirrored(true, false)));
            }
            else if (body == Star){
                brush.setTexture(QPixmap::fromImage(QPixmap(":/friendlies/star2.png").scaledToWidth(33, Qt::SmoothTransformation).toImage().mirrored(true, false)));
            }
            else if (body == Octo){
                brush.setTexture(QPixmap::fromImage(QPixmap(":/friendlies/octopus2.png").scaledToWidth(33, Qt::SmoothTransformation).toImage().mirrored(true, false)));
            }
        }
    }
    else{
        if(spd < 0){
            if(body == Dolphin){
                brush.setTexture(QPixmap(":/friendlies/dolphin.png").scaledToWidth(33, Qt::SmoothTransformation));
            }
            else if (body == Star){
                brush.setTexture(QPixmap(":/friendlies/star.png").scaledToWidth(33, Qt::SmoothTransformation));
            }
            else if (body == Octo){
                brush.setTexture(QPixmap(":/friendlies/octopus.png").scaledToWidth(33, Qt::SmoothTransformation));
            }
        }
        else {
            if(body == Dolphin){
                 brush.setTexture(QPixmap::fromImage(QPixmap(":/friendlies/dolphin.png").scaledToWidth(33, Qt::SmoothTransformation).toImage().mirrored(true, false)));
            }
            else if (body == Star){
                brush.setTexture(QPixmap::fromImage(QPixmap(":/friendlies/star.png").scaledToWidth(33, Qt::SmoothTransformation).toImage().mirrored(true, false)));
            }
            else if (body == Octo){
                brush.setTexture(QPixmap::fromImage(QPixmap(":/friendlies/octopus.png").scaledToWidth(33, Qt::SmoothTransformation).toImage().mirrored(true, false)));
            }
        }
    }
    sprite_index++;
    if(sprite_index >= 2)
        sprite_index = 0;

}

void Invader::fire(){
    qDebug() << "Enemy Fire!";

    //play the firing sound for the invaders
    fireSound->play();
    bullet_enemy *bullt = new bullet_enemy(this->x(), (this->y()+this->boundingRect().height()));
    scene->addItem(bullt);
}
