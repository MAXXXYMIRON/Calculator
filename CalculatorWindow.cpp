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
    expres.Backspace();
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Add_clicked()
{
    expres.AddBehindOperations('+');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Sub_clicked()
{
    expres.AddBehindOperations('-');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Mul_clicked()
{
    expres.AddBehindOperations('*');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Div_clicked()
{
    expres.AddBehindOperations('/');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Pow_clicked()
{
    expres.AddBehindOperations('^');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Zero_clicked()
{
    expres.AddDigit('0');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_One_clicked()
{
    expres.AddDigit('1');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Two_clicked()
{
    expres.AddDigit('2');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Three_clicked()
{
    expres.AddDigit('3');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Four_clicked()
{
    expres.AddDigit('4');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Five_clicked()
{
    expres.AddDigit('5');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Six_clicked()
{
    expres.AddDigit('6');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Seven_clicked()
{
    expres.AddDigit('7');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Eight_clicked()
{
    expres.AddDigit('8');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Nine_clicked()
{
    expres.AddDigit('9');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Point_clicked()
{
    expres.AddPoint();
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Sqrt_clicked()
{
    expres.AddInFrontOperation("√");
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Sin_clicked()
{
    expres.AddInFrontOperation("Sin");
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Cos_clicked()
{
    expres.AddInFrontOperation("Cos");
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Tan_clicked()
{
    expres.AddInFrontOperation("Tan");
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Ln_clicked()
{
    expres.AddInFrontOperation("Ln");
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Exp_clicked()
{
    expres.AddInFrontOperation("Exp");
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_OpenBraket_clicked()
{
    expres.AddBracket('(');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_CloseBraket_clicked()
{
    expres.AddBracket(')');
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_Drop_clicked()
{
    expres.Drop();
    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}
