#include "CalculatorWindow.h"
#include "ui_CalculatorWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlag(Qt::FramelessWindowHint);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Off_clicked()
{
    close();
}

void MainWindow::on_Backspace_clicked()
{

}
