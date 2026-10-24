#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QTimerEvent>
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

    void timerEvent(QTimerEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_pushButton_prev_clicked();
    void on_pushButton_next_clicked();
    void on_pushButton_auto_clicked();
    void on_pushButton_stop_clicked();

private:
    Ui::Widget *ui;

    int timerID;
    QStringList playList;
    size_t pos;
    bool playFlag = false;
};
#endif // WIDGET_H
