#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QCloseEvent>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void closeEvent(QCloseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

    void saveFile();
    bool isSaved();

private:
    void Action_N_slot();
    void Action_O_slot();
    void Action_Q_slot();
    void Action_S_slot();
    void Action_Shift_S_slot();
    void Action_M_slot();

    void Action_R_slot();
    void Action_C_slot();

    void Action_Rrow_slot();
    void Action_Rcol_slot();

    void Action_Down_slot();
    void Action_Up_slot();

    void Action_Adapt_slot();
private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    QString openName;
    bool changeFlag = false;
};
#endif // MAINWINDOW_H