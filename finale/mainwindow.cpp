#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"ajout.h"
#include "suppression.h"

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

void MainWindow::on_pushButton_clicked()
{
    ajout a;
    a.exec();

}


void MainWindow::on_pushButton_2_clicked()
{
    suppression s;
    s.exec();

}

