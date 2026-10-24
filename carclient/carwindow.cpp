#include "carwindow.h"
#include "ui_carwindow.h"

carWindow::carWindow(QTcpSocket* sock, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::carWindow)
    , socket(sock)
    , speedTimer(new QTimer)
    , sendTimer(new QTimer)
    , accTimer(new QTimer)
    , brakeTimer(new QTimer)
    , scene(new QGraphicsScene)
    , group(new QGraphicsItemGroup)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/car-icon.ico"));
    this->setFixedSize(1100, 600);
    updateGearButtonsEnabled();

    connect(ui->action_Q, &QAction::triggered, this, &carWindow::Action_Q_slot);
    connect(ui->action_W, &QAction::triggered, this, &carWindow::Action_W_slot);
    connect(ui->action_V, &QAction::triggered, this, &carWindow::Action_Ver_slot);
    connect(ui->action_Jab, &QAction::triggered, this, &carWindow::Action_Jab_slot);
    connect(ui->action_Light, &QAction::triggered, this, &carWindow::Action_Light_slot);

    speedTimer->setInterval(20);
    connect(speedTimer, &QTimer::timeout, this, &carWindow::updateSpeed);

    // 数据发送独立定时器
    sendTimer->setInterval(50);
    connect(sendTimer, &QTimer::timeout, this, &carWindow::sendData);
    sendTimer->start();

    accTimer->setInterval(100);
    connect(accTimer, &QTimer::timeout, this, &carWindow::onAccTimerTimeout);

    brakeTimer->setInterval(100);
    connect(brakeTimer, &QTimer::timeout, this, &carWindow::onBrakeTimerTimeout);

    setGroup();

    lastDialValue = ui->dial->value();
    totalAngle = 0.0;
}

carWindow::~carWindow()
{
    delete ui;
}

void carWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing |
                           QPainter::TextAntialiasing |
                           QPainter::SmoothPixmapTransform);

    QPixmap pm(":/background.png");
    painter.drawPixmap(0, 0, width(), height(), pm);
}

void carWindow::onAccTimerTimeout()
{
    int current = ui->verticalSlider_acc->value();
    int newVal = qMin(10, current + 1);
    ui->verticalSlider_acc->setValue(newVal);
    ui->label_acc->setText(QString::number(newVal));
    updateTargetSpeed();

    if (newVal >= 10)
        accTimer->stop();  // 达到最大值后停止递增（松开后复位）
}

void carWindow::onBrakeTimerTimeout()
{
    int current = ui->verticalSlider_brake->value();
    int newVal = qMin(10, current + 1);
    ui->verticalSlider_brake->setValue(newVal);
    ui->label_brake->setText(QString::number(newVal));
    ui->checkBox_brakeL->setChecked(true);
    updateTargetSpeed();

    if (newVal >= 10)
        brakeTimer->stop();
}

void carWindow::keyPressEvent(QKeyEvent* event)
{
    if(event->isAutoRepeat() && event->key() != Qt::Key_A && event->key() != Qt::Key_D
        && event->key() != Qt::Key_W && event->key() != Qt::Key_S)
    {
        return;
    }

    if(event->modifiers() == Qt::NoModifier)
    {
        switch(event->key())
        {
        case Qt::Key_W: // 加速
        {
            if (brakeTimer->isActive())
            {
                brakeTimer->stop();
                ui->verticalSlider_brake->setValue(0);
                ui->label_brake->setText("0");
            }
            if (!accTimer->isActive())
                accTimer->start();
            break;
        }
        case Qt::Key_S: // 减速（刹车）
        {
            if (accTimer->isActive())
            {
                accTimer->stop();
                ui->verticalSlider_acc->setValue(0);
                ui->label_acc->setText("0");
            }
            if (!brakeTimer->isActive())
                brakeTimer->start();
            break;
        }
        case Qt::Key_A: // 左转（逆时针，减小）
        {
            int pos = ui->dial->value();
            ui->dial->setValue(pos - 5);   // 不再限制最小值
            break;
        }
        case Qt::Key_D: // 右转（顺时针，增大）
        {
            int pos = ui->dial->value();
            ui->dial->setValue(pos + 5);   // 不再限制最大值
            break;
        }
        case Qt::Key_Q: // 挂倒挡
            ui->radioButton_R->setChecked(true);
            break;
        case Qt::Key_Z: // 双闪
            ui->checkBox_LeftRight->toggle();
            break;
        case Qt::Key_X: // 远光灯
            ui->checkBox_highB->toggle();
            break;
        case Qt::Key_C: // 近光灯
            ui->checkBox_lowB->toggle();
            break;
        case Qt::Key_N: // 左转向灯
        {
            // 若危险警告灯开启，先关闭它
            if (ui->checkBox_LeftRight->isChecked())
                ui->checkBox_LeftRight->setChecked(false);
            // 切换左转灯
            ui->checkBox_leftT->setChecked(!ui->checkBox_leftT->isChecked());
            break;
        }
        case Qt::Key_M: // 右转向灯
        {
            if (ui->checkBox_LeftRight->isChecked())
                ui->checkBox_LeftRight->setChecked(false);
            ui->checkBox_rightT->setChecked(!ui->checkBox_rightT->isChecked());
            break;
        }
        default:
            break;
        }
    }

    if(event->modifiers() == Qt::ControlModifier)
    {
        switch(event->key())
        {
        case Qt::Key_Q : Action_Q_slot(); break;
        case Qt::Key_W : Action_W_slot(); break;
        case Qt::Key_V : Action_Ver_slot(); break;
        default:;
        }
    }
}

void carWindow::keyReleaseEvent(QKeyEvent* event)
{
    // 忽略自动重复（但正常情况下松开不会有自动重复，加上更安全）
    if (event->isAutoRepeat())
        return;

    switch (event->key())
    {
    case Qt::Key_W:
        if (accTimer->isActive())
        {
            accTimer->stop();
        }
        ui->verticalSlider_acc->setValue(0);
        ui->label_acc->setText("0");
        updateTargetSpeed();   // 更新目标速度
        break;

    case Qt::Key_S:
        if (brakeTimer->isActive())
        {
            brakeTimer->stop();

        }
        ui->verticalSlider_brake->setValue(0);
        ui->label_brake->setText("0");
        // 同时将刹车灯熄灭
        ui->checkBox_brakeL->setChecked(false);
        updateTargetSpeed();
        break;

    default:
        break;
    }

    // 调用基类处理其他按键
    QMainWindow::keyReleaseEvent(event);
}

void carWindow::sendData()
{
    CarData data;
    data.speed   = currentSpeed;
    data.acc     = ui->verticalSlider_acc->value();
    data.brake   = ui->verticalSlider_brake->value();
    data.clutch  = ui->verticalSlider_clutch->value();
    data.gear    = gear;
    data.angle   = angle;
    data.leftT   = leftT;
    data.rightT  = rightT;
    data.brakeL  = brakeL;
    data.lowB    = lowB;
    data.highB   = highB;
    data.poslightF = poslightF;
    data.poslightE = poslightE;
    data.foglight = foglight;
    data.SeatbeltFL = SeatbeltFL;
    data.SeatbeltFR = SeatbeltFR;
    data.SeatbeltEL = SeatbeltEL;
    data.SeatbeltER = SeatbeltER;
    data.doorFL = doorFL;
    data.doorFR = doorFR;
    data.doorEL = doorEL;
    data.doorER = doorER;

    // 第一步：序列化数据体到 QByteArray
    QByteArray body;
    QDataStream bodyStream(&body, QIODevice::WriteOnly);
    bodyStream << data.speed << data.acc << data.brake << data.clutch
               << data.gear << data.angle << data.leftT << data.rightT
               << data.brakeL << data.lowB << data.highB << data.poslightF
               << data.poslightE << data.foglight << data.SeatbeltFL
               << data.SeatbeltFR << data.SeatbeltEL << data.SeatbeltER
               << data.doorFL << data.doorFR << data.doorEL << data.doorER;

    // 第二步：构建完整包（长度前缀 + 数据体）
    QByteArray packet;
    QDataStream packetStream(&packet, QIODevice::WriteOnly);
    packetStream << (quint32)body.size();   // 写入长度（4字节）
    packet.append(body);                    // 追加数据体

    // 第三步：发送
    if (socket && socket->state() == QTcpSocket::ConnectedState) {
        socket->write(packet);
        socket->flush();
    }
}

void carWindow::Action_Q_slot()
{
    close();
}

void carWindow::Action_W_slot()
{
    QMessageBox::information(this, "操作指南",
                             "w 加速\n"
                             "s 减速\n"
                             "ad 左右转向\n"
                             "q 挂倒挡\n"
                             "zxc 灯光\n"
                             "nm 左右转向灯"
                             );
}

void carWindow::Action_Ver_slot()
{
    QMessageBox::information(this, "版本信息", "Ver 1.0.0\n开发者：刘程");
}

void carWindow::Action_Light_slot()
{
    bool ok;
    int value = QInputDialog::getInt(this, "输入整数",
                                     "请输入0到60之间的数值:",
                                     5, 0, 60, 5, &ok);
    if(ok)
    {
        LightAngle = value;
    }
}

void carWindow::Action_Jab_slot()
{
    bool ok;
    int value = QInputDialog::getInt(this, "输入整数",
                                     "请输入0到150之间的数值:",
                                     30, 0, 150, 5, &ok);
    if(ok)
    {
        JabAngle = value;
    }
}

void carWindow::updateTargetSpeed()
{
    int acc   = ui->verticalSlider_acc->value();
    int brake = ui->verticalSlider_brake->value();
    int clutch = ui->verticalSlider_clutch->value();

    // 基础速度
    double baseSpeed = 30.0 * acc / (brake * 20 + clutch + 1.0);
    if (baseSpeed > 150.0) baseSpeed = 150.0;   // 硬限速

    // 档位系数（传动比）
    double gearFactor = 0.0;
    if (gear >= 1 && gear <= 5) {
        // 1~5档系数逐渐增大，可自定义
        static double ratios[] = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0};
        gearFactor = ratios[gear];
    } else if (gear == -1) {
        gearFactor = 0.4;   // 倒档速度较低
    }

    double speed = baseSpeed * gearFactor;

    // 倒档速度为负
    if (gear == -1) speed = -speed;

    // 限速
    if (speed < -50.0) speed = -50.0;   // 倒档最大速度

    targetSpeed = speed;

    // 如果定时器未运行，启动它（开始平滑过渡）
    if (!speedTimer->isActive()) {
        speedTimer->start();
    }
}

void carWindow::updateSpeed()
{
    double diff = targetSpeed - currentSpeed;

    // 如果已经很接近目标，直接跳转并停止定时器
    if (qAbs(diff) < 0.05) {
        currentSpeed = targetSpeed;
        speedTimer->stop();
    } else {
        // 每次朝目标移动 20% 的差值，实现指数平滑
        currentSpeed += diff * 0.005;
    }

    // 更新显示（保留一位小数）
    ui->label_Speed->setText(QString::number(currentSpeed, 'f', 2));
}

void carWindow::on_verticalSlider_clutch_sliderMoved(int position)
{
    ui->label_clutch->setText(QString::number(position));
    updateTargetSpeed();
    updateGearButtonsEnabled();
}

void carWindow::on_verticalSlider_brake_sliderMoved(int position)
{
    if (brakeTimer->isActive())
        brakeTimer->stop();
    ui->label_brake->setText(QString::number(position));
    if(position > 0)
    {
        ui->checkBox_brakeL->setChecked(true);
    }
    else
    {
        ui->checkBox_brakeL->setChecked(false);
    }
    updateTargetSpeed();
}

void carWindow::on_verticalSlider_acc_sliderMoved(int position)
{
    if (accTimer->isActive())
        accTimer->stop();
    ui->label_acc->setText(QString::number(position));
    updateTargetSpeed();
}

void carWindow::on_checkBox_LeftRight_checkStateChanged(const Qt::CheckState &arg1)
{
    // 暂时阻断左右复选框的信号
    ui->checkBox_leftT->blockSignals(true);
    ui->checkBox_rightT->blockSignals(true);

    switch(arg1)
    {
    case Qt::Unchecked:
        ui->checkBox_leftT->setChecked(false);
        ui->checkBox_rightT->setChecked(false);
        ui->checkBox_leftT->setEnabled(true);
        ui->checkBox_rightT->setEnabled(true);
        leftT = false;
        rightT = false;
        break;
    case Qt::Checked:
        ui->checkBox_leftT->setChecked(true);
        ui->checkBox_rightT->setChecked(true);
        ui->checkBox_leftT->setEnabled(false);
        ui->checkBox_rightT->setEnabled(false);
        leftT = true;
        rightT = true;
        break;
    case Qt::PartiallyChecked:
        break;
    }

    ui->checkBox_leftT->blockSignals(false);
    ui->checkBox_rightT->blockSignals(false);
}

void carWindow::on_checkBox_leftT_toggled(bool checked)
{
    if (checked) {
        // 当左边被选中时，取消右边
        if (ui->checkBox_rightT->isChecked()) {
            ui->checkBox_rightT->setChecked(false);
        }
    }
    leftT = checked;
}

void carWindow::on_checkBox_rightT_toggled(bool checked)
{
    if (checked) {
        // 当右边被选中时，取消左边
        if (ui->checkBox_leftT->isChecked()) {
            ui->checkBox_leftT->setChecked(false);
        }
    }
    rightT = checked;
}

void carWindow::on_checkBox_brakeL_toggled(bool checked)
{
    brakeL = checked;
}

void carWindow::on_checkBox_lowB_toggled(bool checked)
{
    lowB = checked;
}

void carWindow::on_checkBox_highB_toggled(bool checked)
{
    highB = checked;
}

void carWindow::trySetGear(int newGear)
{
    gear = newGear;
    updateTargetSpeed();
}

void carWindow::on_radioButton_toggled(bool checked) { if (checked) trySetGear(0); }
void carWindow::on_radioButton_1_toggled(bool checked) { if (checked) trySetGear(1); }
void carWindow::on_radioButton_2_toggled(bool checked) { if (checked) trySetGear(2); }
void carWindow::on_radioButton_3_toggled(bool checked) { if (checked) trySetGear(3); }
void carWindow::on_radioButton_4_toggled(bool checked) { if (checked) trySetGear(4); }
void carWindow::on_radioButton_5_toggled(bool checked) { if (checked) trySetGear(5); }
void carWindow::on_radioButton_R_toggled(bool checked) { if (checked) trySetGear(-1); }

void carWindow::updateGearButtonsEnabled()
{
    bool canShift = (ui->verticalSlider_clutch->value() >= 8);
    ui->radioButton_1->setEnabled(canShift);
    ui->radioButton_2->setEnabled(canShift);
    ui->radioButton_3->setEnabled(canShift);
    ui->radioButton_4->setEnabled(canShift);
    ui->radioButton_5->setEnabled(canShift);
    ui->radioButton_R->setEnabled(canShift);
    ui->radioButton->setEnabled(canShift);
}

void carWindow::on_checkBox_SeatbeltFL_toggled(bool checked) { SeatbeltFL = checked; }
void carWindow::on_checkBox_SeatbeltFR_toggled(bool checked) { SeatbeltFR = checked; }
void carWindow::on_checkBox_SeatbeltEL_toggled(bool checked) { SeatbeltEL = checked; }
void carWindow::on_checkBox_SeatbeltER_toggled(bool checked) { SeatbeltER = checked; }


void carWindow::on_checkBox_poslightF_toggled(bool checked) { poslightF = checked; }
void carWindow::on_checkBox_poslightE_toggled(bool checked) { poslightE = checked; }
void carWindow::on_checkBox_foglight_toggled(bool checked) { foglight = checked; }


void carWindow::on_checkBox_doorFL_toggled(bool checked)
{
    doorFL = checked;
    ui->verticalSlider_clutch->setEnabled(!(doorFL || doorFR || doorEL || doorER));
}

void carWindow::on_checkBox_doorFR_toggled(bool checked)
{
    doorFR = checked;
    ui->verticalSlider_clutch->setEnabled(!(doorFL || doorFR || doorEL || doorER));

}
void carWindow::on_checkBox_doorEL_toggled(bool checked)
{
    doorEL = checked;
    ui->verticalSlider_clutch->setEnabled(!(doorFL || doorFR || doorEL || doorER));
}

void carWindow::on_checkBox_doorER_toggled(bool checked)
{
    doorER = checked;
    ui->verticalSlider_clutch->setEnabled(!(doorFL || doorFR || doorEL || doorER));
}

void carWindow::setGroup()
{
    ui->graphicsView->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 200, 200);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing |
                                     QPainter::TextAntialiasing |
                                     QPainter::SmoothPixmapTransform);
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    // ui->graphicsView->setBackgroundBrush(QColor(240, 240, 240));

    QPixmap pm(":/wheel.png");
    QPixmap scaled = pm.scaled(200, 200, Qt::KeepAspectRatio,
                               Qt::SmoothTransformation);

    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(scaled);
    pixItem->setPos(-100, -100);
    pixItem->setFlags(QGraphicsItem::ItemIsMovable |
                      QGraphicsItem::ItemIsSelectable);

    group->addToGroup(pixItem);
    group->setPos(100, 100);
    scene->addItem(group);
}

void carWindow::on_dial_valueChanged(int value)
{
    int delta = value - lastDialValue;
    const int minVal = -180;
    const int maxVal = 180;
    const int range = maxVal - minVal;

    if (delta > 180) {
        delta -= range;
    } else if (delta < -180) {
        delta += range;
    }

    double newTotal = totalAngle + delta;

    // ---- 正向超限：截断到 540° ----
    if (newTotal > 540.0 && delta > 0) {
        totalAngle = 540.0;
        // 计算对应的 dial 值（映射到 [-180, 180]）
        int newDialValue = static_cast<int>(totalAngle) % 360;
        if (newDialValue > 180) newDialValue -= 360;
        else if (newDialValue < -180) newDialValue += 360;

        ui->dial->blockSignals(true);
        ui->dial->setValue(newDialValue);
        ui->dial->blockSignals(false);

        lastDialValue = newDialValue;
        group->setRotation(newDialValue);      // 同步旋转
        ui->label_Angle->setText(QString::number(totalAngle));
        return;
    }
    // ---- 负向超限：截断到 -540° ----
    else if (newTotal < -540.0 && delta < 0) {
        totalAngle = -540.0;
        int newDialValue = static_cast<int>(totalAngle) % 360;
        if (newDialValue > 180) newDialValue -= 360;
        else if (newDialValue < -180) newDialValue += 360;

        ui->dial->blockSignals(true);
        ui->dial->setValue(newDialValue);
        ui->dial->blockSignals(false);

        lastDialValue = newDialValue;
        group->setRotation(newDialValue);
        ui->label_Angle->setText(QString::number(totalAngle));
        return;
    }

    totalAngle = newTotal;
    lastDialValue = value;

    group->setRotation(value);

    angle = totalAngle;
    ui->label_Angle->setText(QString::number(totalAngle));
}

void carWindow::on_pushButton_Reset_clicked()
{
    ui->dial->blockSignals(true);
    ui->dial->setValue(0);
    ui->dial->blockSignals(false);

    totalAngle = 0.0;
    lastDialValue = 0;

    angle = totalAngle;
    ui->label_Angle->setText(QString::number(totalAngle));
    group->setRotation(0);
}

void carWindow::on_pushButton_Left_clicked()
{
    int pos = ui->dial->value();
    ui->dial->setValue(pos - LightAngle);
}


void carWindow::on_pushButton_Right_clicked()
{
    int pos = ui->dial->value();
    ui->dial->setValue(pos + LightAngle);
}


void carWindow::on_pushButton_LeftJab_clicked()
{
    int pos = ui->dial->value();
    ui->dial->setValue(pos - JabAngle);
}


void carWindow::on_pushButton_RightJab_clicked()
{
    int pos = ui->dial->value();
    ui->dial->setValue(pos + JabAngle);
}
