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
    /*void on_up_pressed();
    void on_left_pressed();
    void on_right_pressed();
    void on_up_release();
    void on_left_release();
    void on_right_release();*/

    void step();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QTimer *timer;
    Gameplay *game;
};

#endif // MAINWINDOW_H
