#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <cmath>
#include <QIcon> // 包含头文件

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , num1(0.0)
    , num2(0.0)
    , origNum1(0.0)
    , lastOperand(0.0)
    , sign(ADD)
    , lastSign(ADD)
    , signFlag(false)
    , eqFlag(false)
    , decimalFlag(false)
    , decimalFactor(10.0)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/calculator-icon.ico"));
    this->setFixedSize(500, 600);
    updateDisplay();
}

Widget::~Widget()
{
    delete ui;
}

// ==================== 辅助函数 ====================

void Widget::resetDecimalState()
{
    decimalFlag = false;
    decimalFactor = 10.0;
}

void Widget::parseNumberFromFormula(const QString& formula, bool isNum2)
{
    // 解析公式中的数字部分（第一个数或第二个数）
    QString numStr;
    if (isNum2) {
        int pos = formula.lastIndexOf(' ');
        if (pos != -1) {
            numStr = formula.mid(pos + 1);
        } else {
            numStr = "0";
        }
    } else {
        // 第一个数可能包含符号（如 '-'），但 formula 以数字开头
        numStr = formula;
        // 如果公式包含运算符，则截取运算符前的部分
        int opPos = formula.indexOf(' ');
        if (opPos != -1) {
            numStr = formula.left(opPos);
        }
    }

    bool ok;
    double val = numStr.toDouble(&ok);
    if (!ok) val = 0.0;

    // 更新对应的变量
    if (isNum2) {
        num2 = val;
    } else {
        num1 = val;
        origNum1 = val; // 同步原始值
    }

    // 检测是否包含小数点，更新小数状态
    if (numStr.contains('.')) {
        decimalFlag = true;
        // 计算小数位数，设置 decimalFactor
        int dotPos = numStr.indexOf('.');
        int digitsAfterDot = numStr.length() - dotPos - 1;
        decimalFactor = std::pow(10.0, digitsAfterDot + 1); // 下一位的权重
    } else {
        resetDecimalState();
    }
}

void Widget::updateDisplay()
{
    // 辅助函数：将 double 转为 QString，若 decimalFlag 为 true 且数字为整数，则追加 '.'
    auto numToStr = [&](double val) -> QString {
        QString s = QString::number(val);
        if (decimalFlag && !s.contains('.')) {
            s += '.';
        }
        return s;
    };

    QString formula;
    QString resultText;

    if (eqFlag) {
        // 等于状态：显示完整等式
        QString op = getSignChar(lastSign);
        formula = numToStr(origNum1) + " " + op + " " +
                  numToStr(lastOperand) + " =";
        resultText = numToStr(num1);
    } else if (signFlag) {
        // 输入运算符后，正在输入第二个数
        QString op = getSignChar(sign);
        formula = numToStr(num1) + " " + op + " " + numToStr(num2);
        resultText = numToStr(num2);
    } else {
        // 只输入了第一个数（或初始）
        formula = numToStr(num1);
        resultText = numToStr(num1);
    }

    ui->LineEdit_1->setText(formula);
    ui->LineEdit->setText(resultText);
}

QString Widget::getSignChar(Sign s) const
{
    switch (s) {
    case ADD: return "+";
    case SUB: return "-";
    case MUL: return "×";
    case DIV: return "÷";
    default: return "";
    }
}

double Widget::performOperation(double a, double b, Sign op)
{
    switch (op) {
    case ADD: return a + b;
    case SUB: return a - b;
    case MUL: return a * b;
    case DIV:
        if (b == 0.0) {
            ui->LineEdit->setText("Error");
            return 0.0;
        }
        return a / b;
    default: return 0.0;
    }
}

// 在 eqFlag=true 时，完成上次运算，并将结果作为新运算的第一个数
void Widget::performCalculation()
{
    if (!eqFlag) return;
    double result = performOperation(num1, lastOperand, lastSign);
    num1 = result;
    origNum1 = num1;   // 结果作为新运算的起始操作数
    eqFlag = false;
    resetDecimalState(); // 重置小数状态
}

// ==================== 数字按键 ====================

void Widget::numButtonClicked(int n)
{
    if (eqFlag) {
        // 刚计算完，按数字重新开始
        on_pushButton_C_clicked();
    }

    if (signFlag) {
        // 正在输入第二个数
        if (decimalFlag) {
            num2 += n / decimalFactor;
            decimalFactor *= 10.0;
        } else {
            num2 = num2 * 10 + n;
        }
        updateDisplay();
    } else {
        // 输入第一个数
        if (decimalFlag) {
            num1 += n / decimalFactor;
            decimalFactor *= 10.0;
        } else {
            num1 = num1 * 10 + n;
        }
        origNum1 = num1;   // 同步更新原始操作数
        updateDisplay();
    }
}

void Widget::on_pushButton_0_clicked(){ numButtonClicked(0); }
void Widget::on_pushButton_1_clicked(){ numButtonClicked(1); }
void Widget::on_pushButton_2_clicked(){ numButtonClicked(2); }
void Widget::on_pushButton_3_clicked(){ numButtonClicked(3); }
void Widget::on_pushButton_4_clicked(){ numButtonClicked(4); }
void Widget::on_pushButton_5_clicked(){ numButtonClicked(5); }
void Widget::on_pushButton_6_clicked(){ numButtonClicked(6); }
void Widget::on_pushButton_7_clicked(){ numButtonClicked(7); }
void Widget::on_pushButton_8_clicked(){ numButtonClicked(8); }
void Widget::on_pushButton_9_clicked(){ numButtonClicked(9); }

// ==================== 小数点 ====================

void Widget::on_pushButton_dian_clicked()
{
    if (eqFlag) {
        // 刚计算完，按小数点开始输入小数（相当于重新开始）
        on_pushButton_C_clicked();
    }

    if (decimalFlag) {
        // 已有小数点，忽略
        return;
    }

    decimalFlag = true;
    decimalFactor = 10.0;

    // 如果当前没有数字，自动补0
    if (signFlag) {
        if (num2 == 0.0) {
            // 显示"0."，但我们的数值还是0，显示会变成"0"，但加小数点后显示应为"0."
            // 因此我们需要在显示中体现小数点，可以使用显示字符串，但为了保持简单，我们允许显示为"0"
            // 但用户期望看到"0."，所以我们可以在显示时特殊处理。
            // 更简单的方法：使用字符串输入方式。鉴于代码已定，我们保持数值，显示会丢失末尾小数点。
            // 我们可以临时在updateDisplay中判断，但这会复杂化。
            // 一个折中：在显示时，如果decimalFlag为true且数字为0，则显示为"0."。
            // 在updateDisplay中，如果signFlag且num2==0且decimalFlag，则显示"0."。
        }
    } else {
        if (num1 == 0.0) {
            // 类似处理
        }
    }
    updateDisplay();
}

// ==================== 运算符 ====================

void Widget::signButtonClicked(Sign s)
{
    if (eqFlag) {
        // 等号后按运算符：以当前结果作为新运算的第一个数，直接开始
        eqFlag = false;
        origNum1 = num1;          // 更新为当前结果
        // 不要调用 performCalculation()
    } else if (signFlag) {
        // 已有运算符且正在输入第二个数：先完成本次运算
        double result = performOperation(num1, num2, sign);
        num1 = result;
        origNum1 = num1;
        lastSign = sign;
        lastOperand = num2;
    }

    // 设置新运算符
    sign = s;
    signFlag = true;
    num2 = 0.0;
    resetDecimalState();
    updateDisplay();
}

void Widget::on_pushButton_ADD_clicked(){ signButtonClicked(ADD); }
void Widget::on_pushButton_SUB_clicked(){ signButtonClicked(SUB); }
void Widget::on_pushButton_MUL_clicked(){ signButtonClicked(MUL); }
void Widget::on_pushButton_DIV_clicked(){ signButtonClicked(DIV); }

// ==================== 功能键 ====================

// 退格
void Widget::on_pushButton_back_clicked()
{
    if (eqFlag) {
        on_pushButton_C_clicked();
        return;
    }

    QString formula = ui->LineEdit_1->text();
    if (formula.isEmpty() || formula == "0") return;

    formula.chop(1);
    if (formula.isEmpty() || formula == "-") {
        // 清空变为0
        if (signFlag) {
            num2 = 0.0;
        } else {
            num1 = 0.0;
            origNum1 = 0.0;
        }
        resetDecimalState();
        updateDisplay();
        return;
    }

    // 重新解析数字并更新变量
    if (signFlag) {
        parseNumberFromFormula(formula, true);
    } else {
        parseNumberFromFormula(formula, false);
    }
    ui->LineEdit_1->setText(formula);
    updateDisplay();
}

// 全部清除
void Widget::on_pushButton_C_clicked()
{
    num1 = 0.0;
    num2 = 0.0;
    origNum1 = 0.0;
    lastOperand = 0.0;
    signFlag = false;
    eqFlag = false;
    sign = ADD;
    lastSign = ADD;
    resetDecimalState();
    updateDisplay();
}

// 清除当前输入
void Widget::on_pushButton_CE_clicked()
{
    if (eqFlag) {
        on_pushButton_C_clicked();
        return;
    }

    if (signFlag) {
        num2 = 0.0;
    } else {
        num1 = 0.0;
        origNum1 = 0.0;
    }
    resetDecimalState();
    updateDisplay();
}

// 正负号切换
void Widget::on_pushButton_MP_clicked()
{
    if (eqFlag) {
        num1 = -num1;
        origNum1 = num1;
        updateDisplay();
        return;
    }

    if (signFlag) {
        num2 = -num2;
    } else {
        num1 = -num1;
        origNum1 = num1;
    }
    updateDisplay();
}

// 等于
void Widget::on_pushButton_EQ_clicked()
{
    if (eqFlag) {
        // 连续等于
        double result = performOperation(num1, lastOperand, lastSign);
        origNum1 = num1;     // 保存本次运算的第一个操作数（即旧结果）
        num1 = result;
        updateDisplay();
        return;
    }

    if (!signFlag) {
        // 没有运算符，直接标记等于状态
        eqFlag = true;
        lastSign = sign;
        lastOperand = num2;
        origNum1 = num1;
        resetDecimalState();
        updateDisplay();
        return;
    }

    // 执行运算
    double result = performOperation(num1, num2, sign);
    lastSign = sign;
    lastOperand = num2;
    origNum1 = num1;
    num1 = result;
    signFlag = false;
    eqFlag = true;
    num2 = 0.0;
    resetDecimalState();
    updateDisplay();
}