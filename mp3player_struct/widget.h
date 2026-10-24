#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QCloseEvent>
#include <ctime>
#include <cstdlib>

#define DFLPATH "D:/音乐/music"
#define SETTINGFILE "setting.dat"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

struct SongInfo {
    QString fullPath;
    QString displayName;

    SongInfo() {}
    SongInfo(const QString &path) {
        fullPath = path;
        QFileInfo info(path);
        QString name = info.fileName();
        int dotIndex = name.lastIndexOf('.');
        if (dotIndex != -1) {
            displayName = name.left(dotIndex);
        } else {
            displayName = name;
        }
    }
};

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
    void refreshModel();
    QString getBaseFileName(const QString &filePath);

private slots:
    void on_verticalSlider_sliderMoved(int position);
    void on_horizontalSlider_sliderMoved(int position);

    void positionChangedSlot(qint64 pos);
    void durationChangedSlot(qint64 dur);

    void on_pushButtonPlay_clicked();
    void on_pushButtonPause_clicked();
    void on_pushButtonStop_clicked();

    void on_pushButtonCancel_clicked();
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

    void on_horizontalSlider_sliderReleased();

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
    QList<SongInfo> songData;           // 存储结构体
    QStandardItemModel* model;
};
#endif // WIDGET_H
