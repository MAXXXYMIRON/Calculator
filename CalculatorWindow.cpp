#include "CalculatorWindow.h"
#include "ui_CalculatorWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlag(Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->Hist->setVisible(open);
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

void MainWindow::on_Equal_clicked()
{
    if(!expres.RightExpression()) return;

    hist.WriteHist(expres.GetExpression());
    expres.SetExpression(parser.ParsingExpression(expres.GetExpression()));
    hist.WriteHist("= " + expres.GetExpression());

    ui->Expression->setText(QString::fromStdString(expres.GetExpression()));
}

void MainWindow::on_History_clicked()
{
    try
    {
        vector<string> h = hist.GetHistory();
        ui->Hist->setPlainText("");
        open = !open;
        ui->Hist->setVisible(open);
        for(unsigned i = 0; i < h.size(); i++)
        {
            ui->Hist->appendPlainText(QString::fromStdString(h[i]));
        }
    }
    catch (History::ERRORS e)
    {
        QMessageBox::warning(this, "Внимание", "История вычислений пуста");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        on_Off_clicked();
        break;
    case Qt::Key_Backspace:
        on_Backspace_clicked();
        break;
    case Qt::Key_Plus:
        on_Add_clicked();
        break;
    case Qt::Key_Minus:
        on_Sub_clicked();
        break;
    case Qt::Key_Asterisk:
        on_Mul_clicked();
        break;
    case Qt::Key_Slash:
        on_Div_clicked();
        break;
    case Qt::Key_AsciiCircum:
        on_Pow_clicked();
        break;
    case Qt::Key_0:
        on_Zero_clicked();
        break;
    case Qt::Key_1:
        on_One_clicked();
        break;
    case Qt::Key_2:
        on_Two_clicked();
        break;
    case Qt::Key_3:
        on_Three_clicked();
        break;
    case Qt::Key_4:
        on_Four_clicked();
        break;
    case Qt::Key_5:
        on_Five_clicked();
        break;
    case Qt::Key_6:
        on_Six_clicked();
        break;
    case Qt::Key_7:
        on_Seven_clicked();
        break;
    case Qt::Key_8:
        on_Eight_clicked();
        break;
    case Qt::Key_9:
        on_Nine_clicked();
        break;
    case Qt::Key_Period:
        on_Point_clicked();
        break;
    case Qt::Key_Q:
        on_Sqrt_clicked();
        break;
    case Qt::Key_S:
        on_Sin_clicked();
        break;
    case Qt::Key_C:
        on_Cos_clicked();
        break;
    case Qt::Key_T:
        on_Tan_clicked();
        break;
    case Qt::Key_L:
        on_Ln_clicked();
        break;
    case Qt::Key_E:
        on_Exp_clicked();
        break;
    case Qt::Key_ParenLeft:
        on_OpenBraket_clicked();
        break;
    case Qt::Key_ParenRight:
        on_CloseBraket_clicked();
        break;
    case Qt::Key_End:
        on_Drop_clicked();
        break;
    case Qt::Key_Enter:
        on_Equal_clicked();
        break;
    case Qt::Key_H:
        on_History_clicked();
        break;
    }
}
