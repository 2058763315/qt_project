#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

    void refreshData();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_exe_clicked();

private:
    Ui::Widget *ui;

    QSqlDatabase db;
};
#endif // WIDGET_H
