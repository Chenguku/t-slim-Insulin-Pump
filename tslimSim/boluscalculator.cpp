#include "boluscalculator.h"
#include <iostream>
BolusCalculator::BolusCalculator(float c, float bg, InsulinDeliveryProfile* profile, float iob, int now, int later, QTime duration):
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
QTime BolusCalculator::getDuration() const                      { return duration; }
float BolusCalculator::getDurationFloat() const                 { return duration.hour() + duration.minute() / 60.0f; /*get the total time in hours*/ }

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
    return getFinalBolus() * (getNow() / 100.0);
}

float BolusCalculator::getExtendedBolus() const {
    return getFinalBolus() * (getLater() / 100.0);
}

float BolusCalculator::getBolusRate() const {
    return getExtendedBolus() / getDurationFloat();
}


//setters
void BolusCalculator::setCarbValue(float c)                          { carbValue = c; }
void BolusCalculator::setBloodGlucose(float bg)                      { bloodGlucose = bg; }
void BolusCalculator::setCurProfile(InsulinDeliveryProfile* profile) { curProfile = profile; }
void BolusCalculator::setIOB(float iob)                              { IOB = iob; }
void BolusCalculator::setNow(int now)                                { deliverNowPercentage = now; }
void BolusCalculator::setLater(int later)                            { deliverLaterPercentage = later; }
void BolusCalculator::setDuration(const QTime& dur)                  { duration = dur; }






QString BolusCalculator::logCalculations() const {
    QString output = "";
    output.append(QString("Food (Carb) Bolus = %1 / %2 = %3\n").arg(carbValue).arg(ICR).arg(this->getFoodBolus()));
    output.append(QString("Correction Bolus = (%1 - %2) / %3 = %4\n").arg(bloodGlucose).arg(curProfile->getTargetGlucose()).arg(CF).arg(this->getCorrectionBolus()));
    output.append(QString("Total Bolus (Before IOB) = %1 + %2 = %3\n").arg(this->getFoodBolus()).arg(this->getCorrectionBolus()).arg(this->getTotalBolus()));
    output.append(QString("Final Bolus (After IOB) = %1 - %2 = %3\n\n").arg(this->getTotalBolus()).arg(this->getIOB()).arg(this->getFinalBolus()));
    output.append(QString("Immediate Bolus (%1\%) = %2 x %3 = %4\n").arg(this->getNow()).arg(this->getFinalBolus()).arg(this->getNow() / 100.0).arg(this->getImmediateBolus()));
    output.append(QString("Extended Bolus (%1\%) = %2 x %3 = %4\n").arg(this->getLater()).arg(this->getFinalBolus()).arg(this->getLater() / 100.0).arg(this->getExtendedBolus()));
    output.append(QString("Bolus Per Hour = %1 / %2 = %3\n").arg(this->getExtendedBolus()).arg(this->getDurationFloat()).arg(this->getBolusRate()));


    std::cout << output.toStdString() << std::endl;

    return output;
}


void BolusCalculator::populateDefaultValues(){
    deliverNowPercentage    = DELIVER_NOW;
    deliverLaterPercentage  = DELIVER_LATER;
    duration = QTime(0, 0).addSecs(DEFAULT_DURATION * 60);
}


