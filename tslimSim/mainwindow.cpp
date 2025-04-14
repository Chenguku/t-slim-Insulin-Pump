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

    //passcode setup
    passcode = 1234;

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
     * 0: Lock Screen
     * 1: Power On Page
     * 2: Home Page
     * 3: CGM Home Page
     * 4: Bolus Page
     * 5: Carbs Calculator
     * 6: Glucose Modifier
     * 7: Options Page
     * 8: My Pump Page
     * 9: Personal Profiles Page
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

    //functions for the lockscreen page
    connect(ui->lockScreen_enterButton, SIGNAL(released()), this, SLOT(submitPasscode()));
    connect(ui->lockScreen_deleteButton, SIGNAL(released()), this, SLOT(lsDeleteButton()));
    connect(ui->lockScreen_b0, SIGNAL(released()), this, SLOT(lsButtonZero()));
    connect(ui->lockScreen_b1, SIGNAL(released()), this, SLOT(lsButtonOne()));
    connect(ui->lockScreen_b2, SIGNAL(released()), this, SLOT(lsButtonTwo()));
    connect(ui->lockScreen_b3, SIGNAL(released()), this, SLOT(lsButtonThree()));
    connect(ui->lockScreen_b4, SIGNAL(released()), this, SLOT(lsButtonFour()));
    connect(ui->lockScreen_b5, SIGNAL(released()), this, SLOT(lsButtonFive()));
    connect(ui->lockScreen_b6, SIGNAL(released()), this, SLOT(lsButtonSix()));
    connect(ui->lockScreen_b7, SIGNAL(released()), this, SLOT(lsButtonSeven()));
    connect(ui->lockScreen_b8, SIGNAL(released()), this, SLOT(lsButtonEight()));
    connect(ui->lockScreen_b9, SIGNAL(released()), this, SLOT(lsButtonNine()));
}

void MainWindow::openPowerScreen(){
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::openHome(){
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::openCGM(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::openBolus(){
    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::openCarbs(){
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::openGlucose(){
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::openOptions(){
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::openMyPump(){
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::openPersonalProfiles(){
    ui->stackedWidget->setCurrentIndex(9);
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

void MainWindow::stopCharging(){
     powerOnTimer->stop();
}

// The next few functions are for the pin lock screen
void MainWindow::submitPasscode(){
    if (ui->passcodeLabel->text().toInt() == passcode){
        ui->stackedWidget->setCurrentIndex(1);
        ui->passcodeIncorrectLabel->setText("");
    }
    else{
        ui->passcodeLabel->setText("");
        ui->passcodeIncorrectLabel->setText("Incorrect Passcode");
    }
}

void MainWindow::lsDeleteButton(){
    if (ui->passcodeLabel->text() == "") return;
    else{
        QString temp = ui->passcodeLabel->text();
        temp.chop(1);
        ui->passcodeLabel->setText(temp);
    }
}

void MainWindow::lsButtonOne(){
    QString curPasscode = ui->passcodeLabel->text();
    ui->passcodeLabel->setText(curPasscode + "1");
}

void MainWindow::lsButtonTwo(){
    QString curPasscode = ui->passcodeLabel->text();
    ui->passcodeLabel->setText(curPasscode + "2");
}

void MainWindow::lsButtonThree(){
    QString curPasscode = ui->passcodeLabel->text();
    ui->passcodeLabel->setText(curPasscode + "3");
}

void MainWindow::lsButtonFour(){
    QString curPasscode = ui->passcodeLabel->text();
    ui->passcodeLabel->setText(curPasscode + "4");
}

void MainWindow::lsButtonFive(){
    QString curPasscode = ui->passcodeLabel->text();
    ui->passcodeLabel->setText(curPasscode + "5");
}

void MainWindow::lsButtonSix(){
    QString curPasscode = ui->passcodeLabel->text();
    ui->passcodeLabel->setText(curPasscode + "6");
}

void MainWindow::lsButtonSeven(){
    QString curPasscode = ui->passcodeLabel->text();
    ui->passcodeLabel->setText(curPasscode + "7");
}

void MainWindow::lsButtonEight(){
    QString curPasscode = ui->passcodeLabel->text();
    ui->passcodeLabel->setText(curPasscode + "8");
}

void MainWindow::lsButtonNine(){
    QString curPasscode = ui->passcodeLabel->text();
    ui->passcodeLabel->setText(curPasscode + "9");
}

void MainWindow::lsButtonZero(){
    QString curPasscode = ui->passcodeLabel->text();
    ui->passcodeLabel->setText(curPasscode + "0");
}

//getters
Profile* MainWindow::getCurProfile() const { return curProfile; }

//setters
void MainWindow::setPasscode(int i){
    passcode = i;
}

MainWindow::~MainWindow()
{
    delete ui;
}

