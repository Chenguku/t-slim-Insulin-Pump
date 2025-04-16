#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <vector>
#include <QTime>
#include "insulindeliveryprofile.h"

class Profile
{
public:
    // constructors
    Profile();
    Profile(const std::string &title);

    // getters
    std::string getTitle() const;
    const std::vector<InsulinDeliveryProfile>& getTimeSettings() const;
    const QTime& getInsulinDuration() const;
    float getMaxBolus() const;
    bool getIncludeCarbs() const;

    // setters
    void setTitle(const std::string &title);
    void setInsulinDuration(const QTime &duration);
    void setMaxBolus(float maxBolus);
    void setIncludeCarbs(bool include);

    void addTimeSetting(const InsulinDeliveryProfile &setting);
    void clearTimeSettings();
    void print() const;

private:
    std::string title;
    std::vector<InsulinDeliveryProfile> timeSettings;
    QTime insulinDuration;
    float maxBolus;
    bool includeCarbs;
};

#endif // PROFILE_H
