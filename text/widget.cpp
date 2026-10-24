#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QFontMetrics>
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_text("国之印信在此，还不速速跪下")
    , m_offset(0)
    , m_timer(new QTimer(this))
{
    ui->setupUi(this);

    // 初始化偏移量（从右侧开始）
    m_offset = width();

    // 定时器驱动滚动
    connect(m_timer, &QTimer::timeout, this, &Widget::updateOffset);
    m_timer->start(30); // 约33帧/秒

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing |
                           QPainter::TextAntialiasing |
                           QPainter::SmoothPixmapTransform);

    // 背景图片（拉伸填满整个窗口）
    QPixmap pm(":/1.png");
    painter.drawPixmap(0, 0, width(), height(), pm);

    // 文字样式
    QFont font("经典繁方篆", 150);
    painter.setFont(font);
    QPen pen(QColor(217, 98, 115));
    painter.setPen(pen);

    // 计算文字尺寸
    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(m_text);
    int textHeight = fm.height();

    // 可用绘制区域（避开底部输入框）
    int inputHeight = ui->lineEdit->height() + 10; // 输入框高度 + 边距
    int availableHeight = height() - inputHeight;
    int y = (availableHeight - textHeight) / 2 + fm.ascent(); // 垂直居中（基线位置）

    // 绘制滚动文字
    painter.drawText(m_offset, y, m_text);
}

void Widget::onTextChanged(const QString &text)
{
    if (text.isEmpty()) {
        m_text = "国之印信在此，还不速速跪下";
    } else {
        m_text = text;
    }
    // 新文字从右侧重新进入
    m_offset = width();
    update();
}

void Widget::updateOffset()
{
    m_offset -= 2; // 每帧左移2像素，速度可调

    // 计算当前文字宽度
    QFontMetrics fm(font());
    int textWidth = fm.horizontalAdvance(m_text);

    // 如果文字完全移出左侧，则从右侧重新出现
    if (m_offset + textWidth < 0) {
        m_offset = width();
    }

    update(); // 触发重绘
}

int Widget::getTextWidth() const
{
    QFontMetrics fm(font());
    return fm.horizontalAdvance(m_text);
}

void Widget::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    if (str.isEmpty()) {
        return;
    } else {
        m_text = str;
    }
    m_offset = width();
    update();
}

