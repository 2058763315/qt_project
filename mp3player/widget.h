#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QStringListModel>
#include <QCloseEvent>
#include <ctime>
#include <cstdlib>
#include <QMediaDevices>
#include <QAudioDevice>

#define DFLPATH "D:/音乐/music"
#define SETTINGFILE "setting.dat"

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

    enum PLAT_MODE{LIST_PLAY, LIST_LOOP, SING_LOOP, RAND_PLAY};
private:
    QString timeStr(qint64 num);
    void playSong();

    void saveList(const QString& path);
    void readList(const QString& path);

    void closeEvent(QCloseEvent* event) override;

    void handleAudioOutputsChanged();
    void makeFile();

private slots:
    void on_verticalSlider_sliderMoved(int position);
    void on_verticalSlider_sliderReleased();
    void on_horizontalSlider_sliderMoved(int position);
    void on_horizontalSlider_sliderReleased();

    void positionChangedSlot(qint64 pos);
    void durationChangedSlot(qint64 dur);

    void on_pushButtonPlayOrPause_clicked();
    void on_pushButtonStop_clicked();

    void on_pushButtonMute_clicked();

    void mutedChangedSlot(bool isMute);
    void playbackStateChangedSlot(QMediaPlayer::PlaybackState state);

    void mediaStatusChangedSlot(QMediaPlayer::MediaStatus status);

    void on_pushButtonBack_clicked();
    void on_pushButtonFront_clicked();

    void on_pushButtonAdd_clicked();
    void on_pushButtonDel_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_pushButtonPrev_clicked();
    void on_pushButtonNext_clicked();

    void on_pushButtonUp_clicked();
    void on_pushButtonDown_clicked();

    void on_pushButtonImport_clicked();
    void on_pushButtonExport_clicked();

    void on_pushButtonPosing_clicked();
    void on_pushButtonClear_clicked();

private:
    Ui::Widget *ui;

    QMediaPlayer* player;
    QAudioOutput* audio;

    int pos = -1;
    int currentPos = -1;
    bool isPlaying = false;
    bool isMuteing = false;
    int currentVolume = 100;
    QStringList songData;
    QStringListModel* model;

    QMediaDevices mediaDevices;
};
#endif // WIDGET_H
