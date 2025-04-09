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
     * 3: Glucose Modifier
     * 4: Options Page
     * 5: My Pump Page
     * 6: Personal Profiles Page
    */
    connect(ui->homeBolus, SIGNAL(released()), this, SLOT(openBolus()));
    connect(ui->backButton, SIGNAL(released()), this, SLOT(openHome()));
    
    connect(ui->carbsButton, SIGNAL(released()), this, SLOT(openCarbs()));
    connect(ui->backButton_2, SIGNAL(released()), this, SLOT(openBolus()));

    connect(ui->glucoseButton, SIGNAL(released()), this, SLOT(openGlucose()));
    connect(ui->backButton_3, SIGNAL(released()), this, SLOT(openBolus()));
    
    connect(ui->optionsButton, SIGNAL(released()), this, SLOT(openOptions()));
    connect(ui->backButton_4, SIGNAL(released()), this, SLOT(openHome()));

    connect(ui->myPumpButton, SIGNAL(released()), this, SLOT(openMyPump()));
    connect(ui->backButton_5, SIGNAL(released()), this, SLOT(openOptions()));

    connect(ui->profilesButton, SIGNAL(released()), this, SLOT(openPersonalProfiles()));
    connect(ui->backButton_6, SIGNAL(released()), this, SLOT(openMyPump()));
}

void MainWindow::openHome(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::openBolus(){
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::openCarbs(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::openGlucose(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::openOptions(){
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::openMyPump(){
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::openPersonalProfiles(){
    ui->stackedWidget->setCurrentIndex(6);
}




//getters
Profile* MainWindow::getCurProfile() const { return curProfile; }


MainWindow::~MainWindow()
{
    delete ui;
}

