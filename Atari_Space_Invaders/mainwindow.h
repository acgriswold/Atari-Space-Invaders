#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include "gameplay.h"
#include "tank.h"

#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void keyPressEvent(QKeyEvent* e);
    void keyReleaseEvent(QKeyEvent* e);

private slots:
    void on_up_pressed();
    void on_left_pressed();
    void on_right_pressed();
    void on_up_release();
    void on_left_release();
    void on_right_release();

    void step_friendly();
    void step_foe();
    void enemy_increase();

    void show_jelly();

    void end_game();

    void on_start_button_clicked();

    void on_controls_button_clicked();

    void on_button_return_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QTimer *timer_friendly;
    QTimer *timer_foe;
    QTimer *timer_jelly;
    Gameplay *game;
    QMediaPlaylist *playlist;
    QMediaPlayer *backgroundMusic;
};

#endif // MAINWINDOW_H
