#include "boluscalculator.h"
#include <iostream>
BolusCalculator::BolusCalculator(float c, float bg, InsulinDeliveryProfile* profile, float iob, int now, int later, int duration):
    carbValue(c),
    bloodGlucose(bg),
    curProfile(profile),
    IOB(iob),
    deliverNowPercentage(now),
    deliverLaterPercentage(later),
    duration(duration)
{}


//getters
float BolusCalculator::getCarbValue() const                     { return carbValue; }
float BolusCalculator::getBloodGlucose() const                  { return bloodGlucose; }
InsulinDeliveryProfile* BolusCalculator::getCurProfile() const  { return curProfile; }
float BolusCalculator::getIOB () const                          { return IOB; }
int BolusCalculator::getNow() const                             { return deliverNowPercentage; }
int BolusCalculator::getLater() const                           { return deliverLaterPercentage; }
int BolusCalculator::getDuration() const                        { return duration; }

float BolusCalculator::getFoodBolus() const                     { return (carbValue / ICR); }

float BolusCalculator::getCorrectionBolus() const {
    return (bloodGlucose - curProfile->getTargetGlucose()) / CF;
}

float BolusCalculator::getTotalBolus() const {
    return getFoodBolus() + getCorrectionBolus();
}

float BolusCalculator::getFinalBolus() const {
    return getTotalBolus() - IOB;
}

float BolusCalculator::getImmediateBolus() const {
    return getFinalBolus() * 0.6;
}

float BolusCalculator::getExtendedBolus() const {
    return getFinalBolus() * 0.4;
}

float BolusCalculator::getBolusRate(int hours) const {
    return getExtendedBolus() / hours;
}


//setters
void BolusCalculator::setCarbValue(float c)         { carbValue = c; }
void BolusCalculator::setBloodGlucose(float bg)     { bloodGlucose = bg; }
void BolusCalculator::setIOB(float iob)             { IOB = iob; }
void BolusCalculator::setNow(int now)               { deliverNowPercentage = now; }
void BolusCalculator::setLater(int later)           { deliverLaterPercentage = later; }
void BolusCalculator::setDuration(int dur)          { duration = dur; }






QString BolusCalculator::logCalculations() const {
    QString output = "";
    output.append(QString("Food (Carb) Bolus = %1 / %2 = %3\n").arg(carbValue).arg(ICR).arg(this->getFoodBolus()));
    output.append(QString("Correction Bolus = (%1 - %2) / %3 = %4\n").arg(bloodGlucose).arg(curProfile->getTargetGlucose()).arg(CF).arg(this->getCorrectionBolus()));
    output.append(QString("Total Bolus (Before IOB) = %1 + %2 = %3\n").arg(this->getFoodBolus()).arg(this->getCorrectionBolus()).arg(this->getTotalBolus()));
    output.append(QString("Final Bolus (After IOB) = %1 - %2 = %3\n\n").arg(this->getTotalBolus()).arg(this->getIOB()).arg(this->getFinalBolus()));
    output.append(QString("Immediate Bolus (60%) = 0.6 x %1 = %2\n").arg(this->getFinalBolus()).arg(this->getImmediateBolus()));



    std::cout << output.toStdString() << std::endl;

    return output;
}


void BolusCalculator::populateDefaultValues(){
    deliverNowPercentage    = DELIVER_NOW;
    deliverLaterPercentage  = DELIVER_LATER;
    duration                = DEFAULT_DURATION;
}


