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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *home;
    QProgressBar *battery;
    QLabel *date;
    QPushButton *homeBolus;
    QPushButton *pushButton;
    QFrame *insulinData;
    QLabel *unitsLabel;
    QLabel *timeRemaining;
    QFrame *insulinDataLine;
    QLabel *remainingTime;
    QLabel *units;
    QLabel *insulinOnBoard;
    QProgressBar *progressBar;
    QLabel *label;
    QWidget *ManualBolus;
    QPushButton *backButton;
    QPushButton *carbsButton;
    QLabel *carbsLabel;
    QPushButton *checkButton;
    QPushButton *glucoseButton;
    QLabel *glucoseLabel;
    QTextEdit *textEdit;
    QLabel *unitsLabel_2;
    QPushButton *viewCalcButton;
    QWidget *Carbs;
    QPushButton *XButton;
    QPushButton *backButton_2;
    QPushButton *checkButton_2;
    QPushButton *numberButton_0;
    QPushButton *numberButton_1;
    QPushButton *numberButton_2;
    QPushButton *numberButton_3;
    QPushButton *numberButton_4;
    QPushButton *numberButton_5;
    QPushButton *numberButton_6;
    QPushButton *numberButton_7;
    QPushButton *numberButton_8;
    QPushButton *numberButton_9;
    QPushButton *plusButton;
    QTextEdit *textEdit_2;
    QLabel *unitsLabel_3;
    QWidget *page_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
        home = new QWidget();
        home->setObjectName(QString::fromUtf8("home"));
        battery = new QProgressBar(home);
        battery->setObjectName(QString::fromUtf8("battery"));
        battery->setGeometry(QRect(10, 10, 121, 41));
        battery->setValue(24);
        date = new QLabel(home);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(270, 40, 81, 17));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        date->setFont(font);
        date->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        homeBolus = new QPushButton(home);
        homeBolus->setObjectName(QString::fromUtf8("homeBolus"));
        homeBolus->setGeometry(QRect(10, 80, 591, 131));
        pushButton = new QPushButton(home);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 240, 591, 131));
        insulinData = new QFrame(home);
        insulinData->setObjectName(QString::fromUtf8("insulinData"));
        insulinData->setGeometry(QRect(0, 450, 601, 71));
        insulinData->setAutoFillBackground(false);
        insulinData->setStyleSheet(QString::fromUtf8("background-color: rgb(119, 118, 123)"));
        insulinData->setFrameShape(QFrame::StyledPanel);
        insulinData->setFrameShadow(QFrame::Raised);
        unitsLabel = new QLabel(insulinData);
        unitsLabel->setObjectName(QString::fromUtf8("unitsLabel"));
        unitsLabel->setGeometry(QRect(10, 20, 101, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(14);
        unitsLabel->setFont(font1);
        unitsLabel->setStyleSheet(QString::fromUtf8("color: rgb(246, 245, 244)"));
        timeRemaining = new QLabel(insulinData);
        timeRemaining->setObjectName(QString::fromUtf8("timeRemaining"));
        timeRemaining->setGeometry(QRect(230, 20, 171, 31));
        timeRemaining->setFont(font1);
        timeRemaining->setStyleSheet(QString::fromUtf8("color: rgb(246, 245, 244)"));
        insulinDataLine = new QFrame(insulinData);
        insulinDataLine->setObjectName(QString::fromUtf8("insulinDataLine"));
        insulinDataLine->setGeometry(QRect(206, 0, 20, 71));
        insulinDataLine->setFrameShape(QFrame::VLine);
        insulinDataLine->setFrameShadow(QFrame::Sunken);
        remainingTime = new QLabel(insulinData);
        remainingTime->setObjectName(QString::fromUtf8("remainingTime"));
        remainingTime->setGeometry(QRect(490, 20, 91, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        remainingTime->setFont(font2);
        remainingTime->setStyleSheet(QString::fromUtf8("color: rgb(246, 245, 244)"));
        units = new QLabel(insulinData);
        units->setObjectName(QString::fromUtf8("units"));
        units->setGeometry(QRect(140, 20, 51, 31));
        units->setFont(font2);
        units->setStyleSheet(QString::fromUtf8("color: rgb(246, 245, 244)"));
        insulinOnBoard = new QLabel(home);
        insulinOnBoard->setObjectName(QString::fromUtf8("insulinOnBoard"));
        insulinOnBoard->setGeometry(QRect(30, 410, 311, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        insulinOnBoard->setFont(font3);
        progressBar = new QProgressBar(home);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(480, 10, 121, 41));
        progressBar->setValue(24);
        label = new QLabel(home);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 0, 111, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(24);
        label->setFont(font4);
        label->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(home);
        ManualBolus = new QWidget();
        ManualBolus->setObjectName(QString::fromUtf8("ManualBolus"));
        backButton = new QPushButton(ManualBolus);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(0, 0, 131, 91));
        carbsButton = new QPushButton(ManualBolus);
        carbsButton->setObjectName(QString::fromUtf8("carbsButton"));
        carbsButton->setGeometry(QRect(10, 180, 381, 241));
        carbsLabel = new QLabel(ManualBolus);
        carbsLabel->setObjectName(QString::fromUtf8("carbsLabel"));
        carbsLabel->setGeometry(QRect(20, 150, 141, 31));
        QFont font5;
        font5.setPointSize(18);
        font5.setBold(true);
        font5.setWeight(75);
        carbsLabel->setFont(font5);
        checkButton = new QPushButton(ManualBolus);
        checkButton->setObjectName(QString::fromUtf8("checkButton"));
        checkButton->setGeometry(QRect(660, 0, 131, 91));
        glucoseButton = new QPushButton(ManualBolus);
        glucoseButton->setObjectName(QString::fromUtf8("glucoseButton"));
        glucoseButton->setGeometry(QRect(400, 180, 381, 241));
        glucoseLabel = new QLabel(ManualBolus);
        glucoseLabel->setObjectName(QString::fromUtf8("glucoseLabel"));
        glucoseLabel->setGeometry(QRect(410, 150, 141, 31));
        glucoseLabel->setFont(font5);
        textEdit = new QTextEdit(ManualBolus);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(130, 0, 531, 91));
        unitsLabel_2 = new QLabel(ManualBolus);
        unitsLabel_2->setObjectName(QString::fromUtf8("unitsLabel_2"));
        unitsLabel_2->setGeometry(QRect(370, 100, 61, 21));
        QFont font6;
        font6.setFamily(QString::fromUtf8("DejaVu Sans"));
        font6.setPointSize(15);
        font6.setBold(true);
        font6.setWeight(75);
        unitsLabel_2->setFont(font6);
        viewCalcButton = new QPushButton(ManualBolus);
        viewCalcButton->setObjectName(QString::fromUtf8("viewCalcButton"));
        viewCalcButton->setGeometry(QRect(10, 430, 771, 71));
        stackedWidget->addWidget(ManualBolus);
        Carbs = new QWidget();
        Carbs->setObjectName(QString::fromUtf8("Carbs"));
        XButton = new QPushButton(Carbs);
        XButton->setObjectName(QString::fromUtf8("XButton"));
        XButton->setGeometry(QRect(510, 410, 191, 81));
        backButton_2 = new QPushButton(Carbs);
        backButton_2->setObjectName(QString::fromUtf8("backButton_2"));
        backButton_2->setGeometry(QRect(0, 0, 131, 91));
        checkButton_2 = new QPushButton(Carbs);
        checkButton_2->setObjectName(QString::fromUtf8("checkButton_2"));
        checkButton_2->setGeometry(QRect(660, 0, 131, 91));
        numberButton_0 = new QPushButton(Carbs);
        numberButton_0->setObjectName(QString::fromUtf8("numberButton_0"));
        numberButton_0->setGeometry(QRect(300, 410, 191, 81));
        numberButton_1 = new QPushButton(Carbs);
        numberButton_1->setObjectName(QString::fromUtf8("numberButton_1"));
        numberButton_1->setGeometry(QRect(90, 140, 191, 81));
        numberButton_2 = new QPushButton(Carbs);
        numberButton_2->setObjectName(QString::fromUtf8("numberButton_2"));
        numberButton_2->setGeometry(QRect(300, 140, 191, 81));
        numberButton_3 = new QPushButton(Carbs);
        numberButton_3->setObjectName(QString::fromUtf8("numberButton_3"));
        numberButton_3->setGeometry(QRect(510, 140, 191, 81));
        numberButton_4 = new QPushButton(Carbs);
        numberButton_4->setObjectName(QString::fromUtf8("numberButton_4"));
        numberButton_4->setGeometry(QRect(90, 230, 191, 81));
        numberButton_5 = new QPushButton(Carbs);
        numberButton_5->setObjectName(QString::fromUtf8("numberButton_5"));
        numberButton_5->setGeometry(QRect(300, 230, 191, 81));
        numberButton_6 = new QPushButton(Carbs);
        numberButton_6->setObjectName(QString::fromUtf8("numberButton_6"));
        numberButton_6->setGeometry(QRect(510, 230, 191, 81));
        numberButton_7 = new QPushButton(Carbs);
        numberButton_7->setObjectName(QString::fromUtf8("numberButton_7"));
        numberButton_7->setGeometry(QRect(90, 320, 191, 81));
        numberButton_8 = new QPushButton(Carbs);
        numberButton_8->setObjectName(QString::fromUtf8("numberButton_8"));
        numberButton_8->setGeometry(QRect(300, 320, 191, 81));
        numberButton_9 = new QPushButton(Carbs);
        numberButton_9->setObjectName(QString::fromUtf8("numberButton_9"));
        numberButton_9->setGeometry(QRect(510, 320, 191, 81));
        plusButton = new QPushButton(Carbs);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        plusButton->setGeometry(QRect(90, 410, 191, 81));
        textEdit_2 = new QTextEdit(Carbs);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(130, 0, 531, 91));
        unitsLabel_3 = new QLabel(Carbs);
        unitsLabel_3->setObjectName(QString::fromUtf8("unitsLabel_3"));
        unitsLabel_3->setGeometry(QRect(320, 100, 61, 21));
        QFont font7;
        font7.setPointSize(15);
        font7.setBold(true);
        font7.setWeight(75);
        unitsLabel_3->setFont(font7);
        stackedWidget->addWidget(Carbs);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget->addWidget(page_5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        date->setText(QCoreApplication::translate("MainWindow", "14 Nov", nullptr));
        homeBolus->setText(QCoreApplication::translate("MainWindow", "Bolus", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        unitsLabel->setText(QCoreApplication::translate("MainWindow", "Units:", nullptr));
        timeRemaining->setText(QCoreApplication::translate("MainWindow", "Time Remaining:", nullptr));
        remainingTime->setText(QCoreApplication::translate("MainWindow", "3:45 hrs", nullptr));
        units->setText(QCoreApplication::translate("MainWindow", "2.5u", nullptr));
        insulinOnBoard->setText(QCoreApplication::translate("MainWindow", "Insulin on Board (IOB)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "10:20", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        carbsButton->setText(QCoreApplication::translate("MainWindow", "Carbs", nullptr));
        carbsLabel->setText(QCoreApplication::translate("MainWindow", "Carbs", nullptr));
        checkButton->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
        glucoseButton->setText(QCoreApplication::translate("MainWindow", "Glucose", nullptr));
        glucoseLabel->setText(QCoreApplication::translate("MainWindow", "Glucose", nullptr));
        unitsLabel_2->setText(QCoreApplication::translate("MainWindow", "units", nullptr));
        viewCalcButton->setText(QCoreApplication::translate("MainWindow", "View Calculation", nullptr));
        XButton->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        backButton_2->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        checkButton_2->setText(QCoreApplication::translate("MainWindow", "Check", nullptr));
        numberButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        numberButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        numberButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        numberButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        numberButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        numberButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        numberButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        numberButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        numberButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        numberButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        plusButton->setText(QCoreApplication::translate("MainWindow", "+/=", nullptr));
        unitsLabel_3->setText(QCoreApplication::translate("MainWindow", "units", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
