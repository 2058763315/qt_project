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
    if(event->isAutoRepeat())
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
        default:;
        }
    }
}

bool MainWindow::isSaved()
{
    auto ret = QMessageBox::question(this, "记事本", "文件已修改，是否要保存文件",
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
    ui->textEdit->clear();
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
        QMessageBox::critical(this, "记事本", "打开文件出错！");
        return;
    }
    ui->textEdit->clear();
    ui->textEdit->setText(qf.readAll());

    qf.close();
    changeFlag = false;
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
        QMessageBox::critical(this, "记事本", "保存文件出错！");
        return;
    }

    qf.write(ui->textEdit->toPlainText().toUtf8());

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
    QString tmp = QFileDialog::getSaveFileName(this, "另存为", "D:/");
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
    QMessageBox::information(this, "关于", "一个文本编辑软件");
}

void MainWindow::on_textEdit_textChanged()
{
    changeFlag = true;
}