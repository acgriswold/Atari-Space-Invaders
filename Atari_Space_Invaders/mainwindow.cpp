#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-650, -290, 1300, 600);

    game = new Gameplay(scene);

    game->renderGame();

    /*Working with arrow keys for Khadka*/
    //press handling
    /*QShortcut *shortcutUp = new QShortcut(QKeySequence("Up"), this);
    QObject::connect(shortcutUp, SIGNAL(activated()), this, SLOT(on_up_pressed()));
    QShortcut *shortcutLeft = new QShortcut(QKeySequence("Left"), this);
    QObject::connect(shortcutLeft, SIGNAL(activated()), this, SLOT(on_left_pressed()));
    QShortcut*shortcutRight = new QShortcut(QKeySequence("Right"), this);
    QObject::connect(shortcutRight, SIGNAL(activated()), this, SLOT(on_right_pressed()));

    //Release handling
    QObject::connect(shortcutUp, SIGNAL(deactivated()), this, SLOT(on_up_released()));
    QObject::connect(shortcutLeft, SIGNAL(deactivated()), this, SLOT(on_left_released()));
    QObject::connect(shortcutRight, SIGNAL(deactivated()), this, SLOT(on_right_released()));*/

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(step()));
    timer->start(3);

    QTimer *timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), scene, SLOT(advance()));
    timer1->start(55);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::step(){
    game->logic();
}

void MainWindow::keyPressEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_A){
        game->propose_move(Left);
    }
    else if(e->key() == Qt::Key_D){
        game->propose_move(Right);
    }
    else if(e->key() == Qt::Key_Space){
        game->propose_move(Fire);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_A){
        game->propose_disable(Left);
    }
    else if(e->key() == Qt::Key_D){
        game->propose_disable(Right);
    }
    else if(e->key() == Qt::Key_Space){
        game->propose_disable(Fire);
    }
}

/*void MainWindow::on_left_pressed(){
    game->propose_move(Left);
}
void MainWindow::on_right_pressed(){
    game->propose_move(Right);
}
void MainWindow::on_up_pressed(){
    game->propose_move(Fire);
}
void MainWindow::on_left_release(){
    game->propose_disable(Left);
}
void MainWindow::on_right_release(){
    game->propose_disable(Right);
}
void MainWindow::on_up_release(){
    game->propose_disable(Fire);
}*/
