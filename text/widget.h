#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>
#include <QTimer>

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

    void onTextChanged(const QString &text);
    void updateOffset();
    int getTextWidth() const; // 计算当前文字宽度

private slots:
    void on_pushButton_clicked();

private:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Widget *ui;
    QString m_text;          // 当前显示的文字
    int m_offset;            // 水平偏移量（像素）
    QTimer *m_timer;
};
#endif // WIDGET_H
