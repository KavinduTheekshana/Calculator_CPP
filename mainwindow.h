#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_passed();
    void on_pushButton_decimal_released();

    void unary_operation_passed();
    void on_pushButton_clear_released();
    void on_pushButton_equal_released();

    void binary_oparation_passed();
};

#endif // MAINWINDOW_H
