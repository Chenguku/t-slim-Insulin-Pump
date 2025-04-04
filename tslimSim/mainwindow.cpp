#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->homeBolus, SIGNAL(released()), this, SLOT(openBolus()));
    connect(ui->homeOptions, SIGNAL(released()), this, SLOT(openOptions()));
}

void MainWindow::openBolus(){

}

void MainWindow::openOptions(){

}


MainWindow::~MainWindow()
{
    delete ui;
}

