#include "bunker.h"

Bunker::Bunker(QGraphicsScene *scne, int startX, int startY){
    scene = scne;

    int x = startX, y = startY;
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            //build tiles
            if(!(i >= 2 && (j == 1 || j == 2))){
                Tile *tile = new Tile(scene, x, y);
                scene->addItem(tile);
            }
            x += (tile[0]->get_width());
        }
        y += (tile[0]->get_height());
        x = startX;
    }
}

QGraphicsItem* Bunker::get_tile(int i){
    if (i < 10 && i >= 0){
        return tile[i];
    }
    else {
        return tile[0];
    }
}
