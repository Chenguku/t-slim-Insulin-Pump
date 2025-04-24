// profileformwidget.cpp
#include "profileformwidget.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QPushButton>
#include <QHeaderView>
#include <QGroupBox>
#include <QCheckBox>
#include <QTimeEdit>
#include <QDebug>
#include <memory>

ProfileFormWidget::ProfileFormWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Profile Title
    QFormLayout *titleLayout = new QFormLayout;
    QLabel *titleLabel = new QLabel("Profile Title:");
    titleLineEdit = new QLineEdit;
    titleLineEdit->setPlaceholderText("Enter profile title");
    titleLayout->addRow(titleLabel, titleLineEdit);
    mainLayout->addLayout(titleLayout);

    // Time Settings
    QGroupBox *timeSettingsGroup = new QGroupBox("Time Settings");
    QVBoxLayout *timeLayout = new QVBoxLayout;

    timeTable = new QTableWidget;
    timeTable->setColumnCount(5);
    QStringList headers;
    headers << "Time" << "Basal" << "Correction Factor" << "Carb Ratio" << "Target BG";
    timeTable->setHorizontalHeaderLabels(headers);
    timeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // set mandatory row
    timeTable->setRowCount(1);

    // QTime for Time in 24-hour, HH:mm format
    QTimeEdit *timeEdit = new QTimeEdit;
    timeEdit->setDisplayFormat("HH:mm");
    timeEdit->setTime(QTime(0, 0));
    timeTable->setCellWidget(0, 0, timeEdit);

    // Fill other columns for the mandatory row
    for (int col = 1; col < timeTable->columnCount(); ++col) {
        timeTable->setItem(0, col, new QTableWidgetItem(""));
    }
    timeLayout->addWidget(timeTable);

    // Add "Add" and "Remove" buttons below the table
    QHBoxLayout *timeButtonsLayout = new QHBoxLayout;
    addTimeButton = new QPushButton("Add Time Setting");
    removeTimeButton = new QPushButton("Remove Time Setting");
    timeButtonsLayout->addWidget(addTimeButton);
    timeButtonsLayout->addWidget(removeTimeButton);
    timeLayout->addLayout(timeButtonsLayout);

    connect(addTimeButton, &QPushButton::clicked, this, &ProfileFormWidget::onAddTimeSetting);
    connect(removeTimeButton, &QPushButton::clicked, this, &ProfileFormWidget::onRemoveTimeSetting);

    timeSettingsGroup->setLayout(timeLayout);
    mainLayout->addWidget(timeSettingsGroup);

    // Bolus Settings
    QGroupBox *bolusSettingsGroup = new QGroupBox("Bolus Settings");
    QFormLayout *bolusLayout = new QFormLayout;

    insulinDurationEdit = new QTimeEdit;
    insulinDurationEdit->setDisplayFormat("HH:mm");
    maxBolusEdit = new QLineEdit;
    maxBolusEdit->setPlaceholderText("Enter max bolus");
    carbCheckbox = new QCheckBox("Include Carbohydrates");

    bolusLayout->addRow("Insulin Duration:", insulinDurationEdit);
    bolusLayout->addRow("Max Bolus:", maxBolusEdit);
    bolusLayout->addRow("Carbohydrates:", carbCheckbox);
    bolusSettingsGroup->setLayout(bolusLayout);
    mainLayout->addWidget(bolusSettingsGroup);

    // Set the main layout for this widget
    setLayout(mainLayout);
}

void ProfileFormWidget::onAddTimeSetting() {

    int rowCount = timeTable->rowCount();
    timeTable->insertRow(rowCount);

    QTimeEdit *newTimeEdit = new QTimeEdit;
    newTimeEdit->setDisplayFormat("HH:mm");
    newTimeEdit->setTime(QTime(0, 0));
    timeTable->setCellWidget(rowCount, 0, newTimeEdit);

    for (int col = 1; col < timeTable->columnCount(); ++col) {
        QTableWidgetItem *prevItem = timeTable->item(rowCount - 1, col);
        QString value = "";
        if (prevItem != nullptr) {
            value = prevItem->text();
        }
        timeTable->setItem(rowCount, col, new QTableWidgetItem(value));
    }
}

void ProfileFormWidget::onRemoveTimeSetting() {
    int currentRow = timeTable->currentRow();

    // If no row is selected or mandatory row is selected don't delete
    if (currentRow <= 0)
        return;

    // Remove the selected row.
    timeTable->removeRow(currentRow);
}

Profile* ProfileFormWidget::getProfile() const
{
    Profile* newProfile = new Profile(titleLineEdit->text().toStdString());

    // bolus settings
    newProfile->setInsulinDuration(insulinDurationEdit->time());
    newProfile->setMaxBolus(maxBolusEdit->text().toFloat());
    newProfile->setIncludeCarbs(carbCheckbox->isChecked());

    // time settings
    int rowCount = timeTable->rowCount();
    for (int i = 0; i < rowCount; ++i)
    {
        QTimeEdit* timeEdit = qobject_cast<QTimeEdit*>(timeTable->cellWidget(i, 0));
        QTime timeValue = timeEdit ? timeEdit->time() : QTime(0,0);

        float basal = timeTable->item(i, 1) ? timeTable->item(i, 1)->text().toFloat() : 0.0f;
        float correctionFactor = timeTable->item(i, 2) ? timeTable->item(i, 2)->text().toFloat() : 0.0f;
        float carbRatio = timeTable->item(i, 3) ? timeTable->item(i, 3)->text().toFloat() : 0.0f;
        float targetGlucose = timeTable->item(i, 4) ? timeTable->item(i, 4)->text().toFloat() : 0.0f;

        std::unique_ptr<InsulinDeliveryProfile> idpPtr(
            new InsulinDeliveryProfile(basal, carbRatio, correctionFactor, targetGlucose, timeValue)
        );
        newProfile->addTimeSetting(std::move(idpPtr));
    }
    return newProfile;
}

void ProfileFormWidget::loadProfile(Profile *p)
{
    if (!p) return;

    // basic fields
    titleLineEdit->setText(QString::fromStdString(p->getTitle()));
    insulinDurationEdit->setTime(p->getInsulinDuration());
    maxBolusEdit->setText(QString::number(p->getMaxBolus()));
    carbCheckbox->setChecked(p->getIncludeCarbs());

    // time settings table
    const auto &settings = p->getTimeSettings();
    int rows = static_cast<int>(settings.size());
    timeTable->setRowCount(rows);

    for (int i = 0; i < rows; ++i) {
        auto &up = settings[i];

        // time widget
        QTimeEdit *te = new QTimeEdit;
        te->setDisplayFormat("HH:mm");
        te->setTime(up->getTime());
        timeTable->setCellWidget(i, 0, te);

        // bolus
        timeTable->setItem(i, 1,
            new QTableWidgetItem(QString::number(up->getBasalRate()))
        );
        timeTable->setItem(i, 2,
            new QTableWidgetItem(QString::number(up->getCorrectionFactor()))
        );
        timeTable->setItem(i, 3,
            new QTableWidgetItem(QString::number(up->getCarbRatio()))
        );
        timeTable->setItem(i, 4,
            new QTableWidgetItem(QString::number(up->getTargetGlucose()))
        );
    }
}

void ProfileFormWidget::updateProfile(Profile *p) const
{
    if (!p) return;

    // Basic fields
    p->setTitle(titleLineEdit->text().toStdString());
    p->setInsulinDuration(insulinDurationEdit->time());
    p->setMaxBolus(maxBolusEdit->text().toFloat());
    p->setIncludeCarbs(carbCheckbox->isChecked());

    // Rebuild time-settings
    p->clearTimeSettings();
    int rows = timeTable->rowCount();
    for (int i = 0; i < rows; ++i) {
        // get values
        auto *te = qobject_cast<QTimeEdit*>(timeTable->cellWidget(i, 0));
        QTime tm = te ? te->time() : QTime(0,0);
        float basal  = timeTable->item(i,1)->text().toFloat();
        float corr   = timeTable->item(i,2)->text().toFloat();
        float carb   = timeTable->item(i,3)->text().toFloat();
        float target = timeTable->item(i,4)->text().toFloat();

        // create and add
        std::unique_ptr<InsulinDeliveryProfile> idpPtr(
            new InsulinDeliveryProfile(basal, carb, corr, target, tm)
        );
        p->addTimeSetting(std::move(idpPtr));
    }
}

