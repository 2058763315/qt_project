#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , db(QSqlDatabase::addDatabase("QSQLITE"))
{
    ui->setupUi(this);

    db.setDatabaseName("test.db");
    bool ret = db.open();
    if(!ret)
    {
        QMessageBox::critical(this, "错误", "数据库打开失败：" + db.lastError().text());
        return;
    }

    QSqlQuery query;
    ret = query.exec("CREATE TABLE IF NOT EXISTS `student`("
                    "`id` INT UNSIGNED PRIMARY KEY NOT NULL,"
                     "`name` VARCHAR(128) NOT NULL);");
    if(!ret)
    {
        QMessageBox::critical(this, "错误", "创建数据表失败：" + query.lastError().text());
        close();
        return;
    }

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels({"id", "name"});

    refreshData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::refreshData()
{
    QSqlQuery query;
    bool ret = query.exec("SELECT * FROM `student`;");
    if(!ret)
    {
        QMessageBox::critical(this, "错误", "查询数据失败：" + query.lastError().text());
        return;
    }

    int i;
    int maxid = -1;
    ret = query.first();
    for(i = 0; ret; i++)
    {
        ui->tableWidget->setRowCount(i + 1);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(query.value(1).toString()));

        maxid = query.value(0).toInt();
        ret = query.next();
    }
    ui->spinBox->setValue(maxid + 1);
}

void Widget::on_pushButton_add_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::critical(this, "错误", "请输入姓名！");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO `student` VALUES( :id, :name);");
    query.bindValue(":id", ui->spinBox->value());
    query.bindValue(":name", ui->lineEdit->text());

    bool ret = query.exec();
    if(!ret)
    {
        QMessageBox::critical(this, "错误", "插入数据失败：" + query.lastError().text());
        return;
    }

    ui->lineEdit->clear();
    refreshData();
}

void Widget::on_pushButton_exe_clicked()
{
    if(ui->textEdit->toPlainText().isEmpty())
    {
        QMessageBox::critical(this, "错误", "请输入语句！");
        return;
    }

    QSqlQuery query;
    bool ret = query.exec(ui->textEdit->toPlainText());
    if(!ret)
    {
        QMessageBox::critical(this, "错误", "插入数据失败：" + query.lastError().text());
        return;
    }
    refreshData();
}
