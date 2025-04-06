#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

#include <QMainWindow>

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
    Ui::MainWindow *ui;
    QLineSeries *cgmLine;
    QChart *cgmChart;
    QChartView *cgmView;
    QTimer *powerOnTimer;
    int currentBattery;

private slots:
    void openPowerScreen();
    void openHome();
    void openBolus();
    void openOptions();
    void openCarbs();
    void openCGM();
    void increaseBattery();
    void chargePump();
};
#endif // MAINWINDOW_H
