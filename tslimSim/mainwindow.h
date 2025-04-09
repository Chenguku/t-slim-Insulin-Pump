#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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


    //getters
    Profile* getCurProfile() const;

private:
    Ui::MainWindow *ui;
    Profile curProfile;

private slots:
    void openHome();
    void openBolus();
    void openOptions();
    void openCarbs();
    void openMyPump();
    void openPersonalProfiles();
    void openGlucose();
};
#endif // MAINWINDOW_H
