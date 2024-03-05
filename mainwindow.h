#ifndef MAINWINDOW_H // include guard
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void on_PrevButton_clicked();
    void on_PauseButton_clicked();
    void on_ResButton_clicked();
    void on_SkipButton_clicked();
    void on_GoButton_clicked();
private slots:
    void on_LoopToggle_toggled(bool checked);
    void on_AddButton_clicked();
    void on_ClearButton_clicked();
    void on_DeleteButton_clicked();
    void on_FadeBox_stateChanged(int arg1);
    void on_FadeBox_clicked(bool checked);
    void on_LoopBox_stateChanged(int arg1);
    void on_RestartButton_clicked();
    void on_ShuffleButton_clicked();
    void on_StopButton_clicked();
    void on_VolDownButton_clicked();
    void on_VolUpButton_clicked();

private:
    Ui::MainWindow *ui;
    commandProcessing cmd;
    songQueue q;
};
#endif // MAINWINDOW_H
