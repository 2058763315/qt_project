/********************************************************************************
** Form generated from reading UI file 'carwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARWINDOW_H
#define UI_CARWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_carWindow
{
public:
    QAction *action_W;
    QAction *action_Q;
    QAction *action_V;
    QAction *action_Jab;
    QAction *action_Light;
    QWidget *centralwidget;
    QDial *dial;
    QLabel *label;
    QLabel *label_Angle;
    QLabel *label_Speed;
    QLabel *label_2;
    QGroupBox *groupBox;
    QCheckBox *checkBox_SeatbeltER;
    QLabel *label_12;
    QCheckBox *checkBox_SeatbeltEL;
    QLabel *label_6;
    QLabel *label_10;
    QCheckBox *checkBox_SeatbeltFR;
    QCheckBox *checkBox_SeatbeltFL;
    QLabel *label_11;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_R;
    QGroupBox *groupBox_3;
    QSlider *verticalSlider_acc;
    QLabel *label_clutch;
    QLabel *label_brake;
    QLabel *label_acc;
    QSlider *verticalSlider_clutch;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QSlider *verticalSlider_brake;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_lowB;
    QCheckBox *checkBox_highB;
    QCheckBox *checkBox_rightT;
    QCheckBox *checkBox_LeftRight;
    QCheckBox *checkBox_brakeL;
    QCheckBox *checkBox_leftT;
    QCheckBox *checkBox_poslightF;
    QCheckBox *checkBox_poslightE;
    QCheckBox *checkBox_foglight;
    QGroupBox *groupBox_5;
    QCheckBox *checkBox_doorER;
    QLabel *label_13;
    QCheckBox *checkBox_doorEL;
    QLabel *label_7;
    QLabel *label_14;
    QCheckBox *checkBox_doorFR;
    QCheckBox *checkBox_doorFL;
    QLabel *label_15;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_Reset;
    QPushButton *pushButton_Left;
    QPushButton *pushButton_Right;
    QPushButton *pushButton_LeftJab;
    QPushButton *pushButton_RightJab;
    QMenuBar *menubar;
    QMenu *menu_C;
    QMenu *menu_H;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *carWindow)
    {
        if (carWindow->objectName().isEmpty())
            carWindow->setObjectName("carWindow");
        carWindow->resize(1100, 600);
        QFont font;
        font.setPointSize(16);
        carWindow->setFont(font);
        action_W = new QAction(carWindow);
        action_W->setObjectName("action_W");
        action_Q = new QAction(carWindow);
        action_Q->setObjectName("action_Q");
        action_V = new QAction(carWindow);
        action_V->setObjectName("action_V");
        action_Jab = new QAction(carWindow);
        action_Jab->setObjectName("action_Jab");
        action_Light = new QAction(carWindow);
        action_Light->setObjectName("action_Light");
        centralwidget = new QWidget(carWindow);
        centralwidget->setObjectName("centralwidget");
        dial = new QDial(centralwidget);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(490, 20, 220, 220));
        dial->setStyleSheet(QString::fromUtf8(""));
        dial->setMinimum(-180);
        dial->setMaximum(180);
        dial->setWrapping(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(790, 80, 150, 30));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_Angle = new QLabel(centralwidget);
        label_Angle->setObjectName("label_Angle");
        label_Angle->setGeometry(QRect(940, 80, 100, 30));
        label_Angle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_Speed = new QLabel(centralwidget);
        label_Speed->setObjectName("label_Speed");
        label_Speed->setGeometry(QRect(940, 150, 100, 30));
        label_Speed->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(820, 150, 100, 30));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(350, 300, 201, 211));
        checkBox_SeatbeltER = new QCheckBox(groupBox);
        checkBox_SeatbeltER->setObjectName("checkBox_SeatbeltER");
        checkBox_SeatbeltER->setGeometry(QRect(150, 160, 20, 20));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(150, 30, 31, 41));
        checkBox_SeatbeltEL = new QCheckBox(groupBox);
        checkBox_SeatbeltEL->setObjectName("checkBox_SeatbeltEL");
        checkBox_SeatbeltEL->setGeometry(QRect(90, 160, 20, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 80, 31, 41));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(30, 150, 31, 41));
        checkBox_SeatbeltFR = new QCheckBox(groupBox);
        checkBox_SeatbeltFR->setObjectName("checkBox_SeatbeltFR");
        checkBox_SeatbeltFR->setGeometry(QRect(150, 90, 20, 20));
        checkBox_SeatbeltFL = new QCheckBox(groupBox);
        checkBox_SeatbeltFL->setObjectName("checkBox_SeatbeltFL");
        checkBox_SeatbeltFL->setGeometry(QRect(90, 90, 20, 20));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(90, 30, 31, 41));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(30, 300, 301, 211));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 40, 281, 161));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_1 = new QRadioButton(layoutWidget);
        radioButton_1->setObjectName("radioButton_1");

        gridLayout_2->addWidget(radioButton_1, 0, 0, 1, 1);

        radioButton_3 = new QRadioButton(layoutWidget);
        radioButton_3->setObjectName("radioButton_3");

        gridLayout_2->addWidget(radioButton_3, 0, 1, 1, 1);

        radioButton_5 = new QRadioButton(layoutWidget);
        radioButton_5->setObjectName("radioButton_5");

        gridLayout_2->addWidget(radioButton_5, 0, 2, 1, 1);

        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName("radioButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy);
        radioButton->setMinimumSize(QSize(0, 40));
        radioButton->setChecked(true);

        gridLayout_2->addWidget(radioButton, 1, 1, 1, 1);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName("radioButton_2");

        gridLayout_2->addWidget(radioButton_2, 2, 0, 1, 1);

        radioButton_4 = new QRadioButton(layoutWidget);
        radioButton_4->setObjectName("radioButton_4");

        gridLayout_2->addWidget(radioButton_4, 2, 1, 1, 1);

        radioButton_R = new QRadioButton(layoutWidget);
        radioButton_R->setObjectName("radioButton_R");

        gridLayout_2->addWidget(radioButton_R, 2, 2, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(780, 220, 281, 291));
        verticalSlider_acc = new QSlider(groupBox_3);
        verticalSlider_acc->setObjectName("verticalSlider_acc");
        verticalSlider_acc->setGeometry(QRect(220, 90, 22, 141));
        verticalSlider_acc->setMaximum(10);
        verticalSlider_acc->setOrientation(Qt::Orientation::Vertical);
        label_clutch = new QLabel(groupBox_3);
        label_clutch->setObjectName("label_clutch");
        label_clutch->setGeometry(QRect(20, 50, 60, 31));
        label_clutch->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_brake = new QLabel(groupBox_3);
        label_brake->setObjectName("label_brake");
        label_brake->setGeometry(QRect(110, 50, 60, 31));
        label_brake->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_acc = new QLabel(groupBox_3);
        label_acc->setObjectName("label_acc");
        label_acc->setGeometry(QRect(200, 50, 60, 31));
        label_acc->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalSlider_clutch = new QSlider(groupBox_3);
        verticalSlider_clutch->setObjectName("verticalSlider_clutch");
        verticalSlider_clutch->setGeometry(QRect(40, 90, 22, 141));
        verticalSlider_clutch->setMaximum(10);
        verticalSlider_clutch->setOrientation(Qt::Orientation::Vertical);
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 231, 261, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_5);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_4);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_3);

        verticalSlider_brake = new QSlider(groupBox_3);
        verticalSlider_brake->setObjectName("verticalSlider_brake");
        verticalSlider_brake->setGeometry(QRect(130, 90, 22, 141));
        verticalSlider_brake->setMaximum(10);
        verticalSlider_brake->setOrientation(Qt::Orientation::Vertical);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(20, 30, 411, 241));
        layoutWidget_2 = new QWidget(groupBox_4);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 40, 394, 181));
        gridLayout = new QGridLayout(layoutWidget_2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_lowB = new QCheckBox(layoutWidget_2);
        checkBox_lowB->setObjectName("checkBox_lowB");

        gridLayout->addWidget(checkBox_lowB, 1, 1, 1, 1);

        checkBox_highB = new QCheckBox(layoutWidget_2);
        checkBox_highB->setObjectName("checkBox_highB");

        gridLayout->addWidget(checkBox_highB, 0, 1, 1, 1);

        checkBox_rightT = new QCheckBox(layoutWidget_2);
        checkBox_rightT->setObjectName("checkBox_rightT");

        gridLayout->addWidget(checkBox_rightT, 1, 0, 1, 1);

        checkBox_LeftRight = new QCheckBox(layoutWidget_2);
        checkBox_LeftRight->setObjectName("checkBox_LeftRight");

        gridLayout->addWidget(checkBox_LeftRight, 2, 0, 1, 1);

        checkBox_brakeL = new QCheckBox(layoutWidget_2);
        checkBox_brakeL->setObjectName("checkBox_brakeL");

        gridLayout->addWidget(checkBox_brakeL, 2, 1, 1, 1);

        checkBox_leftT = new QCheckBox(layoutWidget_2);
        checkBox_leftT->setObjectName("checkBox_leftT");
        checkBox_leftT->setIconSize(QSize(20, 20));

        gridLayout->addWidget(checkBox_leftT, 0, 0, 1, 1);

        checkBox_poslightF = new QCheckBox(layoutWidget_2);
        checkBox_poslightF->setObjectName("checkBox_poslightF");

        gridLayout->addWidget(checkBox_poslightF, 0, 2, 1, 1);

        checkBox_poslightE = new QCheckBox(layoutWidget_2);
        checkBox_poslightE->setObjectName("checkBox_poslightE");

        gridLayout->addWidget(checkBox_poslightE, 1, 2, 1, 1);

        checkBox_foglight = new QCheckBox(layoutWidget_2);
        checkBox_foglight->setObjectName("checkBox_foglight");

        gridLayout->addWidget(checkBox_foglight, 2, 2, 1, 1);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(560, 300, 201, 211));
        checkBox_doorER = new QCheckBox(groupBox_5);
        checkBox_doorER->setObjectName("checkBox_doorER");
        checkBox_doorER->setGeometry(QRect(150, 160, 20, 20));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(150, 30, 31, 41));
        checkBox_doorEL = new QCheckBox(groupBox_5);
        checkBox_doorEL->setObjectName("checkBox_doorEL");
        checkBox_doorEL->setGeometry(QRect(90, 160, 20, 20));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 80, 31, 41));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(30, 150, 31, 41));
        checkBox_doorFR = new QCheckBox(groupBox_5);
        checkBox_doorFR->setObjectName("checkBox_doorFR");
        checkBox_doorFR->setGeometry(QRect(150, 90, 20, 20));
        checkBox_doorFL = new QCheckBox(groupBox_5);
        checkBox_doorFL->setObjectName("checkBox_doorFL");
        checkBox_doorFL->setGeometry(QRect(90, 90, 20, 20));
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(90, 30, 31, 41));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(500, 30, 200, 200));
        graphicsView->setStyleSheet(QString::fromUtf8("border:none;\n"
"background: #bec8fd;\n"
"border-radius:100%;"));
        pushButton_Reset = new QPushButton(centralwidget);
        pushButton_Reset->setObjectName("pushButton_Reset");
        pushButton_Reset->setGeometry(QRect(560, 260, 81, 41));
        pushButton_Reset->setFont(font);
        pushButton_Reset->setStyleSheet(QString::fromUtf8("background-color: #14a36a;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 8px;"));
        pushButton_Left = new QPushButton(centralwidget);
        pushButton_Left->setObjectName("pushButton_Left");
        pushButton_Left->setGeometry(QRect(440, 210, 93, 41));
        pushButton_Left->setFont(font);
        pushButton_Left->setStyleSheet(QString::fromUtf8("background-color: #14a36a;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 8px;"));
        pushButton_Right = new QPushButton(centralwidget);
        pushButton_Right->setObjectName("pushButton_Right");
        pushButton_Right->setGeometry(QRect(670, 210, 93, 41));
        pushButton_Right->setFont(font);
        pushButton_Right->setStyleSheet(QString::fromUtf8("background-color: #14a36a;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 8px;"));
        pushButton_LeftJab = new QPushButton(centralwidget);
        pushButton_LeftJab->setObjectName("pushButton_LeftJab");
        pushButton_LeftJab->setGeometry(QRect(440, 260, 111, 41));
        pushButton_LeftJab->setFont(font);
        pushButton_LeftJab->setStyleSheet(QString::fromUtf8("background-color: #14a36a;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 8px;"));
        pushButton_RightJab = new QPushButton(centralwidget);
        pushButton_RightJab->setObjectName("pushButton_RightJab");
        pushButton_RightJab->setGeometry(QRect(652, 260, 111, 41));
        pushButton_RightJab->setFont(font);
        pushButton_RightJab->setStyleSheet(QString::fromUtf8("background-color: #14a36a;\n"
"border: none;\n"
"color: white;\n"
"border-radius: 8px;"));
        carWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(carWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1100, 40));
        menu_C = new QMenu(menubar);
        menu_C->setObjectName("menu_C");
        menu_H = new QMenu(menubar);
        menu_H->setObjectName("menu_H");
        carWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(carWindow);
        statusbar->setObjectName("statusbar");
        carWindow->setStatusBar(statusbar);

        menubar->addAction(menu_C->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu_C->addAction(action_Light);
        menu_C->addAction(action_Jab);
        menu_C->addSeparator();
        menu_C->addAction(action_Q);
        menu_H->addAction(action_W);
        menu_H->addAction(action_V);

        retranslateUi(carWindow);

        QMetaObject::connectSlotsByName(carWindow);
    } // setupUi

    void retranslateUi(QMainWindow *carWindow)
    {
        carWindow->setWindowTitle(QCoreApplication::translate("carWindow", "car", nullptr));
        action_W->setText(QCoreApplication::translate("carWindow", "\346\223\215\344\275\234\346\214\207\345\215\227(Ctrl + W)", nullptr));
        action_Q->setText(QCoreApplication::translate("carWindow", "\351\200\200\345\207\272(Ctrl + Q)", nullptr));
        action_V->setText(QCoreApplication::translate("carWindow", "\347\211\210\346\234\254\344\277\241\346\201\257(Ctrl + V)", nullptr));
        action_Jab->setText(QCoreApplication::translate("carWindow", "\350\256\276\347\275\256\347\214\233\346\211\223\350\247\222\345\272\246", nullptr));
        action_Light->setText(QCoreApplication::translate("carWindow", "\350\256\276\347\275\256\350\275\273\346\211\223\350\247\222\345\272\246", nullptr));
        label->setText(QCoreApplication::translate("carWindow", "\346\226\271\345\220\221\347\233\230\350\247\222\345\272\246", nullptr));
        label_Angle->setText(QCoreApplication::translate("carWindow", "0", nullptr));
        label_Speed->setText(QCoreApplication::translate("carWindow", "0.00", nullptr));
        label_2->setText(QCoreApplication::translate("carWindow", "\351\200\237\345\272\246", nullptr));
        groupBox->setTitle(QCoreApplication::translate("carWindow", "\345\256\211\345\205\250\345\270\246", nullptr));
        checkBox_SeatbeltER->setText(QString());
        label_12->setText(QCoreApplication::translate("carWindow", "\345\217\263", nullptr));
        checkBox_SeatbeltEL->setText(QString());
        label_6->setText(QCoreApplication::translate("carWindow", "\345\211\215", nullptr));
        label_10->setText(QCoreApplication::translate("carWindow", "\345\220\216", nullptr));
        checkBox_SeatbeltFR->setText(QString());
        checkBox_SeatbeltFL->setText(QString());
        label_11->setText(QCoreApplication::translate("carWindow", "\345\267\246", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("carWindow", "\346\241\243\344\275\215", nullptr));
        radioButton_1->setText(QCoreApplication::translate("carWindow", "1", nullptr));
        radioButton_3->setText(QCoreApplication::translate("carWindow", "3", nullptr));
        radioButton_5->setText(QCoreApplication::translate("carWindow", "5", nullptr));
        radioButton->setText(QCoreApplication::translate("carWindow", "N", nullptr));
        radioButton_2->setText(QCoreApplication::translate("carWindow", "2", nullptr));
        radioButton_4->setText(QCoreApplication::translate("carWindow", "4", nullptr));
        radioButton_R->setText(QCoreApplication::translate("carWindow", "R", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("carWindow", "\346\223\215\344\275\234", nullptr));
        label_clutch->setText(QCoreApplication::translate("carWindow", "0", nullptr));
        label_brake->setText(QCoreApplication::translate("carWindow", "0", nullptr));
        label_acc->setText(QCoreApplication::translate("carWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("carWindow", "\347\246\273\345\220\210", nullptr));
        label_4->setText(QCoreApplication::translate("carWindow", "\345\210\271\350\275\246", nullptr));
        label_3->setText(QCoreApplication::translate("carWindow", "\346\262\271\351\227\250", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("carWindow", "\347\201\257\345\205\211", nullptr));
        checkBox_lowB->setText(QCoreApplication::translate("carWindow", "\350\277\221\345\205\211\347\201\257", nullptr));
        checkBox_highB->setText(QCoreApplication::translate("carWindow", "\350\277\234\345\205\211\347\201\257", nullptr));
        checkBox_rightT->setText(QCoreApplication::translate("carWindow", "\345\217\263\350\275\254\345\220\221\347\201\257", nullptr));
        checkBox_LeftRight->setText(QCoreApplication::translate("carWindow", "\345\217\214\351\227\252", nullptr));
        checkBox_brakeL->setText(QCoreApplication::translate("carWindow", "\345\210\271\350\275\246\347\201\257", nullptr));
        checkBox_leftT->setText(QCoreApplication::translate("carWindow", "\345\267\246\350\275\254\345\220\221\347\201\257", nullptr));
        checkBox_poslightF->setText(QCoreApplication::translate("carWindow", "\345\211\215\347\244\272\345\273\223\347\201\257", nullptr));
        checkBox_poslightE->setText(QCoreApplication::translate("carWindow", "\345\220\216\347\244\272\345\273\223\347\201\257", nullptr));
        checkBox_foglight->setText(QCoreApplication::translate("carWindow", "\351\233\276\347\201\257", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("carWindow", "\350\275\246\351\227\250", nullptr));
        checkBox_doorER->setText(QString());
        label_13->setText(QCoreApplication::translate("carWindow", "\345\217\263", nullptr));
        checkBox_doorEL->setText(QString());
        label_7->setText(QCoreApplication::translate("carWindow", "\345\211\215", nullptr));
        label_14->setText(QCoreApplication::translate("carWindow", "\345\220\216", nullptr));
        checkBox_doorFR->setText(QString());
        checkBox_doorFL->setText(QString());
        label_15->setText(QCoreApplication::translate("carWindow", "\345\267\246", nullptr));
        pushButton_Reset->setText(QCoreApplication::translate("carWindow", "\351\207\215\347\275\256", nullptr));
        pushButton_Left->setText(QCoreApplication::translate("carWindow", "\345\267\246\346\211\223", nullptr));
        pushButton_Right->setText(QCoreApplication::translate("carWindow", "\345\217\263\346\211\223", nullptr));
        pushButton_LeftJab->setText(QCoreApplication::translate("carWindow", "\345\267\246\347\214\233\346\211\223", nullptr));
        pushButton_RightJab->setText(QCoreApplication::translate("carWindow", "\345\217\263\347\214\233\346\211\223", nullptr));
        menu_C->setTitle(QCoreApplication::translate("carWindow", "\350\217\234\345\215\225(M)", nullptr));
        menu_H->setTitle(QCoreApplication::translate("carWindow", "\345\270\256\345\212\251(H)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class carWindow: public Ui_carWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARWINDOW_H
