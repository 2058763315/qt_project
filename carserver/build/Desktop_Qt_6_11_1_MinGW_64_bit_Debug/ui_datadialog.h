/********************************************************************************
** Form generated from reading UI file 'datadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATADIALOG_H
#define UI_DATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dataDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *dataDialog)
    {
        if (dataDialog->objectName().isEmpty())
            dataDialog->setObjectName("dataDialog");
        dataDialog->resize(1300, 800);
        QFont font;
        font.setPointSize(14);
        dataDialog->setFont(font);
        verticalLayout = new QVBoxLayout(dataDialog);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(dataDialog);
        tableWidget->setObjectName("tableWidget");
        QFont font1;
        font1.setPointSize(10);
        tableWidget->setFont(font1);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(dataDialog);

        QMetaObject::connectSlotsByName(dataDialog);
    } // setupUi

    void retranslateUi(QDialog *dataDialog)
    {
        dataDialog->setWindowTitle(QCoreApplication::translate("dataDialog", "\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dataDialog: public Ui_dataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATADIALOG_H
