#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QGraphicsScene>
#include <QObject>
#include <QLCDNumber>

#include "tank.h"
#include "bunker.h"
#include "squad.h"

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
    void renderSquad(int lvl);

    void friendly_logic();
    void squad_logic();

    void propose_move(Move mve);
    void propose_disable(Move mve);

    void doCollision();

    int get_current_score();
    int get_current_lives();

signals:
    void collision();

private slots:

    void new_score(int);

private:
    int level;
    QGraphicsScene *scene;

    Tank *tank;
    Bunker *bunker;
    Tile *tile;
    Squad *squad;

    int score;

    int lives;
};

#endif // GAMEPLAY_H
