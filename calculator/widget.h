#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    enum Sign { ADD, SUB, MUL, DIV };

private slots:
    // 数字
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

    // 小数点
    void on_pushButton_dian_clicked();

    // 运算符
    void on_pushButton_ADD_clicked();
    void on_pushButton_SUB_clicked();
    void on_pushButton_MUL_clicked();
    void on_pushButton_DIV_clicked();

    // 功能
    void on_pushButton_back_clicked();
    void on_pushButton_C_clicked();
    void on_pushButton_CE_clicked();
    void on_pushButton_MP_clicked();
    void on_pushButton_EQ_clicked();

private:
    Ui::Widget *ui;

    // 运算数据
    double num1;          // 当前操作数1
    double num2;          // 当前操作数2
    double origNum1;      // 本次运算的原始操作数1（用于显示）
    double lastOperand;   // 上次运算的操作数2（用于连续等于）
    Sign sign;            // 当前运算符
    Sign lastSign;        // 上次运算符（用于连续等于）
    bool signFlag;        // 是否已输入运算符（true表示正在输入第二个数）
    bool eqFlag;          // 是否刚完成计算

    // 小数支持
    bool decimalFlag;     // 当前输入的数字是否包含小数点
    double decimalFactor; // 下一位小数的权重（10, 100, 1000...）

    // 辅助函数
    void updateDisplay();                         // 统一更新两个显示框
    QString getSignChar(Sign s) const;            // 获取运算符字符
    double performOperation(double a, double b, Sign op); // 执行运算
    void performCalculation();                    // 连续运算符时完成上次计算
    void numButtonClicked(int n);                 // 数字处理
    void signButtonClicked(Sign s);               // 运算符处理
    void resetDecimalState();                     // 重置小数状态
    void parseNumberFromFormula(const QString& formula, bool isNum2); // 从公式字符串解析数字并更新对应变量
};

#endif // WIDGET_H