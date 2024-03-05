#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PrevButton_clicked(){
    cmd.previous();
}

void MainWindow::on_PauseButton_clicked(){
    cmd.pause()
}

void MainWindow::on_ResButton_clicked(){
    cmd.resume()
}

void MainWindow::on_SkipButton_clicked(){
    cmd.skip();
}

void MainWindow::on_GoButton_clicked(){
    //when go button is clicked
    //get text from input box and store in string "command"
    std::string command = ui->commandInput->text().simplified().toUtf8();
    //testing purposes:
    cmd.play("CantinaBand3.wav", q);
}

void MainWindow::on_AddButton_clicked()
{
    //get text from input box and store in string "add"
    std::string add = ui->AddInput->text().simplified().toUtf8();

}

void MainWindow::on_ClearButton_clicked()
{
    //clear queue
}

void MainWindow::on_DeleteButton_clicked()
{
    //delete from queue, store input in string "remove"
    std::string remove = ui->RemoveInput->text().simplified().toUtf8();
}

void MainWindow::on_FadeBox_stateChanged(int arg1)
{
    //fade on
}

void MainWindow::on_LoopBox_stateChanged(int arg1)
{
    //loop on
}

void MainWindow::on_RestartButton_clicked()
{
    //restart song
}

void MainWindow::on_ShuffleButton_clicked()
{
    //shuffle queue
}

void MainWindow::on_StopButton_clicked()
{
    //stop music
}

void MainWindow::on_VolDownButton_clicked()
{
    //volume down
}

void MainWindow::on_VolUpButton_clicked()
{
    //volume up
}

