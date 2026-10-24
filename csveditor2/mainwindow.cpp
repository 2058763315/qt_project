#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->action_N, &QAction::triggered, this, &MainWindow::Action_N_slot);
    connect(ui->action_M, &QAction::triggered, this, &MainWindow::Action_M_slot);
    connect(ui->action_O, &QAction::triggered, this, &MainWindow::Action_O_slot);
    connect(ui->action_Q, &QAction::triggered, this, &MainWindow::Action_Q_slot);
    connect(ui->action_S, &QAction::triggered, this, &MainWindow::Action_S_slot);
    connect(ui->action_Shift_S, &QAction::triggered, this, &MainWindow::Action_Shift_S_slot);

    connect(ui->action_R, &QAction::triggered, this, &MainWindow::Action_R_slot);
    connect(ui->action_C, &QAction::triggered, this, &MainWindow::Action_C_slot);

    connect(ui->action_Rrow, &QAction::triggered, this, &MainWindow::Action_Rrow_slot);
    connect(ui->action_Rcol, &QAction::triggered, this, &MainWindow::Action_Rcol_slot);

    connect(ui->action_Down, &QAction::triggered, this, &MainWindow::Action_Down_slot);
    connect(ui->action_Up, &QAction::triggered, this, &MainWindow::Action_Up_slot);

    connect(ui->action_Adapt, &QAction::triggered, this, &MainWindow::Action_Adapt_slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if(changeFlag && !isSaved())
    {
        event->ignore();
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if(event->isAutoRepeat() && event->key() != Qt::Key_D && event->key() != Qt::Key_U)
    {
        return;
    }

    if(event->modifiers() == Qt::ControlModifier)
    {
        switch(event->key())
        {
        case Qt::Key_N : Action_N_slot(); break;
        case Qt::Key_O : Action_O_slot(); break;
        case Qt::Key_S : Action_S_slot(); break;
        case Qt::Key_Q : Action_Q_slot(); break;
        case Qt::Key_M : Action_M_slot(); break;
        default:;
        }
    }

    if(event->modifiers() == (Qt::ControlModifier | Qt::ShiftModifier))
    {
        switch(event->key())
        {
        case Qt::Key_S : Action_Shift_S_slot(); break;
        case Qt::Key_R : Action_R_slot(); break;
        case Qt::Key_C : Action_C_slot(); break;
        case Qt::Key_D : Action_Down_slot(); break;
        case Qt::Key_U : Action_Up_slot(); break;
        default:;
        }
    }
}

bool MainWindow::isSaved()
{
    auto ret = QMessageBox::question(this, "CSV编辑器", "文件已修改，是否要保存文件",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    switch(ret)
    {
    case QMessageBox::Yes :
        Action_S_slot();
        if(openName.isEmpty())
        {
            return false;
        }
        else
        {
            return true;
        }
    case QMessageBox::No : return true;
    case QMessageBox::Cancel : return false;
    default:;
    }
    return false;
}

void MainWindow::Action_N_slot()
{
    if(changeFlag && !isSaved())
    {
        return;
    }

    openName.clear();
    ui->tableWidget->clear();
    changeFlag = false;
}

void MainWindow::Action_O_slot()
{
    if(changeFlag && !isSaved())
    {
        return;
    }

    QString tmp = QFileDialog::getOpenFileName(this, "打开", "D:/");
    if(tmp.isEmpty())
    {
        return;
    }
    openName = tmp;

    QFile qf(openName);

    bool ret = qf.open(QIODevice::ReadOnly);
    if(!ret)
    {
        QMessageBox::critical(this, "CSV编辑器", "打开文件出错！");
        return;
    }

    ui->tableWidget->clear();
    QString line = qf.readLine();
    QStringList lineData;
    int maxColCount = 0;
    int i, j;
    for(i = 0; !line.isEmpty(); i++)
    {
        ui->tableWidget->insertRow(i);
        lineData = line.trimmed().split(",");
        if(lineData.size() > maxColCount)
        {
            maxColCount = lineData.size();
            ui->tableWidget->setColumnCount(maxColCount);
        }

        for(j = 0; j < lineData.size(); j++)
        {
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(lineData[j]));
        }
        line = qf.readLine();
    }

    qf.close();
    changeFlag = false;

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void MainWindow::Action_Q_slot()
{
    close();
}

void MainWindow::saveFile()
{
    QFile qf(openName);

    bool ret = qf.open(QIODevice::WriteOnly);
    if(!ret)
    {
        QMessageBox::critical(this, "CSV编辑器", "保存文件出错！");
        return;
    }

    QStringList strl;
    int i, j;
    for(i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        for(j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            QTableWidgetItem* item = ui->tableWidget->item(i, j);
            if(item)
            {
                strl.append(item->text());
            }
            else
            {
                strl.append("");
            }
        }
        qf.write((strl.join(",") + "\r\n").toUtf8());
        strl.clear();
    }
    qf.close();
}

void MainWindow::Action_S_slot()
{
    if(openName.isEmpty())
    {
        QString tmp = QFileDialog::getSaveFileName(this, "保存文件", "D:/");
        if(tmp.isEmpty())
        {
            return;
        }

        openName = tmp;
    }

    saveFile();
    changeFlag = false;
}

void MainWindow::Action_Shift_S_slot()
{
    QString tmp = QFileDialog::getSaveFileName(this, "保存文件", "D:/");
    if(tmp.isEmpty())
    {
        return;
    }

    openName = tmp;

    saveFile();
    changeFlag = false;
}

void MainWindow::Action_M_slot()
{
    QMessageBox::information(this, "关于", "一个CSV编辑软件");
}

void MainWindow::Action_R_slot()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void MainWindow::Action_C_slot()
{
    ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
}

void MainWindow::Action_Rrow_slot()
{
    if (!ui->tableWidget) return;

    int rowCount = ui->tableWidget->rowCount();
    if (rowCount <= 0) return; // 没有行可删

    int lastRow = rowCount - 1;
    int colCount = ui->tableWidget->columnCount();

    bool hasContent = false;
    for(int col = 0;col < colCount; col++)
    {
        QTableWidgetItem* item = ui->tableWidget->item(lastRow, col);
        if (item) {
            QString text = item->text().trimmed();
            if (!text.isEmpty()) {
                hasContent = true;
                break;
            }
        }
    }
    if(hasContent)
    {
        auto ret = QMessageBox::question(this, "询问", "尾行有数据，确定要删除吗");
        if(ret != QMessageBox::Yes)
        {
            return;
        }
    }

    ui->tableWidget->removeRow(lastRow);
}

void MainWindow::Action_Rcol_slot()
{
    if (!ui->tableWidget) return;

    int colCount = ui->tableWidget->columnCount();
    if (colCount <= 0) return; // 没有列可删

    int lastCol = colCount - 1;
    int rowCount = ui->tableWidget->rowCount();

    bool hasContent = false;
    for(int row = 0; row < rowCount; row++)
    {
        QTableWidgetItem* item = ui->tableWidget->item(row, lastCol);
        if (item) {
            QString text = item->text().trimmed();
            if (!text.isEmpty()) {
                hasContent = true;
                break;
            }
        }
    }
    if(hasContent)
    {
        auto ret = QMessageBox::question(this, "询问", "尾列有数据，确定要删除吗");
        if(ret != QMessageBox::Yes)
        {
            return;
        }
    }
    ui->tableWidget->removeColumn(lastCol);
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    Q_UNUSED(index);
    changeFlag = true;
}

void MainWindow::Action_Up_slot()   // 增大表格字体
{
    QFont font = ui->tableWidget->font();
    int newSize = font.pointSize() + 1;
    if (newSize > 72) newSize = 72;
    font.setPointSize(newSize);
    ui->tableWidget->setFont(font);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void MainWindow::Action_Down_slot()     // 减小表格字体
{
    QFont font = ui->tableWidget->font();
    int newSize = font.pointSize() - 1;
    if (newSize < 6) newSize = 6;
    font.setPointSize(newSize);
    ui->tableWidget->setFont(font);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void MainWindow::Action_Adapt_slot()
{
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}