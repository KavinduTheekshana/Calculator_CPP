#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
bool userIsTypingSecondNumber = false;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_passed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_passed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_passed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_passed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_passed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_passed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_passed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_passed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_passed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_passed()));

    connect(ui->pushButton_plusMinus,SIGNAL(released()),this,SLOT(unary_operation_passed()));
    connect(ui->pushButton_precent,SIGNAL(released()),this,SLOT(unary_operation_passed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(binary_oparation_passed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_oparation_passed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_oparation_passed()));
    connect(ui->pushButton_devide,SIGNAL(released()),this,SLOT(binary_oparation_passed()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_devide->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_passed(){
    QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if ((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() ||
            ui->pushButton_multiply->isChecked() || ui->pushButton_devide->isChecked()) && (!userIsTypingSecondNumber))
    {

            labelNumber=button->text().toDouble();
            userIsTypingSecondNumber = true;
            newLabel = QString::number(labelNumber,'g',15);

    }else{

        if (ui->label->text().contains('.') && button->text() == "0")
        {
            newLabel = ui->label->text() + button->text();

        } else
        {
            labelNumber=(ui->label->text()+button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15);

        }

    }



    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_decimal_released()
{
    ui->label->setText(ui->label->text()+".");
}

void MainWindow::unary_operation_passed()
{
    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if (button->text()=="+/-") {
        labelNumber =ui->label->text().toDouble();
        labelNumber = labelNumber*-1;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }

    if (button->text()=="%") {
        labelNumber =ui->label->text().toDouble();
        labelNumber = labelNumber*0.01;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_devide->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->label->setText("0");
}

void MainWindow::on_pushButton_equal_released()
{
    double labelNumber,secondNum;
    secondNum = ui->label->text().toDouble();
    QString newLabel;

    if(ui->pushButton_plus->isChecked()){
        labelNumber=firstNum+secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
    }

    else if(ui->pushButton_minus->isChecked()){
        labelNumber=firstNum-secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
    }

    else if(ui->pushButton_multiply->isChecked()){
        labelNumber=firstNum*secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_multiply->setChecked(false);
    }

    else if(ui->pushButton_devide->isChecked()){
        labelNumber=firstNum/secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_devide->setChecked(false);
    }

    userIsTypingSecondNumber = false;

}

void MainWindow::binary_oparation_passed()
{
    QPushButton * button = (QPushButton*) sender();
    firstNum =ui->label->text().toDouble();
    button->setChecked(true);



}
