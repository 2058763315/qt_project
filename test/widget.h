#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>
#include <QStringListModel>
#include <QInputDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <ctime>
#include <cstdlib>

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

    QString timeStr(qint64 num);

private slots:

    void positionChangedSlot(qint64 pos);
    void durationChangedSlot(qint64 dur);
    // void mousePressEvent(QMouseEvent* event) override;
    // void mouseReleaseEvent(QMouseEvent* event) override;
    // void mouseDoubleClickEvent(QMouseEvent* event) override;
    // void mouseMoveEvent(QMouseEvent* event) override;

    // void keyPressEvent(QKeyEvent* event) override;
    // void keyReleaseEvent(QKeyEvent* event) override;

    void closeEvent(QCloseEvent* event) override;

    void on_comboBox_currentIndexChanged(int index);

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void onOpenNewWindow();
    void on_pushButton_9_clicked();

    void on_dial_sliderMoved(int position);

    void on_pushButton_14_clicked();

    void on_dial_sliderReleased();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_sliderReleased();

    void on_pushButton_15_clicked();

private:
    Ui::Widget *ui;

    QStringList data;
    QStringListModel* model;

    bool ok;

    QMediaPlayer *player;
    QAudioOutput* audio;
    QVideoWidget *videoWidget;
};
#endif // WIDGET_H
