/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_N;
    QAction *action_O;
    QAction *action_S;
    QAction *action_Shift_S;
    QAction *action_M;
    QAction *action_Q;
    QAction *action_C;
    QAction *action_R;
    QAction *action_Rcol;
    QAction *action_Rrow;
    QAction *action_Up;
    QAction *action_Down;
    QAction *action_Adapt;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_H;
    QMenu *menu_B;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(801, 600);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        action_N = new QAction(MainWindow);
        action_N->setObjectName("action_N");
        action_O = new QAction(MainWindow);
        action_O->setObjectName("action_O");
        action_S = new QAction(MainWindow);
        action_S->setObjectName("action_S");
        action_Shift_S = new QAction(MainWindow);
        action_Shift_S->setObjectName("action_Shift_S");
        action_M = new QAction(MainWindow);
        action_M->setObjectName("action_M");
        action_Q = new QAction(MainWindow);
        action_Q->setObjectName("action_Q");
        action_C = new QAction(MainWindow);
        action_C->setObjectName("action_C");
        action_R = new QAction(MainWindow);
        action_R->setObjectName("action_R");
        action_Rcol = new QAction(MainWindow);
        action_Rcol->setObjectName("action_Rcol");
        action_Rrow = new QAction(MainWindow);
        action_Rrow->setObjectName("action_Rrow");
        action_Up = new QAction(MainWindow);
        action_Up->setObjectName("action_Up");
        action_Down = new QAction(MainWindow);
        action_Down->setObjectName("action_Down");
        action_Adapt = new QAction(MainWindow);
        action_Adapt->setObjectName("action_Adapt");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");

        horizontalLayout->addWidget(tableView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 801, 31));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_H = new QMenu(menubar);
        menu_H->setObjectName("menu_H");
        menu_B = new QMenu(menubar);
        menu_B->setObjectName("menu_B");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_B->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu->addAction(action_N);
        menu->addAction(action_O);
        menu->addAction(action_S);
        menu->addAction(action_Shift_S);
        menu->addSeparator();
        menu->addAction(action_Q);
        menu_2->addAction(action_Adapt);
        menu_3->addAction(action_Up);
        menu_3->addAction(action_Down);
        menu_H->addAction(action_M);
        menu_B->addAction(action_C);
        menu_B->addAction(action_R);
        menu_B->addAction(action_Rcol);
        menu_B->addAction(action_Rrow);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CSV\347\274\226\350\276\221\345\231\250", nullptr));
        action_N->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(Ctrl + N)", nullptr));
        action_O->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(Ctrl + O)", nullptr));
        action_S->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(Ctrl + S)", nullptr));
        action_Shift_S->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(Ctrl + Shift + S)", nullptr));
        action_M->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216(Ctrl + M)", nullptr));
        action_Q->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255(Ctrl + Q)", nullptr));
        action_C->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\200\345\210\227(Ctrl + Shift + C)", nullptr));
        action_R->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\270\200\350\241\214(Ctrl + Shift + R)", nullptr));
        action_Rcol->setText(QCoreApplication::translate("MainWindow", "\345\207\217\345\260\221\344\270\200\345\210\227", nullptr));
        action_Rrow->setText(QCoreApplication::translate("MainWindow", "\345\207\217\345\260\221\344\270\200\350\241\214", nullptr));
        action_Up->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\345\242\236\345\244\247(Ctrl + Shift + U)", nullptr));
        action_Down->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\345\207\217\345\260\217(Ctrl + Shift + D)", nullptr));
        action_Adapt->setText(QCoreApplication::translate("MainWindow", "\350\241\250\346\240\274\351\200\202\345\272\224", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213(&O)", nullptr));
        menu_H->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
        menu_B->setTitle(QCoreApplication::translate("MainWindow", "\350\241\250\346\240\274(&B)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
