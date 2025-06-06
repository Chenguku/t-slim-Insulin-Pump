#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QTimer>
#include <QTextEdit>
#include <QPushButton>
#include <QTime>
#include <QStack>
#include <iostream>
#include <vector>
#include <string>

QT_CHARTS_USE_NAMESPACE

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>
#include <QInputDialog>

#include "boluscalculator.h"
#include "profile.h"
#include "cgm.h"
#include "profile.h"
#include "eventhistory.h"
#include "profileformwidget.h"
#include "profilespagewidget.h"
#include "alertevent.h"
#include "cgmevent.h"
#include "insulindeliveryevent.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define LOW_BATTERY     25
#define LOW_INSULIN     20
#define LOW_BG          3.9     //follows the graph, not the user guide
#define HIGH_BG         10.0    //follows the graph, not the user guide

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //getters
    Profile* getCurProfile() const;
    InsulinDeliveryProfile* getActiveTimeSetting() const;

private:
    Ui::MainWindow      *ui;
    QLineSeries         *cgmLine;
    QChart              *cgmChart;
    QChartView          *cgmView;
    QValueAxis          *xAxis;
    QValueAxis          *yAxis;
    int                 graphRange;
    CGM                 cgm;
    QTimer              *powerOnTimer;
    QTimer              *simulationTimer;
    int                 currentBattery;
    QDateTime           displayTime;
    float               insulinFill;
    float               insulinOnBoard;
    int                 simulationTime;
    BolusCalculator     *bolusCalc;
    int                 passcode;
    EventHistory        events;
    Profile             *curProfile;
    Profile             *editingProfile;
    ProfilesPageWidget  *profilesPageWidget;
    ProfileFormWidget   *profileFormWidget;
    std::vector<Event*> recentEvents;
    QString             historyEvent; //this is for history viewing, to simplify the code
    bool                BGLow;
    bool                BGHigh;
    QStack<int>         pageHistory;
    bool                lowInsulin;

    //users should not be able to use these helper functions
    void createLowBatteryEvent();
    void checkBGLevels();
    void createLowBloodGlucoseEvent();
    void createHighBloodGlucoseEvent();
    void logCGMReading();
    void createLowInsulinEvent();
    void logInsulinDelivery(float);

    //setters
    void setPasscode(int);

private slots:
    void openPowerScreen();
    void openHome();
    void openBolus(bool pullFlag);
    void openOptions();
    void openCarbs();
    void openCGM();
    void increaseBattery();
    void chargePump();
    void stopCharging();
    void openMyPump();
    void openGlucose();
    void previousPage();
    void switchHomePage();
    void refillInsulin();

    //for simulation time tasks
    void simulateBackground();
    void updateBattery();
    void updateTime();
    void updateCGM();
    void openExtendedBolus();
    void openHistoryOptions();
    void openHistoryDisplay(QString);

    // profile pages
    void openPersonalProfiles();
    void openCreateProfile();
    void onCreateProfile();
    void onActiveProfileSelect(Profile *p);
    void onDeleteProfile(Profile *p);
    void onEditProfile(Profile *p);

    //for carbs/glucose input screens
    void inputNumber(int num, QTextEdit&);
    void flipSign(QTextEdit&);
    void addDecimal(QTextEdit&);
    void backspace(QTextEdit&);
    void checkValue(QTextEdit&, QPushButton&, QString);
    void pullBloodGlucose();
    void displayCalculations();
    void changePercentages(QPushButton&);
    void changeDuration();

    //slots for the pin lockscreen
    void submitPasscode();
    void lsDeleteButton();
    void lsButtonOne();
    void lsButtonTwo();
    void lsButtonThree();
    void lsButtonFour();
    void lsButtonFive();
    void lsButtonSix();
    void lsButtonSeven();
    void lsButtonEight();
    void lsButtonNine();
    void lsButtonZero();

    //slots for the history page
    void displaySelectedItem();
};
#endif // MAINWINDOW_H
