#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>   // ← 加这一行
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

    void sendCommand(const QString &cmd);
    void handleLine(const QByteArray &line);
    void setStatusText(const QString &text, const QString &color);  // 统一设置状态
private slots:
    void onSerialReadyRead();

    void on_checkBox_toggled(bool checked);

    void on_checkBox_2_toggled(bool checked);

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QByteArray m_rxBuffer;     // 用于拆行
    QSerialPort *m_serial;

    QTimer     *m_statusTimer;
};
#endif // WIDGET_H
