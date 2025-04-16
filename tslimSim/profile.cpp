#include "profile.h"
#include <iostream>

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

const std::vector<InsulinDeliveryProfile>& Profile::getTimeSettings() const {return timeSettings;}

const QTime& Profile::getInsulinDuration() const {return insulinDuration;}

float Profile::getMaxBolus() const {return maxBolus;}

bool Profile::getIncludeCarbs() const {return includeCarbs;}

void Profile::setTitle(const std::string &title) {this->title = title;}

void Profile::setInsulinDuration(const QTime &duration) {insulinDuration = duration;}

void Profile::setMaxBolus(float maxBolus){this->maxBolus = maxBolus;}

void Profile::setIncludeCarbs(bool include) {includeCarbs = include;}

void Profile::addTimeSetting(const InsulinDeliveryProfile &setting) {
    timeSettings.push_back(setting);
}

void Profile::clearTimeSettings() {
    timeSettings.clear();
}

void Profile::print() const {
    std::cout << "PROFILE  " << title << " CREATED" << std::endl;
}
