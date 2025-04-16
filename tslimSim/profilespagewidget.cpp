#include "profilespagewidget.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QRadioButton>
#include <QTableWidgetItem>
#include <QDebug>

ProfilesPageWidget::ProfilesPageWidget(QWidget *parent)
    : QWidget(parent), activeIndex(-1)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(2);
    QStringList headers;
    headers << "Title" << "Active";
    tableWidget->setHorizontalHeaderLabels(headers);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(tableWidget);

    radioGroup = new QButtonGroup(this);
    radioGroup->setExclusive(true);

    setLayout(layout);
}

ProfilesPageWidget::~ProfilesPageWidget()
{
    for (auto p : profiles)
        delete p;
}

void ProfilesPageWidget::addProfile(Profile* profile)
{
    profiles.push_back(profile);
    refreshTable();
}

void ProfilesPageWidget::refreshTable()
{
    tableWidget->clearContents();
    tableWidget->setRowCount(0);
    QList<QAbstractButton*> buttons = radioGroup->buttons();
    for(auto btn : buttons)
        radioGroup->removeButton(btn);

    for (int i = 0; i < static_cast<int>(profiles.size()); ++i)
    {
        tableWidget->insertRow(i);
        Profile* profile = profiles[i];

        QTableWidgetItem *titleItem = new QTableWidgetItem(QString::fromStdString(profile->getTitle()));
        tableWidget->setItem(i, 0, titleItem);

        QRadioButton *activeRadio = new QRadioButton(this);
        activeRadio->setChecked(i == activeIndex);
        radioGroup->addButton(activeRadio, i);

        connect(activeRadio, &QRadioButton::toggled, this, [this, i](bool checked) {
            if (checked)
            {
                activeIndex = i;
                emit activeProfileChanged(profiles[i]);
            }
        });

        tableWidget->setCellWidget(i, 1, activeRadio);
    }
}

Profile* ProfilesPageWidget::getActiveProfile() const
{
    if (activeIndex >= 0 && activeIndex < static_cast<int>(profiles.size()))
        return profiles[activeIndex];
    return nullptr;
}
