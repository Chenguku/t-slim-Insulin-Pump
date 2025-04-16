#ifndef PROFILES_PAGE_WIDGET_H
#define PROFILES_PAGE_WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QButtonGroup>
#include <vector>
#include "profile.h"

class ProfilesPageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ProfilesPageWidget(QWidget *parent = nullptr);
    ~ProfilesPageWidget();

    void addProfile(Profile* profile);

    Profile* getActiveProfile() const;

signals:
    void activeProfileChanged(Profile* profile);

private:
    void refreshTable();

    QTableWidget *tableWidget;
    QButtonGroup *radioGroup;
    std::vector<Profile*> profiles;
    int activeIndex;
};

#endif // PROFILES_PAGE_WIDGET_H
