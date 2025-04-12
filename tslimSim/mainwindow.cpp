#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set initial page
    ui->stackedWidget->setCurrentIndex(0);

    //setup timer for powering on the insulin pump
    powerOnTimer = new QTimer(this);

    //initialize the battery
    currentBattery = 0;

    //CGM Graph setup
    cgmLine = new QLineSeries();
    QPen dottedLine(Qt::black);
    dottedLine.setStyle(Qt::CustomDashLine);
    dottedLine.setWidth(5);
    dottedLine.setCapStyle(Qt::SquareCap);
    dottedLine.setDashPattern({0.1, 2});
    cgmLine->setPen(dottedLine);

    //sample line
    cgmLine->append(0, 8.9);
    cgmLine->append(2, 9.3);
    cgmLine->append(4, 7.2);


    cgmChart = new QChart();
    cgmChart->addSeries(cgmLine);
    cgmChart->createDefaultAxes();

    cgmView = new QChartView(cgmChart);
    cgmView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(ui->CGMGraph);
    layout->addWidget(cgmView);

    /*
     * Connecting slots to change pages
     * Page Indices
     * 0: Power On Page
     * 1: Home Page
     * 2: CGM Home Page
     * 3: Bolus Page
     * 4: Carbs Calculator
     * 5: Glucose Modifier
     * 6: Options Page
     * 7: My Pump Page
     * 8: Personal Profiles Page
    */
    connect(ui->powerScreenButton, SIGNAL(released()), this, SLOT(openPowerScreen()));
    connect(ui->powerScreenButton_2, SIGNAL(released()), this, SLOT(openPowerScreen()));
    connect(ui->homeBolus, SIGNAL(released()), this, SLOT(openBolus()));
    connect(ui->backButton, SIGNAL(released()), this, SLOT(openHome()));
    
    connect(ui->carbsButton, SIGNAL(released()), this, SLOT(openCarbs()));
    connect(ui->backButton_2, SIGNAL(released()), this, SLOT(openBolus()));
    connect(ui->homeButton, SIGNAL(released()), this, SLOT(openHome()));
    connect(ui->CGMHomeButton, SIGNAL(released()), this, SLOT(openCGM()));
    connect(ui->optionsButton_2, SIGNAL(released()), this, SLOT(openOptions()));

    //functions for the power on page
    connect(ui->powerOnButton, SIGNAL(pressed()), this, SLOT(chargePump()));
    connect(powerOnTimer, SIGNAL(timeout()), this, SLOT(increaseBattery()));
    connect(ui->powerOnButton, SIGNAL(released()), this, SLOT(stopCharging()));

    connect(ui->glucoseButton, SIGNAL(released()), this, SLOT(openGlucose()));
    connect(ui->backButton_3, SIGNAL(released()), this, SLOT(openBolus()));
    
    connect(ui->optionsButton, SIGNAL(released()), this, SLOT(openOptions()));
    connect(ui->backButton_4, SIGNAL(released()), this, SLOT(openHome()));

    connect(ui->myPumpButton, SIGNAL(released()), this, SLOT(openMyPump()));
    connect(ui->backButton_5, SIGNAL(released()), this, SLOT(openOptions()));

    connect(ui->profilesButton, SIGNAL(released()), this, SLOT(openPersonalProfiles()));
    connect(ui->backButton_6, SIGNAL(released()), this, SLOT(openMyPump()));
}

void MainWindow::openPowerScreen(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::openHome(){
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::openCGM(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::openBolus(){
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::openCarbs(){
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::openGlucose(){
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::openOptions(){
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::openMyPump(){
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::openPersonalProfiles(){
    ui->stackedWidget->setCurrentIndex(8);
}

//start timer to charge battery
void MainWindow::chargePump(){
    powerOnTimer->start(10);
}

//slot to increase the battery by 1 every 100 miliseconds
void MainWindow::increaseBattery(){
    if (ui->batteryIndicator->value() == 100){
        //stop the timer after you reach 100% battery
        powerOnTimer->stop();

        //allow the users to go to the home pages
        ui->homeButton->setEnabled(true);
        ui->CGMHomeButton->setEnabled(true);

        //on the home pages, set the battery gauge to the current battery percentage (should be 100)
        ui->battery->setValue(currentBattery);
        ui->battery_2->setValue(currentBattery);

    }
    else{
        currentBattery++;
        ui->batteryIndicator->setValue(currentBattery);
    }
}

//getters
Profile* MainWindow::getCurProfile() const { return curProfile; }

MainWindow::~MainWindow()
{
    delete ui;
}

