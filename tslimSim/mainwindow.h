#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QVBoxLayout>

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

private slots:
    void openHome();
    void openBolus();
    void openOptions();
    void openCarbs();
};
#endif // MAINWINDOW_H
