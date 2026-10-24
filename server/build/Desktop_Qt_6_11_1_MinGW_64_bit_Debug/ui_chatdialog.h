/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <chattextedit.h>

QT_BEGIN_NAMESPACE

class Ui_chatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    chatTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonSend;

    void setupUi(QDialog *chatDialog)
    {
        if (chatDialog->objectName().isEmpty())
            chatDialog->setObjectName("chatDialog");
        chatDialog->resize(500, 600);
        QFont font;
        font.setPointSize(16);
        chatDialog->setFont(font);
        verticalLayout = new QVBoxLayout(chatDialog);
        verticalLayout->setObjectName("verticalLayout");
        listWidget = new QListWidget(chatDialog);
        listWidget->setObjectName("listWidget");
        listWidget->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        verticalLayout->addWidget(listWidget);

        textEdit = new chatTextEdit(chatDialog);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonClear = new QPushButton(chatDialog);
        pushButtonClear->setObjectName("pushButtonClear");

        horizontalLayout->addWidget(pushButtonClear);

        pushButtonSend = new QPushButton(chatDialog);
        pushButtonSend->setObjectName("pushButtonSend");

        horizontalLayout->addWidget(pushButtonSend);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);

        retranslateUi(chatDialog);

        QMetaObject::connectSlotsByName(chatDialog);
    } // setupUi

    void retranslateUi(QDialog *chatDialog)
    {
        chatDialog->setWindowTitle(QCoreApplication::translate("chatDialog", "Dialog", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("chatDialog", "\346\270\205\347\251\272", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("chatDialog", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatDialog: public Ui_chatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H
