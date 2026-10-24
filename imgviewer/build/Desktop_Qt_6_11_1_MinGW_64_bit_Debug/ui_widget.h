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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_prev;
    QPushButton *pushButton_next;
    QPushButton *pushButton_auto;
    QPushButton *pushButton_stop;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(890, 590);
        Widget->setMinimumSize(QSize(890, 590));
        QFont font;
        font.setPointSize(12);
        Widget->setFont(font);
        pushButton_prev = new QPushButton(Widget);
        pushButton_prev->setObjectName("pushButton_prev");
        pushButton_prev->setGeometry(QRect(80, 520, 150, 50));
        pushButton_next = new QPushButton(Widget);
        pushButton_next->setObjectName("pushButton_next");
        pushButton_next->setGeometry(QRect(630, 520, 150, 50));
        pushButton_auto = new QPushButton(Widget);
        pushButton_auto->setObjectName("pushButton_auto");
        pushButton_auto->setGeometry(QRect(360, 520, 150, 50));
        pushButton_stop = new QPushButton(Widget);
        pushButton_stop->setObjectName("pushButton_stop");
        pushButton_stop->setGeometry(QRect(360, 520, 150, 50));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 800, 450));
        label->setScaledContents(true);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\233\276\347\211\207\351\230\205\350\257\273\345\231\250", nullptr));
        pushButton_prev->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\345\274\240", nullptr));
        pushButton_next->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\345\274\240", nullptr));
        pushButton_auto->setText(QCoreApplication::translate("Widget", "\350\207\252\345\212\250\346\222\255\346\224\276", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\346\222\255\346\224\276", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
