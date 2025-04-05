#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    /*
     * Connecting slots to change pages
     * Page Indices
     * 0: Home Page
     * 1: Bolus Page
     * 2: Carbs Calculator
    */
    connect(ui->homeBolus, SIGNAL(released()), this, SLOT(openBolus()));
    connect(ui->backButton, SIGNAL(released()), this, SLOT(openHome()));
    connect(ui->carbsButton, SIGNAL(released()), this, SLOT(openCarbs()));
    connect(ui->backButton_2, SIGNAL(released()), this, SLOT(openBolus()));
}

void MainWindow::openHome(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::openBolus(){
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::openOptions(){

}

void MainWindow::openCarbs(){
    ui->stackedWidget->setCurrentIndex(2);
}


MainWindow::~MainWindow()
{
    delete ui;
}

