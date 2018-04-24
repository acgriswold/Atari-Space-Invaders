/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QLabel *label_4;
    QPushButton *start_button;
    QPushButton *controls_button;
    QWidget *page_4;
    QLabel *label;
    QLCDNumber *live_board;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QLabel *label_3;
    QLCDNumber *score_board;
    QWidget *page_5;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *button_return;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1315, 751);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 0, 1311, 711));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(-10, 100, 1311, 101));
        QFont font;
        font.setFamily(QStringLiteral("MS Serif"));
        font.setPointSize(22);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        start_button = new QPushButton(page_3);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(340, 390, 131, 71));
        start_button->setFont(font);
        controls_button = new QPushButton(page_3);
        controls_button->setObjectName(QStringLiteral("controls_button"));
        controls_button->setGeometry(QRect(830, 390, 131, 71));
        controls_button->setFont(font);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label = new QLabel(page_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(5, 50, 1300, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/passives/sea_background.png")));
        live_board = new QLCDNumber(page_4);
        live_board->setObjectName(QStringLiteral("live_board"));
        live_board->setGeometry(QRect(1120, 5, 111, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Serif"));
        font1.setPointSize(20);
        live_board->setFont(font1);
        live_board->setStyleSheet(QStringLiteral("border: 0px;"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1050, 0, 81, 51));
        label_2->setFont(font);
        graphicsView = new QGraphicsView(page_4);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1311, 701));
        graphicsView->setStyleSheet(QStringLiteral("background: transparent;;"));
        label_3 = new QLabel(page_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1050, 650, 81, 41));
        label_3->setFont(font);
        score_board = new QLCDNumber(page_4);
        score_board->setObjectName(QStringLiteral("score_board"));
        score_board->setGeometry(QRect(1130, 650, 111, 41));
        score_board->setFont(font1);
        score_board->setStyleSheet(QStringLiteral("border: 0px;"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        label_5 = new QLabel(page_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(-10, 90, 1311, 41));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(page_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(540, 130, 211, 261));
        label_6->setFont(font);
        label_6->setTextFormat(Qt::AutoText);
        button_return = new QPushButton(page_5);
        button_return->setObjectName(QStringLiteral("button_return"));
        button_return->setGeometry(QRect(580, 430, 131, 71));
        button_return->setFont(font);
        stackedWidget->addWidget(page_5);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1315, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Atari Space (Sea) Invaders", Q_NULLPTR));
        start_button->setText(QApplication::translate("MainWindow", "Start!", Q_NULLPTR));
        controls_button->setText(QApplication::translate("MainWindow", "Controls!", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Lives:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Score:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Controls:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Left: A\n"
"Right:D\n"
"Up: W\n"
"Down: S\n"
"Fire: Space", Q_NULLPTR));
        button_return->setText(QApplication::translate("MainWindow", "Return!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
