#include "profilespagewidget.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QRadioButton>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QDebug>

ProfilesPageWidget::ProfilesPageWidget(QWidget *parent)
    : QWidget(parent), activeIndex(-1)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(4);
    QStringList headers;
    headers << "Title" << "Active" << "Edit" << "Delete";
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
}

void ProfilesPageWidget::removeProfile(Profile* profile)
{
    // find profile
    auto it = std::find(profiles.begin(), profiles.end(), profile);
    if (it == profiles.end()) return;

    // compute index and delete
    int idx = std::distance(profiles.begin(), it);
    delete *it;
    profiles.erase(it);

    // adjust activeIndex
    if      (idx == activeIndex) activeIndex = -1;
    else if (idx <  activeIndex) --activeIndex;

    refreshTable();
}

void ProfilesPageWidget::refreshTable()
{
    tableWidget->clearContents();
    tableWidget->setRowCount(static_cast<int>(profiles.size()));

    QList<QAbstractButton*> buttons = radioGroup->buttons();
    for(auto btn : buttons)
        radioGroup->removeButton(btn);

    for (int i = 0; i < static_cast<int>(profiles.size()); ++i)
    {
        Profile* profile = profiles[i];

        // title
        QTableWidgetItem *titleItem = new QTableWidgetItem(QString::fromStdString(profile->getTitle()));
        tableWidget->setItem(i, 0, titleItem);

        // active
        QRadioButton *activeRadio = new QRadioButton(this);
        activeRadio->setChecked(i == activeIndex);
        radioGroup->addButton(activeRadio, i);
        connect(activeRadio, &QRadioButton::toggled, this, [this, i](bool checked) {
            if (checked)
            {
                activeIndex = i;
                refreshTable();
                emit activeProfileChanged(profiles[i]);
            }
        });
        tableWidget->setCellWidget(i, 1, activeRadio);

        // edit
        QPushButton *editBtn = new QPushButton("Edit", this);
        editBtn->setEnabled(i != activeIndex);
        connect(editBtn, &QPushButton::clicked, this, [this, i]() {
            if (i != activeIndex)
                emit editProfileRequested(profiles[i]);
        });
        tableWidget->setCellWidget(i, 2, editBtn);

        // delete
        QPushButton *deleteBtn = new QPushButton("Delete", this);
        deleteBtn->setEnabled(i != activeIndex);
        connect(deleteBtn, &QPushButton::clicked, this, [this, i]() {
            if (i != activeIndex)
                emit deleteProfileRequested(profiles[i]);
        });
        tableWidget->setCellWidget(i, 3, deleteBtn);

    }
}

Profile* ProfilesPageWidget::getActiveProfile() const
{
    if (activeIndex >= 0 && activeIndex < static_cast<int>(profiles.size()))
        return profiles[activeIndex];
    return nullptr;
}
