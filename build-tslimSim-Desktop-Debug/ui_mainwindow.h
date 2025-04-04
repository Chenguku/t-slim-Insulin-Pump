/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *home;
    QPushButton *homeBolus;
    QPushButton *homeOptions;
    QLabel *label;
    QProgressBar *battery;
    QFrame *insulinData;
    QFrame *line;
    QLabel *label_2;
    QLabel *units;
    QLabel *label_3;
    QLabel *remainingTime;
    QLabel *time;
    QLabel *date;
    QProgressBar *progressBar;
    QWidget *manualBolus;
    QPushButton *backButton;
    QTextEdit *textEdit;
    QPushButton *checkButton;
    QLabel *unitsLabel;
    QLabel *carbsLabel;
    QLabel *glucoseLabel;
    QPushButton *carbsButton;
    QPushButton *glucoseButton;
    QPushButton *viewCalcButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 791, 551));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        home = new QWidget();
        home->setObjectName(QString::fromUtf8("home"));
        homeBolus = new QPushButton(home);
        homeBolus->setObjectName(QString::fromUtf8("homeBolus"));
        homeBolus->setEnabled(true);
        homeBolus->setGeometry(QRect(10, 80, 591, 131));
        homeOptions = new QPushButton(home);
        homeOptions->setObjectName(QString::fromUtf8("homeOptions"));
        homeOptions->setGeometry(QRect(10, 240, 591, 131));
        label = new QLabel(home);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 410, 311, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        battery = new QProgressBar(home);
        battery->setObjectName(QString::fromUtf8("battery"));
        battery->setGeometry(QRect(10, 10, 121, 41));
        battery->setValue(24);
        insulinData = new QFrame(home);
        insulinData->setObjectName(QString::fromUtf8("insulinData"));
        insulinData->setGeometry(QRect(0, 450, 601, 71));
        insulinData->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123)"));
        insulinData->setFrameShape(QFrame::StyledPanel);
        insulinData->setFrameShadow(QFrame::Raised);
        line = new QFrame(insulinData);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(206, 0, 20, 71));
        line->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(insulinData);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 101, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(246, 245, 244)"));
        units = new QLabel(insulinData);
        units->setObjectName(QString::fromUtf8("units"));
        units->setGeometry(QRect(140, 20, 51, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        units->setFont(font3);
        units->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        units->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(insulinData);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 20, 171, 31));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(246, 245, 244)"));
        remainingTime = new QLabel(insulinData);
        remainingTime->setObjectName(QString::fromUtf8("remainingTime"));
        remainingTime->setGeometry(QRect(490, 20, 91, 31));
        remainingTime->setFont(font3);
        remainingTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        remainingTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        time = new QLabel(home);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(240, 0, 111, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(24);
        font4.setBold(false);
        font4.setWeight(50);
        time->setFont(font4);
        date = new QLabel(home);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(270, 40, 81, 17));
        QFont font5;
        font5.setFamily(QString::fromUtf8("DejaVu Sans"));
        font5.setPointSize(12);
        font5.setBold(false);
        font5.setWeight(50);
        date->setFont(font5);
        progressBar = new QProgressBar(home);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(480, 10, 121, 41));
        progressBar->setValue(24);
        tabWidget->addTab(home, QString());
        manualBolus = new QWidget();
        manualBolus->setObjectName(QString::fromUtf8("manualBolus"));
        manualBolus->setEnabled(true);
        backButton = new QPushButton(manualBolus);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(0, 0, 131, 91));
        textEdit = new QTextEdit(manualBolus);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(130, 0, 531, 91));
        checkButton = new QPushButton(manualBolus);
        checkButton->setObjectName(QString::fromUtf8("checkButton"));
        checkButton->setGeometry(QRect(660, 0, 131, 91));
        unitsLabel = new QLabel(manualBolus);
        unitsLabel->setObjectName(QString::fromUtf8("unitsLabel"));
        unitsLabel->setGeometry(QRect(360, 100, 61, 21));
        QFont font6;
        font6.setPointSize(15);
        font6.setBold(true);
        font6.setWeight(75);
        unitsLabel->setFont(font6);
        unitsLabel->setAlignment(Qt::AlignCenter);
        carbsLabel = new QLabel(manualBolus);
        carbsLabel->setObjectName(QString::fromUtf8("carbsLabel"));
        carbsLabel->setGeometry(QRect(20, 150, 141, 31));
        QFont font7;
        font7.setPointSize(18);
        font7.setBold(true);
        font7.setWeight(75);
        carbsLabel->setFont(font7);
        carbsLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        glucoseLabel = new QLabel(manualBolus);
        glucoseLabel->setObjectName(QString::fromUtf8("glucoseLabel"));
        glucoseLabel->setGeometry(QRect(410, 150, 141, 31));
        glucoseLabel->setFont(font7);
        glucoseLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        carbsButton = new QPushButton(manualBolus);
        carbsButton->setObjectName(QString::fromUtf8("carbsButton"));
        carbsButton->setGeometry(QRect(10, 180, 381, 241));
        glucoseButton = new QPushButton(manualBolus);
        glucoseButton->setObjectName(QString::fromUtf8("glucoseButton"));
        glucoseButton->setGeometry(QRect(400, 180, 381, 241));
        viewCalcButton = new QPushButton(manualBolus);
        viewCalcButton->setObjectName(QString::fromUtf8("viewCalcButton"));
        viewCalcButton->setGeometry(QRect(10, 430, 771, 71));
        tabWidget->addTab(manualBolus, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        homeBolus->setText(QCoreApplication::translate("MainWindow", "Bolus", nullptr));
        homeOptions->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Insulin on Board (IOB)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Units: ", nullptr));
        units->setText(QCoreApplication::translate("MainWindow", "2.5 u", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Time Remaining:", nullptr));
        remainingTime->setText(QCoreApplication::translate("MainWindow", "3:45 hrs", nullptr));
        time->setText(QCoreApplication::translate("MainWindow", "10 : 20", nullptr));
        date->setText(QCoreApplication::translate("MainWindow", "14 Nov", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(home), QCoreApplication::translate("MainWindow", "Home", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        checkButton->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
        unitsLabel->setText(QCoreApplication::translate("MainWindow", "units", nullptr));
        carbsLabel->setText(QCoreApplication::translate("MainWindow", "Carbs", nullptr));
        glucoseLabel->setText(QCoreApplication::translate("MainWindow", "Glucose", nullptr));
        carbsButton->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        glucoseButton->setText(QCoreApplication::translate("MainWindow", "Add BG", nullptr));
        viewCalcButton->setText(QCoreApplication::translate("MainWindow", "View Calculation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(manualBolus), QCoreApplication::translate("MainWindow", "Manual Bolus", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
