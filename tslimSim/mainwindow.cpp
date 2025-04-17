#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , displayTime(QDate(2024, 11, 14), QTime(0, 0, 0)) //initialize time that is displayed to the user
    , bolusCalc(new BolusCalculator(0,0, new InsulinDeliveryProfile(0,0,1,5, QTime(0, 0)), 5, 0, 0, QTime(0,0))) //initiate the bolus calculator with default values
{
    ui->setupUi(this);

    //set initial page
    ui->stackedWidget->setCurrentIndex(0);

    //setup timer for powering on the insulin pump
    powerOnTimer = new QTimer(this);

    //setup simulation time
    simulationTimer = new QTimer(this);
    simulationTime = 0;

    //initialize the battery
    currentBattery = 0;

    //initialize CGM
    GlucoseReader_Sine *cgmreader = new GlucoseReader_Sine();
    cgm = CGM();
    cgm.setBGReader(cgmreader);
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
    /*
    cgmLine->append(0, 8.9);
    cgmLine->append(2, 9.3);
    cgmLine->append(4, 7.2);
    */

    cgmChart = new QChart();
    cgmChart->addSeries(cgmLine);

    yAxis = new QValueAxis;
    yAxis->setRange(0, 12);
    yAxis->setLabelFormat("%.1f");
    yAxis->setGridLineVisible(false);
    yAxis->setMinorGridLineVisible(false);
    cgmChart->addAxis(yAxis, Qt::AlignRight);
    cgmLine->attachAxis(yAxis);
    xAxis = new QValueAxis;
    xAxis->setRange(0, 20);
    xAxis->setLabelsVisible(false);
    xAxis->setTickCount(0);
    xAxis->setGridLineVisible(false);
    xAxis->setMinorGridLineVisible(false);
    cgmChart->addAxis(xAxis, Qt::AlignBottom);
    cgmLine->attachAxis(xAxis);

    QLineSeries *upperLimit = new QLineSeries();
    upperLimit->append(0, 10);
    upperLimit->append(1000, 10);
    QPen yellowPen(Qt::yellow);
    yellowPen.setWidth(1);
    yellowPen.setStyle(Qt::SolidLine);
    upperLimit->setPen(yellowPen);
    QLineSeries *lowerLimit = new QLineSeries();
    lowerLimit->append(0, 3.9);
    lowerLimit->append(1000, 3.9);
    QPen redPen(Qt::red);
    redPen.setWidth(1);
    redPen.setStyle(Qt::SolidLine);
    lowerLimit->setPen(redPen);
    cgmChart->addSeries(lowerLimit);
    cgmChart->addSeries(upperLimit);
    lowerLimit->attachAxis(xAxis);
    lowerLimit->attachAxis(yAxis);
    upperLimit->attachAxis(xAxis);
    upperLimit->attachAxis(yAxis);


    cgmView = new QChartView(cgmChart);
    cgmView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(ui->CGMGraph);
    layout->addWidget(cgmView);



    // profiles page widget
    if (!ui->Profiles->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->ProfileForm);
        layout->setContentsMargins(0, 100, 0, 0);
        ui->Profiles->setLayout(layout);
    }
    profilesPageWidget = new ProfilesPageWidget(this);
    ui->Profiles->layout()->addWidget(profilesPageWidget);
    layout->setAlignment(profilesPageWidget, Qt::AlignLeft);


    // add profile form widget
    if (!ui->ProfileForm->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->ProfileForm);
        layout->setContentsMargins(0, 100, 0, 0);
        ui->ProfileForm->setLayout(layout);
    }
    profileFormWidget = new ProfileFormWidget(this);
    ui->ProfileForm->layout()->addWidget(profileFormWidget);
    layout->setAlignment(profileFormWidget, Qt::AlignLeft);

    //pull glucose from cgm
    pullBloodGlucose();

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
     * 9: History Options
     * 10: Personal Profiles Page
     * 11: Create Profilles Page
     * 12: History Page
     * 13: Extended Bolus Page
    */
    connect(ui->powerScreenButton, SIGNAL(released()), this, SLOT(openPowerScreen()));
    connect(ui->powerScreenButton_2, SIGNAL(released()), this, SLOT(openPowerScreen()));

    connect(ui->homeBolus, &QPushButton::released, this, [this]() {
        openBolus(true);
    });
    connect(ui->backButton, SIGNAL(released()), this, SLOT(openHome()));
    
    connect(ui->carbsButton, SIGNAL(released()), this, SLOT(openCarbs()));
    connect(ui->backButton_2, &QPushButton::released, this, [this]() {
        openBolus(false);
    });
    connect(ui->homeButton, SIGNAL(released()), this, SLOT(openHome()));
    connect(ui->CGMHomeButton, SIGNAL(released()), this, SLOT(openCGM()));
    connect(ui->optionsButton_2, SIGNAL(released()), this, SLOT(openOptions()));

    //functions for the power on page
    connect(ui->powerOnButton, SIGNAL(pressed()), this, SLOT(chargePump()));
    connect(powerOnTimer, SIGNAL(timeout()), this, SLOT(increaseBattery()));
    connect(ui->powerOnButton, SIGNAL(released()), this, SLOT(stopCharging()));

    connect(ui->glucoseButton, SIGNAL(released()), this, SLOT(openGlucose()));
    connect(ui->backButton_3, &QPushButton::released, this, [this]() {
        openBolus(false);
    });
    connect(ui->optionsButton, SIGNAL(released()), this, SLOT(openOptions()));
    connect(ui->backButton_4, SIGNAL(released()), this, SLOT(openHome()));

    connect(ui->myPumpButton, SIGNAL(released()), this, SLOT(openMyPump()));
    connect(ui->backButton_5, SIGNAL(released()), this, SLOT(openOptions()));

    connect(ui->profilesButton, SIGNAL(released()), this, SLOT(openPersonalProfiles()));
    connect(ui->backButton_6, SIGNAL(released()), this, SLOT(openMyPump()));

    connect(simulationTimer, SIGNAL(timeout()), this, SLOT(simulateBackground()));

    connect(ui->addProfileButton, SIGNAL(released()), this, SLOT(openCreateProfile()));
    connect(ui->profileForm_backButton, SIGNAL(released()), this, SLOT(openPersonalProfiles()));
    connect(ui->createProfileButton, SIGNAL(released()), this, SLOT(onCreateProfile()));
    connect(ui->pushButton_2, &QPushButton::released, this, [this]() {
        openBolus(true);
    });

    connect(ui->backButton_9, SIGNAL(released()), this, SLOT(openOptions()));
    connect(ui->historyButton, SIGNAL(released()), this, SLOT(openHistoryOptions()));
    connect(ui->backButton_10, SIGNAL(released()), this, SLOT(openHistoryOptions()));
    //add something to determine which one was pressed
    connect(ui->CGMReadingsButton, &QPushButton::released, this, [this](){
        openHistoryDisplay("CGM");
    });
    connect(ui->InsulinDeliveryButton, &QPushButton::released, this, [this](){
        openHistoryDisplay("Insulin Delivery");
    });
    connect(ui->WarningsButton, &QPushButton::released, this, [this](){
        openHistoryDisplay("Warnings");
    });

    //connnecting number carb buttons (by looping through and connecting each button, 0-9)
    for (int i = 0; i <= 9; ++i) {
        QString buttonName = QString("numberButton_%1").arg(i);
        QPushButton* button = findChild<QPushButton*>(buttonName);

        //use a lambda to connect inputNumber to the button
        connect(button, &QPushButton::released, this, [this, i]() {
            inputNumber(i, *ui->textEdit_2);
        });
    }



    //same but for the glucose buttons
    for (int i = 10; i <= 19; ++i) {
        QString buttonName = QString("numberButton_%1").arg(i);
        QPushButton* button = findChild<QPushButton*>(buttonName);

        //use a lambda to connect inputNumber to the button
        connect(button, &QPushButton::released, this, [this, i]() {
            inputNumber(i-10, *ui->textEdit_3);
        });

    }


    //connect the +/- and decimal buttonsgetFinalBolus
    connect(ui->plusButton, &QPushButton::released, this, [this]() {
        flipSign(*ui->textEdit_2);
    });
    connect(ui->decimalButton, &QPushButton::released, this, [this]() {
        addDecimal(*ui->textEdit_3);
    });
    //connect the backspace buttons
    connect(ui->XButton, &QPushButton::released, this, [this]() {
        backspace(*ui->textEdit_2);
    });
    connect(ui->XButton_2, &QPushButton::released, this, [this]() {
        backspace(*ui->textEdit_3);
    });


    //connect the "check" buttons, this will confirm the grams/glucose values
    connect(ui->checkButton, &QPushButton::released, this, [this]() {
        float carbs = bolusCalc->getCarbValue();
        float bloodGlucose = bolusCalc->getBloodGlucose();
        float unitsToDeliver = bolusCalc->getFinalBolus();

        QString message = QString("Carbs: %1 g\nBG: %2 mmol/L\nUnits To Deliver: %3 units\n\nConfirm?").arg(carbs).arg(bloodGlucose).arg(unitsToDeliver);

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirm Dose", message, QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            QMessageBox::StandardButton deliveryMethod = QMessageBox::question(this, "Delivery Method", "Would you like to deliver the bolus immediately?\nSelect 'No' to deliver it over an extended period.",
                QMessageBox::Yes | QMessageBox::No
            );

            if (deliveryMethod == QMessageBox::Yes) {
                //deliver immediately
                std::cout << "Bolus delivery: immediate\n";
            }
            else {
                //deliver over extended period
                std::cout << "Bolus delivery: extended\n";
                openExtendedBolus();
                ui->textEdit_4->setText(QString("%1").arg(bolusCalc->getFinalBolus()));
            }
        }
        else { std::cout << "Bolus cancelled by user\n"; }
    });



    connect(ui->checkButton_2, &QPushButton::released, this, [this]() {
        QString currentText = ui->textEdit_2->toPlainText(); //this lambda will set the carb value in the bolus calculator
        if (!currentText.isEmpty()) {
            float carbValue = currentText.toFloat();
            bolusCalc->setCarbValue(carbValue);
            std::cout << "Carbs:" << bolusCalc->getCarbValue() << std::endl;
            checkValue(*ui->textEdit_2, *ui->carbsButton, " grams");
        }

        //then set the text for the bolus units
        ui->textEdit->setPlainText(QString("%1").arg(bolusCalc->getFinalBolus()));
    });
    connect(ui->checkButton_2, &QPushButton::released, this, [this]() {
        openBolus(false);
    });

    connect(ui->checkButton_3, &QPushButton::released, this, [this]() {
        QString currentText = ui->textEdit_3->toPlainText(); //this lambda will set the blood glucose level in the bolus calculator
        if (!currentText.isEmpty()) {
            float bgLevel = currentText.toFloat();
            bolusCalc->setBloodGlucose(bgLevel);
            std::cout << "Blood Glucose:" << bolusCalc->getBloodGlucose() << std::endl;
            checkValue(*ui->textEdit_3, *ui->glucoseButton, " mmol/L");
        }

        //then set the text for the bolus units
        ui->textEdit->setPlainText(QString("%1").arg(bolusCalc->getFinalBolus()));
    });
    connect(ui->checkButton_3, &QPushButton::released, this, [this]() {
        openBolus(false);
    });

    //connect the view calculation ui elements
    connect(ui->viewCalcButton, &QPushButton::released, this, [this]() {
        displayCalculations();
    });
    connect(ui->viewCalcButton_2, &QPushButton::released, this, [this]() {
        displayCalculations();
    });
    //connect the extended bolus ui elements, and populate default values (percentages and duration)
    connect(ui->backButton_8, &QPushButton::released, this, [this]() {
        openBolus(false);
    });
    bolusCalc->populateDefaultValues();
    ui->deliverNowButton->setText(QString("%1\%").arg(bolusCalc->getNow()));
    ui->deliverLaterButton->setText(QString("%1\%").arg(bolusCalc->getLater()));
    ui->durationButton->setText(QString("%1h %2m").arg(bolusCalc->getDuration().hour()).arg(bolusCalc->getDuration().minute())); //format time in Xh Ym format
    connect(ui->deliverNowButton, &QPushButton::released, this, [this]() {
        changePercentages(*ui->deliverNowButton);
    });
    connect(ui->deliverLaterButton, &QPushButton::released, this, [this]() {
        changePercentages(*ui->deliverLaterButton);
    });
    connect(ui->durationButton, &QPushButton::released, this, [this]() {
        changeDuration();
    });



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

    connect(ui->timeList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(displaySelectedItem()));
    //displayList();
}

//change function name, and everytime you open the history page, it should update recentEvents
/*
 * TEST CODE FOR INFORMATION HISTORY
void MainWindow::displayList(){
    recentEvents = events.recentEvents();
    for (std::size_t i = 0; i < recentEvents.size(); i++){
        ui->timeList->addItem(QString::number(recentEvents[i]->getEventTime()));
    }
}
*/

void MainWindow::openPowerScreen(){
    ui->stackedWidget->setCurrentIndex(1);
    simulationTimer->stop();
}

void MainWindow::openHome(){
    ui->stackedWidget->setCurrentIndex(2);
    if(!simulationTimer->isActive()){
        simulationTimer->start(1000);
    }
}
void MainWindow::openCGM(){
    ui->stackedWidget->setCurrentIndex(3);
    if(!simulationTimer->isActive()){
        simulationTimer->start(1000);
    }
    cgmConnected = true;
}

void MainWindow::openBolus(bool pullFlag){
    if (pullFlag){
        //pull glucose from cgm before entering bolus
        pullBloodGlucose();
    }
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

void MainWindow::openHistoryOptions(){
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::openPersonalProfiles(){
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::openCreateProfile(){
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::openHistoryDisplay(QString filter){
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::openExtendedBolus(){
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::inputNumber(int num, QTextEdit& edit){
    QString currentText = edit.toPlainText();
    currentText += QString::number(num);
    edit.setPlainText(currentText);
}

void MainWindow::flipSign(QTextEdit& edit){
    QString currentText = edit.toPlainText();
    if (currentText.isEmpty()) return; //sanity check
    if (currentText.startsWith('-')) {
        currentText.remove(0, 1);  //remove the minus sign
    }
    else {
        currentText.prepend('-');  //add the minus sign
    }
    edit.setPlainText(currentText);
}

void MainWindow::addDecimal(QTextEdit& edit){
    QString currentText = edit.toPlainText();
    if (currentText.isEmpty()) return; //sanity checks
    else if (currentText.contains('.')) return;
    else {
        currentText.append('.');  //add the decimal
    }
    edit.setPlainText(currentText);
}

void MainWindow::backspace(QTextEdit& edit){
    QString currentText = edit.toPlainText();
    if (currentText.isEmpty()) return; //sanity check
    else{
        currentText.remove(currentText.length()-1, 1);
    }
    edit.setPlainText(currentText);
}

void MainWindow::checkValue(QTextEdit& edit, QPushButton& button, QString unit){
    QString currentText = edit.toPlainText();
    if (currentText.isEmpty()) return; //sanity check
    else{
        button.setText(currentText + unit);
    }
    edit.setPlainText("");
}

void MainWindow::pullBloodGlucose() {
    float glucose = cgm.getCurrentBG();  //pull current glucose
    QString text = QString("%1 mmol/L").arg(glucose);
    ui->glucoseButton->setText(text);
    bolusCalc->setBloodGlucose(glucose);
    std::cout << "Pulled BG: " << bolusCalc->getBloodGlucose() << std::endl;
}

void MainWindow::displayCalculations() {
    QString logMessage = bolusCalc->logCalculations();

    //display the message in a popup
    QMessageBox::information(this, "View Calculations", logMessage);
}

void MainWindow::changePercentages(QPushButton& clickedButton) {
    bool ok;
    int percentage = QInputDialog::getInt(this,
                                          "Set Delivery Percentage",
                                          "Enter percentage (0-100):",
                                          50,     //default value
                                          0,      //min
                                          100,    //max
                                          1,      //increment step
                                          &ok);

    //clicked OK and entered a value.
    if (ok) {
        qDebug() << "User entered:" << percentage << "%";

        //modify the percentages depending on which button was clicked
        if (&clickedButton == ui->deliverNowButton){
            //set the values in the bolus calculator
            bolusCalc->setNow(percentage);
            bolusCalc->setLater(100 - percentage);

            //change the numbers on the buttons
            ui->deliverNowButton->setText(QString("%1\%").arg(percentage));
            ui->deliverLaterButton->setText(QString("%1\%").arg(100 - percentage));
        }
        else{ //same but reversed
            bolusCalc->setNow(100 - percentage);
            bolusCalc->setLater(percentage);
            ui->deliverNowButton->setText(QString("%1\%").arg(100 - percentage));
            ui->deliverLaterButton->setText(QString("%1\%").arg(percentage));
        }
        qDebug() << "Now: " << bolusCalc->getNow() << "Later: " << bolusCalc->getLater();


    }
    else {
        //clicked cancel or closed the dialog
        qDebug() << "User cancelled input";
    }

}

void MainWindow::changeDuration() {
    bool ok;
    int duration = QInputDialog::getInt(this,
                                          "Set Delivery Percentage",
                                          "Enter duration in minutes (0-360):",
                                          120,    //default value
                                          0,      //min
                                          360,    //max
                                          5,      //increment step
                                          &ok);

    //clicked OK and entered a value.
    if (ok) {
        qDebug() << "User entered:" << duration << "%";
        QTime qDuration = QTime(0, 0).addSecs(duration * 60); //convert the minutes to a time
        bolusCalc->setDuration(qDuration);

        int hours = qDuration.hour();
        int minutes = qDuration.minute();

        QString durationStr;
        if (hours > 0)
            durationStr += QString::number(hours) + "h ";
        if (minutes > 0 || hours == 0) //only show minutes if hours is 0
            durationStr += QString::number(minutes) + "m";

        ui->durationButton->setText(durationStr);

        qDebug() << "Duration: " << bolusCalc->getDuration();

    }
    else {
        //clicked cancel or closed the dialog
        qDebug() << "User cancelled input";
    }
}






//start timer to charge battery
void MainWindow::chargePump(){
    powerOnTimer->start(10);
}

void MainWindow::stopCharging(){
    powerOnTimer->stop();
}

//slot to increase the battery by 1 every 100 miliseconds
void MainWindow::increaseBattery(){
    if (ui->progressIndicator->value() == 100){
        //stop the timer after you reach 100% battery
        powerOnTimer->stop();

        //allow the users to go to the home pages
        ui->homeButton->setEnabled(true);
        ui->CGMHomeButton->setEnabled(true);

        //on the home pages, set the battery gauge to the current battery percentage (should be 100)
        ui->battery->setValue(currentBattery);
        ui->battery_2->setValue(currentBattery);

        //on the home pages, set the innsulin on board (default 100)
        insulinOnBoard = 100;
        ui->insulinGauge->setValue(insulinOnBoard);
        ui->insulinGauge_2->setValue(insulinOnBoard);
    }
    else{
        currentBattery++;
        ui->progressIndicator->setValue(currentBattery);
    }
}

//triggered every second after simulation is loaded. calls handlers for background tasks
void MainWindow::simulateBackground(){
    if(simulationTime % 3 == 0){
        updateBattery();
    }
    if(cgmConnected){
        updateCGM();
    }
    updateTime();
    std::cout << cgm.readBG_mock() << std::endl;

    simulationTime++;
}

void MainWindow::updateBattery(){
    if(currentBattery == 0){
        ui->stackedWidget->setCurrentIndex(0);
        ui->homeButton->setEnabled(false);
        ui->CGMHomeButton->setEnabled(false);
        return;
    }
    currentBattery--;
    ui->battery->setValue(currentBattery);
    ui->battery_2->setValue(currentBattery);
    ui->progressIndicator->setValue(currentBattery);
}

void MainWindow::updateTime(){
    displayTime = displayTime.addSecs(300);
    ui->time->setText(displayTime.toString("HH:mm"));
    ui->time_2->setText(displayTime.toString("HH:mm"));
    ui->date->setText(displayTime.toString("dd MMM"));
    ui->date_2->setText(displayTime.toString("dd MMM"));
}

void MainWindow::updateCGM(){
    cgm.basalDelivery(insulinOnBoard);
    cgmLine->append(simulationTime, cgm.getCurrentBG());
    if(simulationTime > 20){
        xAxis->setRange(simulationTime - 20, simulationTime);
        cgmLine->removePoints(0, 1);
    }
}

// The next few functions are for the pin lock screen
void MainWindow::submitPasscode(){
    //check if the passcode entered is the same as the actual passcode
    if (ui->passcodeLabel->text().toInt() == passcode){
        //switch page if correct passcode
        ui->stackedWidget->setCurrentIndex(1);
        //clear the text from the labels
        ui->passcodeIncorrectLabel->setText("");
        ui->passcodeLabel->setText("");
    }
    else{
        //delete the user's previous entry, and tell them the passcode they entered was incorrect
        ui->passcodeLabel->setText("");
        ui->passcodeIncorrectLabel->setText("Incorrect Passcode");
        //clear the passcode after 2 seconds
        QTimer::singleShot(2000, [this](){
            ui->passcodeIncorrectLabel->setText("");
        });
    }
}

void MainWindow::lsDeleteButton(){
    //chop functions removes the last letter of a QString, does nothing if the QString is empty
    QString temp = ui->passcodeLabel->text();
    temp.chop(1);
    ui->passcodeLabel->setText(temp);
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
//end of pin lock screen functions

void MainWindow::onCreateProfile() {
    Profile* newProfile = profileFormWidget->getProfile();
    profilesPageWidget->addProfile(newProfile);
    openPersonalProfiles();
}
//pump information and history
void MainWindow::displaySelectedItem(){
    int currentIndex = ui->timeList->currentRow();

    /*
     * These don't currently work
    //eInfo should be polymorphic
    std::string eName = recentEvents[currentIndex]->getEventName();
    std::string eInfo = recentEvents[currentIndex]->getInformation();

    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser->append(QString::fromStdString(eName));
    ui->textBrowser_2->append(QString::fromStdString(eInfo));
    */
}



//getters
Profile* MainWindow::getCurProfile() const { return profilesPageWidget->getActiveProfile(); }

//setters
void MainWindow::setPasscode(int i){
    passcode = i;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bolusCalc;
}

