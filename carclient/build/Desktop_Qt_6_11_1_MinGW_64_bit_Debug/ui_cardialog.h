/********************************************************************************
** Form generated from reading UI file 'cardialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDIALOG_H
#define UI_CARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_carDialog
{
public:

    void setupUi(QDialog *carDialog)
    {
        if (carDialog->objectName().isEmpty())
            carDialog->setObjectName("carDialog");
        carDialog->resize(693, 445);

        retranslateUi(carDialog);

        QMetaObject::connectSlotsByName(carDialog);
    } // setupUi

    void retranslateUi(QDialog *carDialog)
    {
        carDialog->setWindowTitle(QCoreApplication::translate("carDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class carDialog: public Ui_carDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDIALOG_H
