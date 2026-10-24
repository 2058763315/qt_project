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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *LineEdit_1;
    QLineEdit *LineEdit;
    QGridLayout *gridLayout;
    QPushButton *pushButton_MUL;
    QPushButton *pushButton_0;
    QPushButton *pushButton_MP;
    QPushButton *pushButton_CE;
    QPushButton *pushButton_ADD;
    QPushButton *pushButton_DIV;
    QPushButton *pushButton_dian;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_SUB;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_back;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_C;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_1;
    QPushButton *pushButton_EQ;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(500, 600);
        QFont font;
        font.setPointSize(10);
        Widget->setFont(font);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Widget);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        LineEdit_1 = new QLineEdit(Widget);
        LineEdit_1->setObjectName("LineEdit_1");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font2.setPointSize(36);
        LineEdit_1->setFont(font2);
        LineEdit_1->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        LineEdit_1->setReadOnly(true);

        verticalLayout_2->addWidget(LineEdit_1);

        LineEdit = new QLineEdit(Widget);
        LineEdit->setObjectName("LineEdit");
        LineEdit->setFont(font2);
        LineEdit->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        LineEdit->setReadOnly(true);

        verticalLayout_2->addWidget(LineEdit);


        verticalLayout->addLayout(verticalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton_MUL = new QPushButton(Widget);
        pushButton_MUL->setObjectName("pushButton_MUL");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_MUL->sizePolicy().hasHeightForWidth());
        pushButton_MUL->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font3.setPointSize(24);
        pushButton_MUL->setFont(font3);

        gridLayout->addWidget(pushButton_MUL, 2, 3, 1, 1);

        pushButton_0 = new QPushButton(Widget);
        pushButton_0->setObjectName("pushButton_0");
        sizePolicy.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy);
        pushButton_0->setFont(font3);

        gridLayout->addWidget(pushButton_0, 5, 1, 1, 1);

        pushButton_MP = new QPushButton(Widget);
        pushButton_MP->setObjectName("pushButton_MP");
        sizePolicy.setHeightForWidth(pushButton_MP->sizePolicy().hasHeightForWidth());
        pushButton_MP->setSizePolicy(sizePolicy);
        pushButton_MP->setFont(font3);

        gridLayout->addWidget(pushButton_MP, 5, 0, 1, 1);

        pushButton_CE = new QPushButton(Widget);
        pushButton_CE->setObjectName("pushButton_CE");
        sizePolicy.setHeightForWidth(pushButton_CE->sizePolicy().hasHeightForWidth());
        pushButton_CE->setSizePolicy(sizePolicy);
        pushButton_CE->setFont(font3);

        gridLayout->addWidget(pushButton_CE, 0, 0, 1, 1);

        pushButton_ADD = new QPushButton(Widget);
        pushButton_ADD->setObjectName("pushButton_ADD");
        sizePolicy.setHeightForWidth(pushButton_ADD->sizePolicy().hasHeightForWidth());
        pushButton_ADD->setSizePolicy(sizePolicy);
        pushButton_ADD->setFont(font3);

        gridLayout->addWidget(pushButton_ADD, 4, 3, 1, 1);

        pushButton_DIV = new QPushButton(Widget);
        pushButton_DIV->setObjectName("pushButton_DIV");
        sizePolicy.setHeightForWidth(pushButton_DIV->sizePolicy().hasHeightForWidth());
        pushButton_DIV->setSizePolicy(sizePolicy);
        pushButton_DIV->setFont(font3);

        gridLayout->addWidget(pushButton_DIV, 0, 3, 1, 1);

        pushButton_dian = new QPushButton(Widget);
        pushButton_dian->setObjectName("pushButton_dian");
        sizePolicy.setHeightForWidth(pushButton_dian->sizePolicy().hasHeightForWidth());
        pushButton_dian->setSizePolicy(sizePolicy);
        pushButton_dian->setFont(font3);

        gridLayout->addWidget(pushButton_dian, 5, 2, 1, 1);

        pushButton_7 = new QPushButton(Widget);
        pushButton_7->setObjectName("pushButton_7");
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setFont(font3);

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName("pushButton_9");
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFont(font3);

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_SUB = new QPushButton(Widget);
        pushButton_SUB->setObjectName("pushButton_SUB");
        sizePolicy.setHeightForWidth(pushButton_SUB->sizePolicy().hasHeightForWidth());
        pushButton_SUB->setSizePolicy(sizePolicy);
        pushButton_SUB->setFont(font3);

        gridLayout->addWidget(pushButton_SUB, 3, 3, 1, 1);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font3);

        gridLayout->addWidget(pushButton_2, 4, 1, 1, 1);

        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setFont(font3);

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_back = new QPushButton(Widget);
        pushButton_back->setObjectName("pushButton_back");
        sizePolicy.setHeightForWidth(pushButton_back->sizePolicy().hasHeightForWidth());
        pushButton_back->setSizePolicy(sizePolicy);
        pushButton_back->setFont(font3);

        gridLayout->addWidget(pushButton_back, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFont(font3);

        gridLayout->addWidget(pushButton_3, 4, 2, 1, 1);

        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName("pushButton_5");
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setFont(font3);

        gridLayout->addWidget(pushButton_5, 3, 1, 1, 1);

        pushButton_C = new QPushButton(Widget);
        pushButton_C->setObjectName("pushButton_C");
        sizePolicy.setHeightForWidth(pushButton_C->sizePolicy().hasHeightForWidth());
        pushButton_C->setSizePolicy(sizePolicy);
        pushButton_C->setFont(font3);

        gridLayout->addWidget(pushButton_C, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName("pushButton_6");
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFont(font3);

        gridLayout->addWidget(pushButton_6, 3, 2, 1, 1);

        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName("pushButton_8");
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFont(font3);

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_1 = new QPushButton(Widget);
        pushButton_1->setObjectName("pushButton_1");
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);
        pushButton_1->setFont(font3);

        gridLayout->addWidget(pushButton_1, 4, 0, 1, 1);

        pushButton_EQ = new QPushButton(Widget);
        pushButton_EQ->setObjectName("pushButton_EQ");
        sizePolicy.setHeightForWidth(pushButton_EQ->sizePolicy().hasHeightForWidth());
        pushButton_EQ->setSizePolicy(sizePolicy);
        pushButton_EQ->setFont(font3);

        gridLayout->addWidget(pushButton_EQ, 5, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\350\256\241\347\256\227\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\254\242\350\277\216\344\275\277\347\224\250\350\256\241\347\256\227\345\231\250", nullptr));
        LineEdit_1->setText(QCoreApplication::translate("Widget", "0", nullptr));
        LineEdit->setText(QCoreApplication::translate("Widget", "0", nullptr));
        pushButton_MUL->setText(QCoreApplication::translate("Widget", "x", nullptr));
        pushButton_0->setText(QCoreApplication::translate("Widget", "0", nullptr));
        pushButton_MP->setText(QCoreApplication::translate("Widget", "+/-", nullptr));
        pushButton_CE->setText(QCoreApplication::translate("Widget", "CE", nullptr));
        pushButton_ADD->setText(QCoreApplication::translate("Widget", "+", nullptr));
        pushButton_DIV->setText(QCoreApplication::translate("Widget", "/", nullptr));
        pushButton_dian->setText(QCoreApplication::translate("Widget", ".", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "7", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "9", nullptr));
        pushButton_SUB->setText(QCoreApplication::translate("Widget", "-", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "2", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "4", nullptr));
        pushButton_back->setText(QCoreApplication::translate("Widget", "Back", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "3", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "5", nullptr));
        pushButton_C->setText(QCoreApplication::translate("Widget", "C", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "6", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "8", nullptr));
        pushButton_1->setText(QCoreApplication::translate("Widget", "1", nullptr));
        pushButton_EQ->setText(QCoreApplication::translate("Widget", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
