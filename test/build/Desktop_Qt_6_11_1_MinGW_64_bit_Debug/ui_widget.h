/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QListView *listView;
    QListWidget *listWidget;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QDial *dial;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLabel *label_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton;
    QPushButton *pushButton_14;
    QSlider *horizontalSlider;
    QLabel *labelCurPos;
    QLabel *label_8;
    QLabel *labelAllPos;
    QPushButton *pushButton_15;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->setEnabled(true);
        Widget->resize(1000, 861);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        Widget->setFont(font);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 511, 291));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 320, 786, 321));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        listView = new QListView(layoutWidget1);
        listView->setObjectName("listView");
        QFont font1;
        font1.setPointSize(16);
        listView->setFont(font1);

        horizontalLayout_2->addWidget(listView);

        listWidget = new QListWidget(layoutWidget1);
        listWidget->setObjectName("listWidget");
        listWidget->setFont(font1);

        horizontalLayout_2->addWidget(listWidget);

        tableWidget = new QTableWidget(layoutWidget1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setFont(font1);

        horizontalLayout_2->addWidget(tableWidget);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setFont(font1);

        horizontalLayout->addWidget(lineEdit);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font1);

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_1 = new QPushButton(layoutWidget1);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setFont(font1);

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setFont(font1);

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget1);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setFont(font1);

        gridLayout->addWidget(pushButton_8, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 4);
        verticalLayout_2->setStretch(1, 1);
        dial = new QDial(Widget);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(120, 680, 161, 161));
        dial->setWrapping(true);
        dial->setNotchesVisible(false);
        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(820, 10, 173, 839));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setFont(font1);

        verticalLayout->addWidget(comboBox);

        spinBox = new QSpinBox(layoutWidget2);
        spinBox->setObjectName("spinBox");
        spinBox->setFont(font1);

        verticalLayout->addWidget(spinBox);

        label_1 = new QLabel(layoutWidget2);
        label_1->setObjectName("label_1");
        label_1->setFont(font1);

        verticalLayout->addWidget(label_1);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(layoutWidget2);
        label->setObjectName("label");
        label->setFont(font1);

        horizontalLayout_3->addWidget(label);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);

        horizontalLayout_3->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName("label_10");
        label_10->setFont(font1);

        horizontalLayout_4->addWidget(label_10);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);

        horizontalLayout_4->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_4);

        pushButton_4 = new QPushButton(layoutWidget2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setFont(font1);

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(layoutWidget2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setFont(font1);

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(layoutWidget2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setFont(font1);

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(layoutWidget2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setFont(font1);

        verticalLayout->addWidget(pushButton_7);

        pushButton_9 = new QPushButton(layoutWidget2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setFont(font1);

        verticalLayout->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(layoutWidget2);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setFont(font1);

        verticalLayout->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(layoutWidget2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setFont(font1);

        verticalLayout->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(layoutWidget2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setFont(font1);

        verticalLayout->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(layoutWidget2);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setFont(font1);

        verticalLayout->addWidget(pushButton_13);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName("pushButton");
        pushButton->setFont(font1);

        verticalLayout->addWidget(pushButton);

        pushButton_14 = new QPushButton(Widget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(500, 740, 161, 43));
        pushButton_14->setFont(font1);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(40, 660, 451, 22));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        labelCurPos = new QLabel(Widget);
        labelCurPos->setObjectName("labelCurPos");
        labelCurPos->setGeometry(QRect(520, 660, 70, 20));
        QFont font2;
        font2.setPointSize(14);
        labelCurPos->setFont(font2);
        labelCurPos->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8 = new QLabel(Widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(580, 660, 20, 20));
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelAllPos = new QLabel(Widget);
        labelAllPos->setObjectName("labelAllPos");
        labelAllPos->setGeometry(QRect(590, 660, 70, 20));
        labelAllPos->setFont(font2);
        labelAllPos->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_15 = new QPushButton(Widget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(500, 790, 161, 43));
        pushButton_15->setFont(font1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "List Widget", nullptr));
        pushButton_1->setText(QCoreApplication::translate("Widget", "List View", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240\350\241\250\346\240\274", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "\350\213\217\345\267\236", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "\346\267\261\345\234\263", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Widget", "\346\227\240\351\224\241", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Widget", "\346\210\220\351\203\275", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Widget", "\351\225\277\346\262\231", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("Widget", "\346\235\255\345\267\236", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("Widget", "\345\244\251\346\264\245", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("Widget", "\344\270\212\346\265\267", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("Widget", "\345\214\227\344\272\254", nullptr));

        label_1->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\237\216\345\270\202\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\346\227\240", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\346\227\240", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "getInt\346\214\211\351\222\256", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "getItem\346\214\211\351\222\256", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "getText\346\226\207\346\234\254", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "getText\345\257\206\347\240\201", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "\345\244\232\350\241\214\347\274\226\350\276\221\346\241\206", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
        pushButton_12->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
        pushButton_13->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\351\200\211\346\213\251\346\226\207\344\273\266\346\214\211\351\222\256", nullptr));
        pushButton_14->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\346\226\260\347\252\227\345\217\243", nullptr));
        labelCurPos->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "/", nullptr));
        labelAllPos->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        pushButton_15->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\346\226\260\347\252\227\345\217\2432", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
