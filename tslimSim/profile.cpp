#include "profile.h"
#include <iostream>
#include <algorithm>

Profile::Profile()
    : title(""),
      insulinDuration(QTime(0, 0)),
      maxBolus(0.0f),
      includeCarbs(false)
{}

Profile::Profile(const std::string &title)
    : title(title),
      insulinDuration(QTime(0, 0)),
      maxBolus(0.0f),
      includeCarbs(false)
{}

std::string Profile::getTitle() const {return title;}

const std::vector<std::unique_ptr<InsulinDeliveryProfile>>& Profile::getTimeSettings() const { return timeSettings; }

const QTime& Profile::getInsulinDuration() const {return insulinDuration;}

float Profile::getMaxBolus() const {return maxBolus;}

bool Profile::getIncludeCarbs() const {return includeCarbs;}

InsulinDeliveryProfile* Profile::getActiveDeliveryProfile(const QDateTime &now) const {
    if (timeSettings.empty())
        return nullptr;

    QTime current = now.time();
    auto it = std::upper_bound(
        timeSettings.begin(), timeSettings.end(),
        current,
        [](QTime t, std::unique_ptr<InsulinDeliveryProfile> const& up){
            return t < up->getTime();
        }
    );

    // all time settings have time > now, means the latest time setting
    if (it == timeSettings.begin()) {
        return timeSettings.back()->getTime(), timeSettings.back().get();
    } else {
        return std::prev(it)->get();
    }
}

void Profile::setTitle(const std::string &title) {this->title = title;}

void Profile::setInsulinDuration(const QTime &duration) {insulinDuration = duration;}

void Profile::setMaxBolus(float maxBolus){this->maxBolus = maxBolus;}

void Profile::setIncludeCarbs(bool include) {includeCarbs = include;}

void Profile::addTimeSetting(std::unique_ptr<InsulinDeliveryProfile> setting) {
    timeSettings.emplace_back(std::move(setting));
    this->sortTimeSettings();
}

void Profile::clearTimeSettings() {
    timeSettings.clear();
}

void Profile::sortTimeSettings()
{
    std::sort(
        timeSettings.begin(),
        timeSettings.end(),
        [](const std::unique_ptr<InsulinDeliveryProfile>& a,
           const std::unique_ptr<InsulinDeliveryProfile>& b)
        {
            return a->getTime() < b->getTime();
        }
    );
}

void Profile::print() const {
    std::cout << "PROFILE  " << title << " CREATED" << std::endl;
}
