#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QTimer>
#include <QTextEdit>
#include <QPushButton>
#include <QTime>
#include <iostream>
#include <vector>

QT_CHARTS_USE_NAMESPACE

#include <QMainWindow>
#include <QTableWidget>

#include "boluscalculator.h"
#include "profile.h"
#include "cgm.h"
#include "profile.h"
#include "eventhistory.h"
#include "profileformwidget.h"
#include "profilespagewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //void displayList(); test function
    //getters
    Profile* getCurProfile() const;

    //setters
    void setPasscode(int);

private:
    Ui::MainWindow      *ui;
    QLineSeries         *cgmLine;
    QChart              *cgmChart;
    QChartView          *cgmView;
    CGM                 cgm;
    QTimer              *powerOnTimer;
    QTimer              *simulationTimer;
    int                 currentBattery;
    QDateTime           displayTime;
    int                 insulinOnBoard;
    int                 simulationTime;
    BolusCalculator     *bolusCalc;
    int                 passcode;
    EventHistory        events;
    Profile             *curProfile;
    ProfilesPageWidget  *profilesPageWidget;
    ProfileFormWidget   *profileFormWidget;

private slots:
    void openPowerScreen();
    void openHome();
    void openBolus();
    void openOptions();
    void openCarbs();
    void openCGM();
    void increaseBattery();
    void chargePump();
    void stopCharging();
    void openMyPump();
    void openGlucose();
    void simulateBackground();
    void updateBattery();
    void updateTime();

    // profile pages
    void openPersonalProfiles();
    void openCreateProfile();
    void onCreateProfile();

    //for carbs/glucose input screens
    void inputNumber(int num, QTextEdit&);
    void flipSign(QTextEdit&);
    void addDecimal(QTextEdit&);
    void backspace(QTextEdit&);
    void checkValue(QTextEdit&, QPushButton&, QString);
    void pullBloodGlucose();

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
};
#endif // MAINWINDOW_H
