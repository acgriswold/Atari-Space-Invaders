#include "tile.h"

Tile::Tile(QGraphicsScene *scne, int startX, int startY){
    setPos(startX, startY);

    scene = scne;

    health = 3;

    brush.setTexture(QPixmap(":/friendlies/sand_tile_init.png").scaledToWidth(32, Qt::SmoothTransformation));
}

QRectF Tile::boundingRect() const{
    return QRect(0, 0, 32, 32);
}

void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();

    painter->fillRect(rect, brush);
}

void Tile::advance(int phase){
    if(!phase) return;
    if(!scene->collidingItems(this).isEmpty()){
        qDebug() << "collision!!" << scene->collidingItems(this)[0]->type();
        hit();
    }
}

int Tile::get_width(){
    return 32;
}

int Tile::get_height(){
    return 32;
}

void Tile::hit(){
    qDebug() << "hit!";
    health--;
    scene->removeItem(scene->collidingItems(this)[0]);

    if(health <= 0){
        scene->removeItem(this);
        delete this;
    }
    else if(health == 2){
        brush.setTexture(QPixmap(":/friendlies/sand_tile_damaged1.png").scaledToWidth(32, Qt::SmoothTransformation));
        this->update(boundingRect());
    }
    else if (health == 1){
        brush.setTexture(QPixmap(":/friendlies/sand_tile_damaged2.png").scaledToWidth(32, Qt::SmoothTransformation));
        this->update(boundingRect());
    }
}
