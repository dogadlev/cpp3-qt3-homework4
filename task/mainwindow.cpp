#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gb_radio_buttons->setTitle("Скорость");
    ui->rb_upper->setText("Скорость по умолчанию");
    ui->rb_lower->setText("Ускорить в два раза");
    ui->pb_button->setText("Увеличить");

    ui->rb_upper->setChecked(true);
    for(int i = 1; i<=10; ++i)
        ui->lst_elements->addItem("Элемент " + QString::number(i));
    ui->pb_button->setCheckable(true);
    ui->prbr_bar->setMinimum(0);
    ui->prbr_bar->setMaximum(10);
    ui->prbr_bar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_button_clicked()
{
    if(ui->rb_upper->isChecked()) {
        int tmp = ui->prbr_bar->value() + (ui->prbr_bar->maximum() - ui->prbr_bar->minimum()) / 10;
        if(tmp <= ui->prbr_bar->maximum())
            ui->prbr_bar->setValue(tmp);
        else
            ui->prbr_bar->setValue(0);
    } else {
        int tmp = ui->prbr_bar->value() + (ui->prbr_bar->maximum() - ui->prbr_bar->minimum()) / 5;
        if(tmp <= ui->prbr_bar->maximum())
            ui->prbr_bar->setValue(tmp);
        else
            ui->prbr_bar->setValue(0);
    }
}

