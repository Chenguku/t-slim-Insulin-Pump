#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

#include <QMainWindow>

#include <vector>

#include "profile.h"
#include "eventhistory.h"

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
    Ui::MainWindow *ui;
    QLineSeries *cgmLine;
    QChart *cgmChart;
    QChartView *cgmView;
    QTimer *powerOnTimer;
    int currentBattery;
    Profile* curProfile;
    int passcode;
    EventHistory events;

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
    void openPersonalProfiles();
    void openGlucose();
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
