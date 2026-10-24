/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->setWindowModality(Qt::WindowModality::WindowModal);
        Dialog->resize(400, 300);
        QFont font;
        font.setPointSize(16);
        Dialog->setFont(font);
        progressBar = new QProgressBar(Dialog);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(20, 175, 381, 21));
        progressBar->setValue(0);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 80, 191, 61));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 220, 231, 51));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\345\274\200\345\247\213\346\243\200\346\265\213", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\347\255\211\345\276\205\346\243\200\346\265\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
