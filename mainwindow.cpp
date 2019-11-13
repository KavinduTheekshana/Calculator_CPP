#include "mainwindow.h"
#include "ui_mainwindow.h"


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

    labelNumber=(ui->label->text()+button->text()).toDouble();
    newLabel = QString::number(labelNumber,'g',15);
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
    ui->label->setText(NULL);
}

void MainWindow::on_pushButton_equal_released()
{

}

void MainWindow::binary_oparation_passed()
{
    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;


    if (button->text()=="+") {

    }


}
