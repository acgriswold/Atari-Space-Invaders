#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QGraphicsScene>
#include <QObject>
#include <QLCDNumber>

#include "tank.h"
#include "bunker.h"

class Gameplay : public QObject
{
    Q_OBJECT
public:
    Gameplay(QGraphicsScene *scne);
    ~Gameplay();

    void renderGame();
    void renderBorder();
    void renderTank();
    void renderBunker();
    void renderAlien(int lvl);

    void logic();

    void propose_move(Move mve);
    void propose_disable(Move mve);

private:
    int level;
    QGraphicsScene *scene;

    Tank *tank;
    Bunker *bunker;
};

#endif // GAMEPLAY_H
