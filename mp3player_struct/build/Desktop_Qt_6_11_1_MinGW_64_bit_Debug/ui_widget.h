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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QPushButton *pushButtonPlay;
    QPushButton *pushButtonBack;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonMute;
    QLabel *labelVolume;
    QLabel *labelMute;
    QPushButton *pushButtonFront;
    QLabel *labelCurPos;
    QLabel *labelAllPos;
    QLabel *label;
    QComboBox *comboBox;
    QListView *listView;
    QPushButton *pushButtonPrev;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonUp;
    QPushButton *pushButtonDown;
    QPushButton *pushButtonImport;
    QPushButton *pushButtonExport;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonPosing;
    QPushButton *pushButtonPause;
    QPushButton *pushButtonCancel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(792, 712);
        QFont font;
        font.setPointSize(14);
        Widget->setFont(font);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(40, 500, 551, 22));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        verticalSlider = new QSlider(Widget);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setGeometry(QRect(690, 540, 20, 111));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        verticalSlider->setFont(font1);
        verticalSlider->setMaximum(100);
        verticalSlider->setValue(100);
        verticalSlider->setOrientation(Qt::Orientation::Vertical);
        pushButtonPlay = new QPushButton(Widget);
        pushButtonPlay->setObjectName("pushButtonPlay");
        pushButtonPlay->setGeometry(QRect(20, 530, 180, 50));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonPlay->sizePolicy().hasHeightForWidth());
        pushButtonPlay->setSizePolicy(sizePolicy);
        pushButtonBack = new QPushButton(Widget);
        pushButtonBack->setObjectName("pushButtonBack");
        pushButtonBack->setGeometry(QRect(230, 530, 181, 50));
        sizePolicy.setHeightForWidth(pushButtonBack->sizePolicy().hasHeightForWidth());
        pushButtonBack->setSizePolicy(sizePolicy);
        pushButtonStop = new QPushButton(Widget);
        pushButtonStop->setObjectName("pushButtonStop");
        pushButtonStop->setGeometry(QRect(20, 590, 180, 50));
        sizePolicy.setHeightForWidth(pushButtonStop->sizePolicy().hasHeightForWidth());
        pushButtonStop->setSizePolicy(sizePolicy);
        pushButtonMute = new QPushButton(Widget);
        pushButtonMute->setObjectName("pushButtonMute");
        pushButtonMute->setGeometry(QRect(630, 310, 140, 50));
        sizePolicy.setHeightForWidth(pushButtonMute->sizePolicy().hasHeightForWidth());
        pushButtonMute->setSizePolicy(sizePolicy);
        labelVolume = new QLabel(Widget);
        labelVolume->setObjectName("labelVolume");
        labelVolume->setGeometry(QRect(658, 660, 80, 30));
        labelVolume->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelMute = new QLabel(Widget);
        labelMute->setObjectName("labelMute");
        labelMute->setGeometry(QRect(658, 660, 80, 30));
        labelMute->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButtonFront = new QPushButton(Widget);
        pushButtonFront->setObjectName("pushButtonFront");
        pushButtonFront->setGeometry(QRect(440, 530, 180, 50));
        sizePolicy.setHeightForWidth(pushButtonFront->sizePolicy().hasHeightForWidth());
        pushButtonFront->setSizePolicy(sizePolicy);
        labelCurPos = new QLabel(Widget);
        labelCurPos->setObjectName("labelCurPos");
        labelCurPos->setGeometry(QRect(610, 500, 70, 20));
        labelCurPos->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelAllPos = new QLabel(Widget);
        labelAllPos->setObjectName("labelAllPos");
        labelAllPos->setGeometry(QRect(680, 500, 70, 20));
        labelAllPos->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(670, 500, 20, 20));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(630, 250, 140, 50));
        listView = new QListView(Widget);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(20, 10, 601, 471));
        listView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        pushButtonPrev = new QPushButton(Widget);
        pushButtonPrev->setObjectName("pushButtonPrev");
        pushButtonPrev->setGeometry(QRect(230, 590, 180, 50));
        sizePolicy.setHeightForWidth(pushButtonPrev->sizePolicy().hasHeightForWidth());
        pushButtonPrev->setSizePolicy(sizePolicy);
        pushButtonNext = new QPushButton(Widget);
        pushButtonNext->setObjectName("pushButtonNext");
        pushButtonNext->setGeometry(QRect(440, 590, 180, 50));
        sizePolicy.setHeightForWidth(pushButtonNext->sizePolicy().hasHeightForWidth());
        pushButtonNext->setSizePolicy(sizePolicy);
        pushButtonAdd = new QPushButton(Widget);
        pushButtonAdd->setObjectName("pushButtonAdd");
        pushButtonAdd->setGeometry(QRect(630, 10, 140, 50));
        sizePolicy.setHeightForWidth(pushButtonAdd->sizePolicy().hasHeightForWidth());
        pushButtonAdd->setSizePolicy(sizePolicy);
        pushButtonDel = new QPushButton(Widget);
        pushButtonDel->setObjectName("pushButtonDel");
        pushButtonDel->setGeometry(QRect(630, 70, 140, 50));
        sizePolicy.setHeightForWidth(pushButtonDel->sizePolicy().hasHeightForWidth());
        pushButtonDel->setSizePolicy(sizePolicy);
        pushButtonUp = new QPushButton(Widget);
        pushButtonUp->setObjectName("pushButtonUp");
        pushButtonUp->setGeometry(QRect(630, 130, 140, 50));
        sizePolicy.setHeightForWidth(pushButtonUp->sizePolicy().hasHeightForWidth());
        pushButtonUp->setSizePolicy(sizePolicy);
        pushButtonDown = new QPushButton(Widget);
        pushButtonDown->setObjectName("pushButtonDown");
        pushButtonDown->setGeometry(QRect(630, 190, 140, 50));
        sizePolicy.setHeightForWidth(pushButtonDown->sizePolicy().hasHeightForWidth());
        pushButtonDown->setSizePolicy(sizePolicy);
        pushButtonImport = new QPushButton(Widget);
        pushButtonImport->setObjectName("pushButtonImport");
        pushButtonImport->setGeometry(QRect(19, 650, 290, 50));
        sizePolicy.setHeightForWidth(pushButtonImport->sizePolicy().hasHeightForWidth());
        pushButtonImport->setSizePolicy(sizePolicy);
        pushButtonExport = new QPushButton(Widget);
        pushButtonExport->setObjectName("pushButtonExport");
        pushButtonExport->setGeometry(QRect(330, 650, 290, 50));
        sizePolicy.setHeightForWidth(pushButtonExport->sizePolicy().hasHeightForWidth());
        pushButtonExport->setSizePolicy(sizePolicy);
        pushButtonClear = new QPushButton(Widget);
        pushButtonClear->setObjectName("pushButtonClear");
        pushButtonClear->setGeometry(QRect(630, 370, 140, 50));
        sizePolicy.setHeightForWidth(pushButtonClear->sizePolicy().hasHeightForWidth());
        pushButtonClear->setSizePolicy(sizePolicy);
        pushButtonPosing = new QPushButton(Widget);
        pushButtonPosing->setObjectName("pushButtonPosing");
        pushButtonPosing->setGeometry(QRect(630, 430, 140, 50));
        sizePolicy.setHeightForWidth(pushButtonPosing->sizePolicy().hasHeightForWidth());
        pushButtonPosing->setSizePolicy(sizePolicy);
        pushButtonPause = new QPushButton(Widget);
        pushButtonPause->setObjectName("pushButtonPause");
        pushButtonPause->setGeometry(QRect(20, 530, 180, 50));
        sizePolicy.setHeightForWidth(pushButtonPause->sizePolicy().hasHeightForWidth());
        pushButtonPause->setSizePolicy(sizePolicy);
        pushButtonCancel = new QPushButton(Widget);
        pushButtonCancel->setObjectName("pushButtonCancel");
        pushButtonCancel->setGeometry(QRect(630, 310, 140, 50));
        sizePolicy.setHeightForWidth(pushButtonCancel->sizePolicy().hasHeightForWidth());
        pushButtonCancel->setSizePolicy(sizePolicy);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "mp3\346\222\255\346\224\276\345\231\250", nullptr));
        pushButtonPlay->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276", nullptr));
        pushButtonBack->setText(QCoreApplication::translate("Widget", "\345\277\253\350\277\233", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
        pushButtonMute->setText(QCoreApplication::translate("Widget", "\351\235\231\351\237\263", nullptr));
        labelVolume->setText(QCoreApplication::translate("Widget", "100", nullptr));
        labelMute->setText(QCoreApplication::translate("Widget", "\351\235\231\351\237\263", nullptr));
        pushButtonFront->setText(QCoreApplication::translate("Widget", "\345\277\253\351\200\200", nullptr));
        labelCurPos->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        labelAllPos->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        label->setText(QCoreApplication::translate("Widget", "/", nullptr));
        pushButtonPrev->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\246\226", nullptr));
        pushButtonNext->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\246\226", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240", nullptr));
        pushButtonDel->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        pushButtonUp->setText(QCoreApplication::translate("Widget", "\344\270\212\347\247\273", nullptr));
        pushButtonDown->setText(QCoreApplication::translate("Widget", "\344\270\213\347\247\273", nullptr));
        pushButtonImport->setText(QCoreApplication::translate("Widget", "\345\257\274\345\205\245\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        pushButtonExport->setText(QCoreApplication::translate("Widget", "\345\257\274\345\207\272\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        pushButtonPosing->setText(QCoreApplication::translate("Widget", "\345\256\232\344\275\215", nullptr));
        pushButtonPause->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("Widget", "\350\247\243\351\231\244\351\235\231\351\237\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
