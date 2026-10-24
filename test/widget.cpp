#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
#include "errordialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , model(new QStringListModel)
    , player(new QMediaPlayer)
    , audio(new QAudioOutput)
    , videoWidget(new QVideoWidget)
{
    ui->setupUi(this);

    connect(player, & QMediaPlayer::positionChanged, this, &Widget::positionChangedSlot);
    connect(player, & QMediaPlayer::durationChanged, this, &Widget::durationChangedSlot);


    ui->listView->setModel(model);

    QString text = ui->comboBox->currentText();
    ui->label_5->setText(text);
    int arg1 = ui->spinBox->value();
    ui->label_6->setText(QString::number(arg1)); // 初始化加载

    ui->verticalLayout_3->addWidget(videoWidget);
    player->setVideoOutput(videoWidget);

    audio->setVolume(1);
    player->setAudioOutput(audio);
    player->setSource(QUrl(""));
    player->play();


}

Widget::~Widget()
{
    delete model;
    delete ui;
}

void Widget::onOpenNewWindow()
{
    Widget *win = new Widget(this);
    win->show();
}

QString Widget::timeStr(qint64 num)
{
    num /= 1000;
    return QString("%1:%2").arg(num / 60, 2, 10, '0').arg(num % 60, 2, 10, '0');
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

// void Widget::mousePressEvent(QMouseEvent* event)
// {
//     switch(event->button())
//     {
//     case Qt::LeftButton    : ui->label_1->setText("左键按下"); break;
//     case Qt::RightButton   : ui->label_1->setText("右键按下"); break;
//     case Qt::MiddleButton  : ui->label_1->setText("滚轮按下"); break;
//     case Qt::BackButton    : ui->label_1->setText("后腿按下"); break;
//     case Qt::ForwardButton : ui->label_1->setText("前进按下"); break;
//     default:;
//     }
// }

// void Widget::mouseReleaseEvent(QMouseEvent* event)
// {
//     switch(event->button())
//     {
//     case Qt::LeftButton    : ui->label_2->setText("左键弹起"); break;
//     case Qt::RightButton   : ui->label_2->setText("右键弹起"); break;
//     case Qt::MiddleButton  : ui->label_2->setText("滚轮弹起"); break;
//     case Qt::BackButton    : ui->label_2->setText("后腿弹起"); break;
//     case Qt::ForwardButton : ui->label_2->setText("前进弹起"); break;
//     default:;
//     }
// }

// void Widget::mouseDoubleClickEvent(QMouseEvent* event)
// {
//     switch(event->button())
//     {
//     case Qt::LeftButton    : ui->label_3->setText("左键双击"); break;
//     case Qt::RightButton   : ui->label_3->setText("右键双击"); break;
//     case Qt::MiddleButton  : ui->label_3->setText("滚轮双击"); break;
//     case Qt::BackButton    : ui->label_3->setText("后腿双击"); break;
//     case Qt::ForwardButton : ui->label_3->setText("前进双击"); break;
//     default:;
//     }
// }

// void Widget::mouseMoveEvent(QMouseEvent* event)
// {
//     QString str = QString("(%1,%2)").arg(event->position().x()).arg(event->position().y());
//     ui->label_4->setText(str);
// }

// void Widget::keyPressEvent(QKeyEvent* event)
// {
//     if(event->isAutoRepeat())
//     {
//         return;
//     }
//     if(event->modifiers() == Qt::NoModifier)
//     {
//         switch(event->key())
//         {
//         case Qt::Key_W : ui->label_1->setText("W键按下"); break;
//         case Qt::Key_A : ui->label_1->setText("A键按下"); break;
//         case Qt::Key_S : ui->label_1->setText("S键按下"); break;
//         case Qt::Key_D : ui->label_1->setText("D键按下"); break;
//         default:;
//         }
//     }
//     else if(event->modifiers() == Qt::ControlModifier)
//     {
//         switch(event->key())
//         {
//         case Qt::Key_W : ui->label_2->setText("Ctrl + W键按下"); break;
//         case Qt::Key_A : ui->label_2->setText("Ctrl + A键按下"); break;
//         case Qt::Key_S : ui->label_2->setText("Ctrl + S键按下"); break;
//         case Qt::Key_D : ui->label_2->setText("Ctrl + D键按下"); break;
//         default:;
//         }
//     }
//     else if(event->modifiers() == (Qt::ControlModifier | Qt::ShiftModifier))
//     {
//         switch(event->key())
//         {
//         case Qt::Key_W : ui->label_3->setText("Ctrl + Shift + W键按下"); break;
//         case Qt::Key_A : ui->label_3->setText("Ctrl + Shift + A键按下"); break;
//         case Qt::Key_S : ui->label_3->setText("Ctrl + Shift + S键按下"); break;
//         case Qt::Key_D : ui->label_3->setText("Ctrl + Shift + D键按下"); break;
//         default:;
//         }
//     }
// }

// void Widget::keyReleaseEvent(QKeyEvent* event)
// {
//     if(event->isAutoRepeat())
//     {
//         return;
//     }
//     if(event->modifiers() == Qt::NoModifier)
//     {
//         switch(event->key())
//         {
//         case Qt::Key_W : ui->label_1->setText("W键弹起"); break;
//         case Qt::Key_A : ui->label_1->setText("A键弹起"); break;
//         case Qt::Key_S : ui->label_1->setText("S键弹起"); break;
//         case Qt::Key_D : ui->label_1->setText("D键弹起"); break;
//         default:;
//         }
//     }
//     else if(event->modifiers() == Qt::ControlModifier)
//     {
//         switch(event->key())
//         {
//         case Qt::Key_W : ui->label_2->setText("Ctrl + W键弹起"); break;
//         case Qt::Key_A : ui->label_2->setText("Ctrl + A键弹起"); break;
//         case Qt::Key_S : ui->label_2->setText("Ctrl + S键弹起"); break;
//         case Qt::Key_D : ui->label_2->setText("Ctrl + D键弹起"); break;
//         default:;
//         }
//     }
//     else if(event->modifiers() == (Qt::ControlModifier | Qt::ShiftModifier))
//     {
//         switch(event->key())
//         {
//         case Qt::Key_W : ui->label_3->setText("Ctrl + Shift + W键弹起"); break;
//         case Qt::Key_A : ui->label_3->setText("Ctrl + Shift + A键弹起"); break;
//         case Qt::Key_S : ui->label_3->setText("Ctrl + Shift + S键弹起"); break;
//         case Qt::Key_D : ui->label_3->setText("Ctrl + Shift + D键弹起"); break;
//         default:;
//         }
//     }
// }

void Widget::closeEvent(QCloseEvent* event)
{
    auto ret = QMessageBox::question(this, "询问", "是否要关闭窗口？");
    if (ret == QMessageBox::No)
    {
        event->ignore();
    }
}

void Widget::on_comboBox_currentIndexChanged(int index)
{
    if (index >= 0)
    {
        QString text = ui->comboBox->currentText();
        ui->label_5->setText(text);
    }
}


void Widget::on_spinBox_valueChanged(int arg1)
{
    ui->label_6->setText(QString::number(arg1));
}


void Widget::on_pushButton_clicked()
{
    QFileDialog::getOpenFileNames(this, "打开");
}


void Widget::on_pushButton_2_clicked()
{

    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();
}


void Widget::on_pushButton_1_clicked()
{
    data.append(ui->lineEdit->text());
    model->setStringList(data);
    ui->lineEdit->clear();
}


void Widget::on_pushButton_3_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
}


void Widget::on_pushButton_4_clicked()
{
    int value = QInputDialog::getInt(this, "输入整数",
                                     "请输入-1000到1000之间的数值:",
                                     100, -1000, 1000, 10, &ok);
    if(ok)
    {
        ui->label_1->setText(QString::number(value));
    }
}


void Widget::on_pushButton_5_clicked()
{
    QStringList items;
    items << tr("春天") << tr("夏天") << tr("秋天") << tr("冬天");
    QString item = QInputDialog::getItem(this, "选择季节",
                                         "请选择一个季节:",
                                         items, 0, false, &ok);
    if(ok)
    {
        ui->label_2->setText(item);
    }
}


void Widget::on_pushButton_6_clicked()
{
    QString text = QInputDialog::getText(this, "输入姓名",
                                     "请输入您的名字:", QLineEdit::Normal,
                                     "默认姓名", &ok);
    if(ok && !text.isEmpty())
    {
        ui->label_3->setText(text);
    }
}

void Widget::on_pushButton_7_clicked()
{
    QString text = QInputDialog::getText(this, "输入密码",
                                         "请输入您的密码:", QLineEdit::Password,
                                         "", &ok);
    if(ok && !text.isEmpty())
    {
        ui->label_4->setText(text);
    }
}

void Widget::on_pushButton_9_clicked()
{
    bool ok;
    QString text = QInputDialog::getMultiLineText(this, tr("输入备注"),
                                                  tr("请输入详细备注:"),
                                                  "默认的备注内容", &ok);
    if (ok && !text.isEmpty()) {
        ui->listWidget->addItem(text);
    }
}

void Widget::on_dial_sliderMoved(int position)
{
    ui->listWidget->addItem(QString::number(position));
    ui->listWidget->scrollToBottom();
}


void Widget::on_pushButton_14_clicked()
{
    Dialog* pd = new Dialog(this);
    pd->show();
}


void Widget::on_dial_sliderReleased()
{
    int pos = ui->dial->value();
    ui->listWidget->addItem(QString::number(pos));
    ui->listWidget->scrollToBottom();
}


void Widget::on_pushButton_11_clicked()
{
    player->pause();
}


void Widget::on_pushButton_10_clicked()
{
    player->play();
}

void Widget::on_pushButton_12_clicked()
{
    player->stop();
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


void Widget::on_pushButton_15_clicked()
{
    ErrorDialog* pd = new ErrorDialog(this);
    pd->show();
}

