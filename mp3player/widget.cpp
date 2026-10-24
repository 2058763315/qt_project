#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , player(new QMediaPlayer)
    , audio(new QAudioOutput)
    , model(new QStringListModel)
{
    ui->setupUi(this);
    makeFile();
    connect(player, & QMediaPlayer::positionChanged, this, &Widget::positionChangedSlot);
    connect(player, & QMediaPlayer::durationChanged, this, &Widget::durationChangedSlot);
    connect(audio, & QAudioOutput::mutedChanged, this, &Widget::mutedChangedSlot);
    connect(player, & QMediaPlayer::playbackStateChanged, this, &Widget::playbackStateChangedSlot);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &Widget::mediaStatusChangedSlot);
    connect(&mediaDevices, &QMediaDevices::audioOutputsChanged, this, &Widget::handleAudioOutputsChanged);

    ui->listView->setModel(model);
    QStringList modes = {"顺序播放", "列表循环", "单曲循环", "随机播放"};
    for (int i = 0; i < modes.size(); ++i) {
        ui->comboBox->addItem(modes[i]);
        ui->comboBox->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    readList(SETTINGFILE);

    srand(time(NULL));
    audio->setVolume(currentVolume / 100.0);
    ui->verticalSlider->setSliderPosition(currentVolume);
    ui->labelVolume->setText(QString::number(currentVolume));

    player->setAudioOutput(audio);
}

Widget::~Widget()
{
    delete model;
    delete audio;
    delete player;
    delete ui;
}

void Widget::makeFile()
{
    QFile file(SETTINGFILE);
    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly)) {
            file.close();
        }
    }
}

QString Widget::timeStr(qint64 num)
{
    num /= 1000;
    return QString("%1:%2").arg(num / 60, 2, 10, '0').arg(num % 60, 2, 10, '0');
}

void Widget::playSong()
{
    if(pos != currentPos)
    {
        player->setSource(QUrl(songData[pos]));
        currentPos = pos;
    }
    player->play();
    isPlaying = true;
    ui->listView->setCurrentIndex(model->index(pos));
}

void Widget::on_verticalSlider_sliderMoved(int position)
{
    audio->setVolume(position / 100.0);
    ui->labelVolume->setText(QString::number(position));
    audio->setMuted(false);
    isMuteing = false;
    currentVolume = pos;
}

void Widget::on_verticalSlider_sliderReleased()
{
    int pos = ui->verticalSlider->value();
    audio->setVolume(pos / 100.0);
    ui->labelVolume->setText(QString::number(pos));
    audio->setMuted(false);
    isMuteing = false;
    currentVolume = pos;
}

void Widget::on_horizontalSlider_sliderMoved(int position)
{
    ui->labelCurPos->setText(timeStr(position));
}

void Widget::on_horizontalSlider_sliderReleased()
{
    int pos = ui->horizontalSlider->value();
    player->setPosition(pos);
}

void Widget::positionChangedSlot(qint64 pos)
{
    if (!ui->horizontalSlider->isSliderDown())
    {
        ui->horizontalSlider->setValue(pos);
        ui->labelCurPos->setText(timeStr(pos));
    }
}

void Widget::durationChangedSlot(qint64 dur)
{
    ui->labelAllPos->setText(timeStr(dur));
    ui->horizontalSlider->setMaximum(dur);
}

void Widget::on_pushButtonPlayOrPause_clicked()
{
    if(isPlaying == false)
    {
        if(pos < 0)
        {
            QMessageBox::warning(this, "警告", "播放列表为空");
            return;
        }
        playSong();
    }
    else{
        player->pause();
        isPlaying = false;
    }
}

void Widget::on_pushButtonStop_clicked()
{
    player->stop();
    isPlaying = false;
}

void Widget::on_pushButtonMute_clicked()
{
    if(isMuteing == true)
    {
        audio->setMuted(false);
        isMuteing = false;
    }
    else
    {
        audio->setMuted(true);
        isMuteing = true;
    }
}

void Widget::mutedChangedSlot(bool isMute)
{
    if(isMute)
    {
        ui->pushButtonMute->setText("解除静音");

        ui->labelVolume->setText("静音");
    }
    else
    {
        ui->pushButtonMute->setText("静音");

        ui->labelVolume->setText(QString::number(currentVolume));
    }
}

void Widget::playbackStateChangedSlot(QMediaPlayer::PlaybackState state)
{
    switch (state)
    {
    case QMediaPlayer::StoppedState:
    case QMediaPlayer::PausedState:
        ui->pushButtonPlayOrPause->setText("播放");
        break;
    case QMediaPlayer::PlayingState:
        ui->pushButtonPlayOrPause->setText("暂停");
        break;
    }
}

void Widget::on_pushButtonBack_clicked()
{
    qint64 pos = player->position();
    pos += 5000;
    if(pos > player->duration())
    {
        pos = player->duration();
    }
    player->setPosition(pos);
}

void Widget::on_pushButtonFront_clicked()
{
    qint64 pos = player->position();
    pos -= 5000;
    if(pos < 0)
    {
        pos = 0;
    }
    player->setPosition(pos);
}

void Widget::on_listView_doubleClicked(const QModelIndex &index)
{
    pos = index.row();
    if(pos == currentPos && isPlaying == true)
    {
        player->pause();
        isPlaying = false;
    }
    else
    {
        pos = index.row();
        playSong();
    }
}

void Widget::on_pushButtonPrev_clicked()
{
    switch(ui->comboBox->currentIndex())
    {
    case LIST_PLAY:
    case SING_LOOP:
        if(pos == 0)
        {
            QMessageBox::critical(this, "MP3播放器", "已经是第一首了");
            return;
        }
        pos--;
        playSong();
        break;
    case LIST_LOOP:
        pos = (pos - 1 + songData.size()) % songData.size();
        playSong();
        break;
    case RAND_PLAY:
        pos = rand() % songData.size();
        playSong();
        break;
    default:;
    }
}

void Widget::on_pushButtonNext_clicked()
{
    switch(ui->comboBox->currentIndex())
    {
    case LIST_PLAY:
    case SING_LOOP:
        if(pos == songData.size() - 1)
        {
            QMessageBox::critical(this, "MP3播放器", "已经是最后一首了");
            return;
        }
        pos++;
        playSong();
        break;
    case LIST_LOOP:
        pos = (pos + 1) % songData.size();
        playSong();
        break;
    case RAND_PLAY:
        pos = rand() % songData.size();
        playSong();
        break;
    default:;
    }
}

void Widget::on_pushButtonAdd_clicked()
{
    bool flag = false;
    QModelIndex tmp;
    if(songData.isEmpty())
    {
        flag = true;
    }
    else
    {
        tmp = ui->listView->currentIndex();
    }

    QStringList res = QFileDialog::getOpenFileNames(this, "添加音乐文件", DFLPATH);
    if(res.isEmpty())
    {
        return;
    }

    songData.append(res);
    model->setStringList(songData);
    if(flag)
    {
        pos = 0;
        ui->listView->setCurrentIndex(model->index(0));
    }
    else
    {
        ui->listView->setCurrentIndex(tmp);
    }
}

void Widget::mediaStatusChangedSlot(QMediaPlayer::MediaStatus status)
{
    if(status == QMediaPlayer::EndOfMedia)
    {
        if(ui->comboBox->currentIndex() == SING_LOOP)
        {
            player->play();
            return;
        }
        on_pushButtonNext_clicked();
    }
}

void Widget::on_pushButtonDel_clicked()
{
    if(songData.isEmpty())
    {
        QMessageBox::critical(this, "MP3播放器", "列表中没有歌曲，无法删除！");
        return;
    }

    int del = ui->listView->currentIndex().row();

    if(del < pos)
    {
        pos--;
    }
    else if(del == pos)
    {
        if(pos == songData.size() - 1 && player->playbackState() == QMediaPlayer::StoppedState)
        {
            pos--;
        }
        else if(player->playbackState() == QMediaPlayer::PlayingState
                || player->playbackState() == QMediaPlayer::PausedState)
        {
            QMessageBox::critical(this, "MP3播放器", "歌曲正在播放，无法删除");
            return;
        }
    }
    songData.remove(del);
    model->setStringList(songData);

    if(del == songData.size())
    {
        del--;
    }

    if(songData.isEmpty())
    {
        pos = -1;
        ui->labelAllPos->setText("00:00");
    }
    else
    {
        ui->listView->setCurrentIndex(model->index(del));
    }
}

void Widget::on_pushButtonUp_clicked()
{
    int mov = ui->listView->currentIndex().row();
    if(mov == 0)
    {
        QMessageBox::critical(this, "MP3播放器", "已经是第一首了");
        return;
    }

    if(mov == pos)
    {
        pos--;
    }
    else if(mov - 1 == pos)
    {
        pos++;
    }

    songData[mov].swap(songData[mov - 1]);
    model->setStringList(songData);
    ui->listView->setCurrentIndex(model->index(mov - 1));
}

void Widget::on_pushButtonDown_clicked()
{
    int mov = ui->listView->currentIndex().row();
    if(mov == songData.size() - 1)
    {
        QMessageBox::critical(this, "MP3播放器", "已经是最后一首了");
        return;
    }

    if(mov == pos)
    {
        pos++;
    }
    else if(mov + 1 == pos)
    {
        pos--;
    }

    songData[mov].swap(songData[mov + 1]);
    model->setStringList(songData);
    ui->listView->setCurrentIndex(model->index(mov + 1));
}

void Widget::readList(const QString& path)
{
    QFile qf(path);

    bool ret = qf.open(QIODevice::ReadOnly);
    if(!ret)
    {
        QMessageBox::critical(this, "MP3播放器", "打开播放列表出错");
        return;
    }
    QString volumeStr = qf.readLine();
    currentVolume = volumeStr.toInt();


    QString str = qf.readLine();
    while(!str.isEmpty())
    {
        songData.append(str.trimmed());
        str = qf.readLine();
    }

    model->setStringList(songData);
    ui->listView->setCurrentIndex(model->index(0));
    pos = 0;
    qf.close();
}

void Widget::saveList(const QString& path)
{
    QFile qf(path);

    bool ret = qf.open(QIODevice::WriteOnly | QIODevice::Truncate);
    if(!ret)
    {
        QMessageBox::critical(this, "MP3播放器", "保存播放列表出错");
        return;
    }
    qf.write(QString::number(currentVolume).toUtf8() + "\r\n");
    for(auto& e : songData)
    {
        qf.write((e + "\r\n").toUtf8());
    }

    qf.close();
}

void Widget::on_pushButtonImport_clicked()
{
    QString lst = QFileDialog::getOpenFileName(this, "打开播放列表", DFLPATH, "*.lst");
    if(lst.isEmpty())
    {
        return;
    }

    readList(lst);
}


void Widget::on_pushButtonExport_clicked()
{
    QString lst = QFileDialog::getSaveFileName(this, "保存播放列表", DFLPATH, "*.lst");
    if(lst.isEmpty())
    {
        return;
    }

    saveList(lst);
}

void Widget::closeEvent(QCloseEvent* event)
{
    Q_UNUSED(event);
    saveList(SETTINGFILE);
}

void Widget::on_pushButtonClear_clicked()
{
    player->stop();
    isPlaying = false;
    songData.clear();
    model->setStringList(songData);

    pos = -1;
    ui->horizontalSlider->setValue(0);
    ui->labelCurPos->setText("00:00");
    ui->labelAllPos->setText("00:00");

    ui->pushButtonPlayOrPause->setText("播放");
}

void Widget::on_pushButtonPosing_clicked()
{
    if (pos >= 0 && pos < songData.size()) {
        QModelIndex index = model->index(pos);
        ui->listView->setCurrentIndex(index);
        ui->listView->scrollTo(index, QAbstractItemView::PositionAtCenter);
    } else {
        QMessageBox::information(this, "MP3播放器", "当前没有正在播放的歌曲");
    }
}

void Widget::handleAudioOutputsChanged()
{
    // 获取当前默认输出设备
    QAudioDevice defaultDevice = QMediaDevices::defaultAudioOutput();

    // 如果当前设备与之前不同，则重新设置
    if (audio->device() != defaultDevice) {
        // 记录当前播放位置（可选，用于恢复进度）
        qint64 position = player->position();

        // 重新设置输出设备
        audio->setDevice(defaultDevice);

        // 如果是播放状态，重启播放以应用新设备
        if (player->playbackState() == QMediaPlayer::PlayingState) {
            player->setPosition(position);
            player->play();
        }
    }
}