#ifndef PROFILEFORMWIDGET_H
#define PROFILEFORMWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QTimeEdit>
#include <QLineEdit>
#include <QCheckBox>
#include "profile.h"


class ProfileFormWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProfileFormWidget(QWidget *parent = nullptr);
    Profile* getProfile() const;

    void loadProfile(Profile* p);
    void updateProfile(Profile* p) const;

private:
    QLineEdit    *titleLineEdit;
    QTableWidget *timeTable;
    QTimeEdit    *insulinDurationEdit;
    QLineEdit    *maxBolusEdit;
    QCheckBox    *carbCheckbox;
    QPushButton  *addTimeButton;
    QPushButton  *removeTimeButton;

private slots:
    void onAddTimeSetting();
    void onRemoveTimeSetting();

signals:

};

#endif // PROFILEFORMWIDGET_H
