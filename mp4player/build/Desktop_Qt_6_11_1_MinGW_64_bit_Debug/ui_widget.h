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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListView *listView;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider;
    QLabel *labelCurPos;
    QLabel *label;
    QLabel *labelAllPos;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonPlayOrPause;
    QPushButton *pushButtonPrev;
    QPushButton *pushButtonBack;
    QPushButton *pushButtonFront;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDel;
    QPushButton *pushButtonUp;
    QComboBox *comboBox;
    QPushButton *pushButtonMute;
    QPushButton *pushButtonPosing;
    QPushButton *pushButtonImport;
    QPushButton *pushButtonExport;
    QPushButton *pushButtonDown;
    QPushButton *pushButtonClear;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QSlider *verticalSlider;
    QLabel *labelVolume;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1200, 800);
        QFont font;
        font.setPointSize(14);
        Widget->setFont(font);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        listView = new QListView(Widget);
        listView->setObjectName("listView");
        listView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_2->addWidget(listView);


        horizontalLayout_5->addLayout(verticalLayout_2);

        horizontalLayout_5->setStretch(0, 4);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        labelCurPos = new QLabel(Widget);
        labelCurPos->setObjectName("labelCurPos");
        labelCurPos->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelCurPos);

        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label);

        labelAllPos = new QLabel(Widget);
        labelAllPos->setObjectName("labelAllPos");
        labelAllPos->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelAllPos);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButtonStop = new QPushButton(Widget);
        pushButtonStop->setObjectName("pushButtonStop");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonStop->sizePolicy().hasHeightForWidth());
        pushButtonStop->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonStop, 1, 0, 1, 1);

        pushButtonPlayOrPause = new QPushButton(Widget);
        pushButtonPlayOrPause->setObjectName("pushButtonPlayOrPause");
        sizePolicy.setHeightForWidth(pushButtonPlayOrPause->sizePolicy().hasHeightForWidth());
        pushButtonPlayOrPause->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonPlayOrPause, 0, 0, 1, 1);

        pushButtonPrev = new QPushButton(Widget);
        pushButtonPrev->setObjectName("pushButtonPrev");
        sizePolicy.setHeightForWidth(pushButtonPrev->sizePolicy().hasHeightForWidth());
        pushButtonPrev->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonPrev, 1, 1, 1, 1);

        pushButtonBack = new QPushButton(Widget);
        pushButtonBack->setObjectName("pushButtonBack");
        sizePolicy.setHeightForWidth(pushButtonBack->sizePolicy().hasHeightForWidth());
        pushButtonBack->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonBack, 0, 1, 1, 1);

        pushButtonFront = new QPushButton(Widget);
        pushButtonFront->setObjectName("pushButtonFront");
        sizePolicy.setHeightForWidth(pushButtonFront->sizePolicy().hasHeightForWidth());
        pushButtonFront->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonFront, 0, 2, 1, 1);

        pushButtonNext = new QPushButton(Widget);
        pushButtonNext->setObjectName("pushButtonNext");
        sizePolicy.setHeightForWidth(pushButtonNext->sizePolicy().hasHeightForWidth());
        pushButtonNext->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonNext, 1, 2, 1, 1);

        pushButtonAdd = new QPushButton(Widget);
        pushButtonAdd->setObjectName("pushButtonAdd");
        sizePolicy.setHeightForWidth(pushButtonAdd->sizePolicy().hasHeightForWidth());
        pushButtonAdd->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonAdd, 0, 3, 1, 1);

        pushButtonDel = new QPushButton(Widget);
        pushButtonDel->setObjectName("pushButtonDel");
        sizePolicy.setHeightForWidth(pushButtonDel->sizePolicy().hasHeightForWidth());
        pushButtonDel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonDel, 1, 3, 1, 1);

        pushButtonUp = new QPushButton(Widget);
        pushButtonUp->setObjectName("pushButtonUp");
        sizePolicy.setHeightForWidth(pushButtonUp->sizePolicy().hasHeightForWidth());
        pushButtonUp->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonUp, 1, 4, 1, 1);

        comboBox = new QComboBox(Widget);
        comboBox->setObjectName("comboBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox, 0, 4, 1, 1);

        pushButtonMute = new QPushButton(Widget);
        pushButtonMute->setObjectName("pushButtonMute");
        sizePolicy.setHeightForWidth(pushButtonMute->sizePolicy().hasHeightForWidth());
        pushButtonMute->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonMute, 0, 5, 1, 1);

        pushButtonPosing = new QPushButton(Widget);
        pushButtonPosing->setObjectName("pushButtonPosing");
        sizePolicy.setHeightForWidth(pushButtonPosing->sizePolicy().hasHeightForWidth());
        pushButtonPosing->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonPosing, 1, 5, 1, 1);

        pushButtonImport = new QPushButton(Widget);
        pushButtonImport->setObjectName("pushButtonImport");
        sizePolicy.setHeightForWidth(pushButtonImport->sizePolicy().hasHeightForWidth());
        pushButtonImport->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonImport, 2, 0, 1, 2);

        pushButtonExport = new QPushButton(Widget);
        pushButtonExport->setObjectName("pushButtonExport");
        sizePolicy.setHeightForWidth(pushButtonExport->sizePolicy().hasHeightForWidth());
        pushButtonExport->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonExport, 2, 2, 1, 2);

        pushButtonDown = new QPushButton(Widget);
        pushButtonDown->setObjectName("pushButtonDown");
        sizePolicy.setHeightForWidth(pushButtonDown->sizePolicy().hasHeightForWidth());
        pushButtonDown->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonDown, 2, 4, 1, 1);

        pushButtonClear = new QPushButton(Widget);
        pushButtonClear->setObjectName("pushButtonClear");
        sizePolicy.setHeightForWidth(pushButtonClear->sizePolicy().hasHeightForWidth());
        pushButtonClear->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonClear, 2, 5, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalSlider = new QSlider(Widget);
        verticalSlider->setObjectName("verticalSlider");
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        verticalSlider->setFont(font2);
        verticalSlider->setMaximum(100);
        verticalSlider->setValue(100);
        verticalSlider->setOrientation(Qt::Orientation::Vertical);

        horizontalLayout_3->addWidget(verticalSlider);


        verticalLayout_4->addLayout(horizontalLayout_3);

        labelVolume = new QLabel(Widget);
        labelVolume->setObjectName("labelVolume");
        labelVolume->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(labelVolume);


        horizontalLayout_4->addLayout(verticalLayout_4);

        horizontalLayout_4->setStretch(0, 12);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_3->setStretch(0, 5);
        verticalLayout_3->setStretch(1, 2);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "mp4\346\222\255\346\224\276\345\231\250", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        labelCurPos->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        label->setText(QCoreApplication::translate("Widget", "/", nullptr));
        labelAllPos->setText(QCoreApplication::translate("Widget", "00:00", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
        pushButtonPlayOrPause->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276", nullptr));
        pushButtonPrev->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\246\226", nullptr));
        pushButtonBack->setText(QCoreApplication::translate("Widget", "\345\277\253\350\277\233", nullptr));
        pushButtonFront->setText(QCoreApplication::translate("Widget", "\345\277\253\351\200\200", nullptr));
        pushButtonNext->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\246\226", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240", nullptr));
        pushButtonDel->setText(QCoreApplication::translate("Widget", "\345\210\240\351\231\244", nullptr));
        pushButtonUp->setText(QCoreApplication::translate("Widget", "\344\270\212\347\247\273", nullptr));
        pushButtonMute->setText(QCoreApplication::translate("Widget", "\351\235\231\351\237\263", nullptr));
        pushButtonPosing->setText(QCoreApplication::translate("Widget", "\345\256\232\344\275\215", nullptr));
        pushButtonImport->setText(QCoreApplication::translate("Widget", "\345\257\274\345\205\245\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        pushButtonExport->setText(QCoreApplication::translate("Widget", "\345\257\274\345\207\272\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        pushButtonDown->setText(QCoreApplication::translate("Widget", "\344\270\213\347\247\273", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        labelVolume->setText(QCoreApplication::translate("Widget", "100", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
