#ifndef CARWINDOW_H
#define CARWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QCloseEvent>
#include <QMEssageBox>
#include <QTimer>
#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsPathItem>
#include <QGraphicsEllipseItem>
#include <QPainterPath>
#include <QInputDialog>

namespace Ui {
class carWindow;
}

struct CarData {
    double speed;      // 当前速度（平滑后）
    int acc;           // 油门 0~10
    int brake;         // 刹车 0~10
    int clutch;        // 离合 0~10
    int gear;          // 档位：0=空档，1~5=前进档，-1=倒档
    int angle;         // 方向盘角度
    bool leftT;        // 左转向灯
    bool rightT;       // 右转向灯
    bool brakeL;       // 刹车灯（自动根据刹车值>0点亮）
    bool lowB;         // 近光灯
    bool highB;        // 远光灯
    bool foglight;      // 雾灯
    bool poslightF;      // 示廓灯
    bool poslightE;
    bool SeatbeltFL;   // 安全带
    bool SeatbeltFR;
    bool SeatbeltEL;
    bool SeatbeltER;

    bool doorFL;
    bool doorFR;
    bool doorEL;
    bool doorER;
};

class carWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit carWindow(QTcpSocket* socket, QWidget *parent = nullptr);
    ~carWindow();

    void updateSpeed();
    void updateTargetSpeed();
    void sendData();

    bool canShiftGear() const;
    void trySetGear(int newGear);
    bool isSpeedInGearRange(int gear, double speed);

    void onAccTimerTimeout();
    void onBrakeTimerTimeout();

    void updateGearButtonsEnabled();

    void setGroup();

private slots:

    void on_verticalSlider_acc_sliderMoved(int position);
    void on_verticalSlider_brake_sliderMoved(int position);
    void on_verticalSlider_clutch_sliderMoved(int position);

    void on_checkBox_LeftRight_checkStateChanged(const Qt::CheckState &arg1);

    void on_checkBox_leftT_toggled(bool checked);
    void on_checkBox_rightT_toggled(bool checked);

    void on_checkBox_lowB_toggled(bool checked);
    void on_checkBox_highB_toggled(bool checked);

    void on_radioButton_toggled(bool checked);
    void on_radioButton_1_toggled(bool checked);
    void on_radioButton_2_toggled(bool checked);
    void on_radioButton_3_toggled(bool checked);
    void on_radioButton_4_toggled(bool checked);
    void on_radioButton_5_toggled(bool checked);
    void on_radioButton_R_toggled(bool checked);

    void on_checkBox_brakeL_toggled(bool checked);

    void on_checkBox_SeatbeltFL_toggled(bool checked);
    void on_checkBox_SeatbeltFR_toggled(bool checked);
    void on_checkBox_SeatbeltEL_toggled(bool checked);
    void on_checkBox_SeatbeltER_toggled(bool checked);

    void on_checkBox_poslightF_toggled(bool checked);
    void on_checkBox_poslightE_toggled(bool checked);
    void on_checkBox_foglight_toggled(bool checked);

    void on_checkBox_doorFL_toggled(bool checked);
    void on_checkBox_doorFR_toggled(bool checked);
    void on_checkBox_doorEL_toggled(bool checked);
    void on_checkBox_doorER_toggled(bool checked);

    void on_dial_valueChanged(int value);

    void on_pushButton_Reset_clicked();
    void on_pushButton_Left_clicked();
    void on_pushButton_Right_clicked();

    void on_pushButton_LeftJab_clicked();
    void on_pushButton_RightJab_clicked();

private:
    void Action_Q_slot();
    void Action_W_slot();
    void Action_Ver_slot();
    void Action_Jab_slot();
    void Action_Light_slot();

    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::carWindow *ui;

    QTcpSocket* socket;

    QTimer* speedTimer;
    QTimer* sendTimer;
    QTimer* accTimer;
    QTimer* brakeTimer;

    bool closeFlag = false;

    double currentSpeed = 0.00;
    double targetSpeed = 0.00;

    double speed = 0.00;
    int acc = 0;
    int brake = 0;
    int clutch = 0;

    int gear = 0;          // 当前档位
    int angle = 0;         // 方向盘角度
    bool leftT = false;        // 左转向灯状态
    bool rightT = false;       // 右转向灯状态
    bool lowB = false;         // 近光灯
    bool highB = false;        // 远光灯
    bool brakeL = false;       // 刹车灯
    bool SeatbeltFL = false;   // 安全带
    bool SeatbeltFR = false;
    bool SeatbeltEL = false;
    bool SeatbeltER = false;

    bool foglight = false;
    bool poslightF = false;
    bool poslightE = false;

    bool doorFL = false;
    bool doorFR = false;
    bool doorEL = false;
    bool doorER = false;

    QGraphicsScene* scene;
    QGraphicsItemGroup* group;

    int lastDialValue;          // 上一次的 dial 值（-180~180）
    double totalAngle;          // 累计净旋转角度（单位：度）

    int JabAngle = 30;
    int LightAngle = 5;
};

#endif // CARWINDOW_H
