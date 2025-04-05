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
    */
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
     * 0: Home Page
     * 1: Something
     * 2: Bolus Page
     * 3: Carbs Calculator
    */
    connect(ui->homeBolus, SIGNAL(released()), this, SLOT(openBolus()));
    connect(ui->backButton, SIGNAL(released()), this, SLOT(openHome()));
    connect(ui->carbsButton, SIGNAL(released()), this, SLOT(openCarbs()));
    connect(ui->backButton_2, SIGNAL(released()), this, SLOT(openBolus()));
}

void MainWindow::openHome(){
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::openBolus(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::openOptions(){

}

void MainWindow::openCarbs(){
    ui->stackedWidget->setCurrentIndex(3);
}


MainWindow::~MainWindow()
{
    delete ui;
}

