#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <vector>
#include <memory>                             // ← for std::unique_ptr
#include <QTime>
#include "insulindeliveryprofile.h"
#include <QDateTime>

class Profile
{
public:
    Profile();
    Profile(const std::string &title);

    // getters
    std::string getTitle() const;
    const std::vector<std::unique_ptr<InsulinDeliveryProfile>>& getTimeSettings() const;
    const QTime& getInsulinDuration() const;
    float getMaxBolus() const;
    bool getIncludeCarbs() const;
    InsulinDeliveryProfile* getActiveDeliveryProfile(const QDateTime& now) const;

    // setters
    void setTitle(const std::string &title);
    void setInsulinDuration(const QTime &duration);
    void setMaxBolus(float maxBolus);
    void setIncludeCarbs(bool include);

    // other
    void addTimeSetting(std::unique_ptr<InsulinDeliveryProfile> setting);
    void sortTimeSettings();
    void clearTimeSettings();
    void print() const;

private:
    std::string title;
    std::vector<std::unique_ptr<InsulinDeliveryProfile>> timeSettings;
    QTime insulinDuration;
    float maxBolus;
    bool includeCarbs;
};

#endif // PROFILE_H
