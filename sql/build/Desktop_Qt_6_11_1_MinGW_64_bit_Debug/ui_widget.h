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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QSpinBox *spinBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_add;
    QWidget *tab_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_exe;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(500, 600);
        QFont font;
        font.setPointSize(14);
        Widget->setFont(font);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(Widget);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        spinBox = new QSpinBox(tab);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(90, 20, 241, 40));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 20, 40));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 71, 40));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 70, 241, 40));
        pushButton_add = new QPushButton(tab);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(360, 70, 100, 40));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        textEdit = new QTextEdit(tab_2);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 0, 451, 61));
        pushButton_exe = new QPushButton(tab_2);
        pushButton_exe->setObjectName("pushButton_exe");
        pushButton_exe->setGeometry(QRect(360, 70, 100, 40));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 2);

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "id", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "name", nullptr));
        pushButton_add->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "Tab 1", nullptr));
        pushButton_exe->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
