#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    this->show();

    my_login.show();

    connect(&my_login,&page_login::sendLoginSuccess,this,&MainWindow::login);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login(){

    my_login.hide();
    this->show();
}
