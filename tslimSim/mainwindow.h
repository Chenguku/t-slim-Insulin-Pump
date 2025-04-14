#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QTimer>
#include <QTextEdit>
#include <QPushButton>
#include <iostream>

QT_CHARTS_USE_NAMESPACE

#include <QMainWindow>

#include "boluscalculator.h"
#include "profile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow      *ui;
    QLineSeries         *cgmLine;
    QChart              *cgmChart;
    QChartView          *cgmView;
    QTimer              *powerOnTimer;
    int                 currentBattery;
    BolusCalculator*    bolusCalc;


private slots:
    void openPowerScreen();
    void openHome();
    void openBolus();
    void openOptions();
    void openCarbs();
    void openCGM();
    void increaseBattery();
    void chargePump();
    void openMyPump();
    void openPersonalProfiles();
    void openGlucose();

    //for carbs/glucose input screens
    void inputNumber(int num, QTextEdit&);
    void flipSign(QTextEdit&);
    void addDecimal(QTextEdit&);
    void backspace(QTextEdit&);
    void checkValue(QTextEdit&, QPushButton&, QString);


};
#endif // MAINWINDOW_H
