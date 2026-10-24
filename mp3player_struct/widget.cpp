#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , player(new QMediaPlayer)
    , audio(new QAudioOutput)
    , model(new QStandardItemModel(this))
{
    ui->setupUi(this);

    connect(player, & QMediaPlayer::positionChanged, this, &Widget::positionChangedSlot);
    connect(player, & QMediaPlayer::durationChanged, this, &Widget::durationChangedSlot);
    connect(audio, & QAudioOutput::mutedChanged, this, &Widget::mutedChangedSlot);
    connect(player, & QMediaPlayer::playbackStateChanged, this, &Widget::playbackStateChangedSlot);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &Widget::mediaStatusChangedSlot);

    ui->pushButtonCancel->setVisible(false);
    ui->labelMute->setVisible(false);
    ui->pushButtonPause->setVisible(false);

    ui->listView->setModel(model);
    ui->comboBox->addItems({"顺序播放", "列表循环", "单曲循环", "随机播放"});

    srand(time(NULL));
    audio->setVolume(1);
    player->setAudioOutput(audio);

    readList(SETTINGFILE);
}

Widget::~Widget()
{
    delete model;
    delete audio;
    delete player;
    delete ui;
}

QString Widget::timeStr(qint64 num)
{
    num /= 1000;
    return QString("%1:%2").arg(num / 60, 2, 10, '0').arg(num % 60, 2, 10, '0');
}

QString Widget::getBaseFileName(const QString &filePath) {
    QFileInfo info(filePath);
    return info.baseName();
}

void Widget::refreshModel()
{
    model->clear();
    for (auto& info : songData) {
        qDebug() << "fullPath:" << info.fullPath << "displayName:" << info.displayName;
        QStandardItem *item = new QStandardItem(info.displayName);
        item->setData(info.fullPath, Qt::UserRole);
        model->appendRow(item);
    }
}

void Widget::playSong()
{
    if (pos < 0 || pos >= songData.size()) return;

    if(pos != currentPos)
    {
        player->setSource(QUrl(songData[pos].fullPath));
        currentPos = pos;
    }
    player->play();
    isPlaying = true;
    ui->listView->setCurrentIndex(model->index(pos, 0));
}

void Widget::on_verticalSlider_sliderMoved(int position)
{
    audio->setVolume(position / 100.0);
    ui->labelVolume->setText(QString::number(position));
    audio->setMuted(false);
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
    }
    ui->labelCurPos->setText(timeStr(pos));
}

void Widget::durationChangedSlot(qint64 dur)
{
    ui->labelAllPos->setText(timeStr(dur));
    ui->horizontalSlider->setMaximum(dur);
}

void Widget::on_pushButtonPlay_clicked()
{
    if(pos < 0)
    {
        QMessageBox::warning(this, "警告", "播放列表为空");
        return;
    }
    playSong();
}

void Widget::on_pushButtonPause_clicked()
{
    player->pause();
    isPlaying = false;
}

void Widget::on_pushButtonStop_clicked()
{
    player->stop();
    isPlaying = false;
}

void Widget::on_pushButtonMute_clicked()
{
    audio->setMuted(true);
}

void Widget::on_pushButtonCancel_clicked()
{
    audio->setMuted(false);
}

void Widget::mutedChangedSlot(bool isMute)
{
    if(isMute)
    {
        ui->pushButtonMute->setVisible(false);
        ui->pushButtonCancel->setVisible(true);

        ui->labelVolume->setVisible(false);
        ui->labelMute->setVisible(true);
    }
    else
    {
        ui->pushButtonMute->setVisible(true);
        ui->pushButtonCancel->setVisible(false);

        ui->labelVolume->setVisible(true);
        ui->labelMute->setVisible(false);
    }
}

void Widget::playbackStateChangedSlot(QMediaPlayer::PlaybackState state)
{
    switch (state)
    {
    case QMediaPlayer::StoppedState:
    case QMediaPlayer::PausedState:
        ui->pushButtonPause->setVisible(false);
        ui->pushButtonPlay->setVisible(true);
        break;
    case QMediaPlayer::PlayingState:
        ui->pushButtonPause->setVisible(true);
        ui->pushButtonPlay->setVisible(false);
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
    int row = index.row();
    if (row < 0 || row >= songData.size()) return;

    if(row == currentPos && isPlaying)
    {
        player->pause();
        isPlaying = false;
    }
    else
    {
        pos = row;
        playSong();
    }
}

void Widget::on_pushButtonPrev_clicked()
{
    if (songData.isEmpty()) return;

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
    if (songData.isEmpty()) return;

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

    for (auto& path : res) {
        songData.append(SongInfo(path));
    }
    refreshModel();

    if(flag)
    {
        pos = 0;
        ui->listView->setCurrentIndex(model->index(0, 0));
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
    if (del < 0 || del >= songData.size()) return;

    // 调整播放索引
    if (del < pos) {
        pos--;
    } else if (del == pos) {
        // 如果删除的是当前播放的歌曲
        if (player->playbackState() == QMediaPlayer::PlayingState ||
            player->playbackState() == QMediaPlayer::PausedState) {
            QMessageBox::critical(this, "MP3播放器", "歌曲正在播放，无法删除");
            return;
        }
        // 如果删除的是最后一首且已停止，则 pos--
        if (pos == songData.size() - 1 && player->playbackState() == QMediaPlayer::StoppedState) {
            pos--;
        }
    }

    songData.removeAt(del);
    refreshModel();

    // 调整 currentPos
    if (currentPos == del) {
        currentPos = -1;   // 删除的是当前播放的歌曲，重置
    } else if (currentPos > del) {
        currentPos--;
    }

    if(songData.isEmpty())
    {
        pos = -1;
        currentPos = -1;
        ui->labelAllPos->setText("00:00");
        ui->listView->setCurrentIndex(QModelIndex());
    }
    else
    {
        // 如果 del 已经超出边界，选最后一首
        if (del >= songData.size()) del = songData.size() - 1;
        ui->listView->setCurrentIndex(model->index(del, 0));
        if (pos >= songData.size()) pos = songData.size() - 1;
    }
}

void Widget::on_pushButtonUp_clicked()
{
    int mov = ui->listView->currentIndex().row();
    if (mov <= 0 || mov >= songData.size()) {
        QMessageBox::critical(this, "MP3播放器", "已经是第一首了");
        return;
    }

    // 调整 pos 和 currentPos
    if (mov == pos) pos--;
    else if (mov - 1 == pos) pos++;

    if (mov == currentPos) currentPos--;
    else if (mov - 1 == currentPos) currentPos++;

    std::swap(songData[mov], songData[mov - 1]);
    refreshModel();
    ui->listView->setCurrentIndex(model->index(mov - 1, 0));
}

void Widget::on_pushButtonDown_clicked()
{
    int mov = ui->listView->currentIndex().row();
    if (mov < 0 || mov >= songData.size() - 1) {
        QMessageBox::critical(this, "MP3播放器", "已经是最后一首了");
        return;
    }

    // 调整 pos 和 currentPos
    if (mov == pos) pos++;
    else if (mov + 1 == pos) pos--;

    if (mov == currentPos) currentPos++;
    else if (mov + 1 == currentPos) currentPos--;

    std::swap(songData[mov], songData[mov + 1]);
    refreshModel();
    ui->listView->setCurrentIndex(model->index(mov + 1, 0));
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

    songData.clear();
    QString str = qf.readLine();
    while (!str.isEmpty()) {
        songData.append(SongInfo(str.trimmed()));
        str = qf.readLine();
    }
    refreshModel();

    if (!songData.isEmpty()) {
        pos = 0;
        currentPos = -1; // 未播放
        ui->listView->setCurrentIndex(model->index(0, 0));
    } else {
        pos = -1;
        currentPos = -1;
    }
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

    for(auto& info : songData)
    {
        qf.write((info.fullPath + "\r\n").toUtf8());
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
    refreshModel();

    pos = -1;
    currentPos = -1;
    ui->horizontalSlider->setValue(0);
    ui->labelCurPos->setText("00:00");
    ui->labelAllPos->setText("00:00");

    ui->pushButtonPause->setVisible(false);
    ui->pushButtonPlay->setVisible(true);
}

void Widget::on_pushButtonPosing_clicked()
{
    if (pos >= 0 && pos < songData.size()) {
        QModelIndex index = model->index(pos, 0);
        ui->listView->setCurrentIndex(index);
        ui->listView->scrollTo(index, QAbstractItemView::PositionAtCenter);
    } else {
        QMessageBox::information(this, "MP3播放器", "当前没有正在播放的歌曲");
    }
}