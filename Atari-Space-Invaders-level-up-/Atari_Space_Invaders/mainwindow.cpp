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

    timer_friendly = new QTimer(this);
    connect(timer_friendly, SIGNAL(timeout()), this, SLOT(step_friendly()));
    timer_friendly->start(3);

    timer_foe = new QTimer(this);
    connect(timer_foe, SIGNAL(timeout()), this, SLOT(step_foe()));
    timer_foe->start(1000);

    QTimer *timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), scene, SLOT(advance()));
    timer1->start(55);

    connect(game, SIGNAL(collision()), this, SLOT(end_game()));
    connect(game, SIGNAL(carlos()), this, SLOT(enemy_increase()));

    //setting the background music to play in an endless loop
    backgroundMusic = new QMediaPlayer();
    backgroundMusic->setMedia(QUrl("qrc:/sounds/gameMusic.mp3"));
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/gameMusic.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    backgroundMusic->setPlaylist(playlist);
    backgroundMusic->play();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::step_friendly(){
    if(ui->stackedWidget->currentIndex() == 1){
        game->friendly_logic();
        ui->score_board->display(game->get_current_score());
        ui->live_board->display(game->get_current_lives());
    }
}

void MainWindow::step_foe(){
    if(ui->stackedWidget->currentIndex() == 1){
        game->squad_logic();
    }
}

void MainWindow::enemy_increase(){
    int currentint = timer_foe->interval();
    timer_foe->stop();
    currentint -= 100;
    if(currentint < 105){currentint = 105;}
    timer_foe->start(currentint);
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
    else if(e->key() == Qt::Key_H){
        game->propose_move(Hit);
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

void MainWindow::end_game(){
    timer_friendly->stop();
    timer_foe->stop();

    QString message = "You successfully defended the nation!  For a couple days that is... we still got obliterated... Try again?";

    if(ui->score_board->value() == 0){
        message = "Are you kidding me? That's your score? You have to play again to make up for that!";
    }
    else if(ui->score_board->value() <= 10000){
        message = "Nice try, but you could do better...  Play again?";
    }

    bool close = false;
    if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation", message, QMessageBox::Yes | QMessageBox::No)) {
         qApp->quit();
         QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
    else {
        close = true;
    }
    if(close) this->close();
}

void MainWindow::on_start_button_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_controls_button_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_button_return_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}
