#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include<QMessageBox>
#include "Expression.h"
#include "parser.h"
#include "history.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Off_clicked();

    void on_Backspace_clicked();

    void on_Add_clicked();

    void on_Sub_clicked();

    void on_Mul_clicked();

    void on_Div_clicked();

    void on_Pow_clicked();

    void on_Zero_clicked();

    void on_One_clicked();

    void on_Two_clicked();

    void on_Three_clicked();

    void on_Four_clicked();

    void on_Five_clicked();

    void on_Six_clicked();

    void on_Seven_clicked();

    void on_Eight_clicked();

    void on_Nine_clicked();

    void on_Point_clicked();

    void on_Sqrt_clicked();

    void on_Sin_clicked();

    void on_Cos_clicked();

    void on_Tan_clicked();

    void on_Ln_clicked();

    void on_Exp_clicked();

    void on_OpenBraket_clicked();

    void on_CloseBraket_clicked();

    void on_Drop_clicked();

    void keyPressEvent(QKeyEvent *event);

    void on_Equal_clicked();

    void on_History_clicked();

private:
    Ui::MainWindow *ui;
    Expression expres;
    Parser pars;
    History hist;
    bool open = false;
};
#endif // MAINWINDOW_H
