#include "boluscalculator.h"

BolusCalculator::BolusCalculator(float c, float bg, InsulinDeliveryProfile* profile, float iob):
    carbValue(c),
    bloodGlucose(bg),
    curProfile(profile),
    IOB(iob)
{}


//getters
float BolusCalculator::getCarbValue() const         { return carbValue; }
float BolusCalculator::getBloodGlucose() const      { return bloodGlucose; }

float BolusCalculator::getFoodBolus() const         { return (carbValue / ICR); }

float BolusCalculator::getCorrectionBolus() const {
    return (carbValue - curProfile->getTargetGlucose()) / CF;
}

float BolusCalculator::getTotalBolus() const {
    return getFoodBolus() + getCorrectionBolus();
}

float BolusCalculator::getFinalBolus() const {
    return getTotalBolus() - IOB;
}
float BolusCalculator::getImmediateBolus() const {}
float BolusCalculator::getExtendedBolus() const {}
float BolusCalculator::getBolusRate() const {}


//setters
void BolusCalculator::setCarbValue(float c){ carbValue = c; }
void BolusCalculator::setBloodGlucose(float bg){ bloodGlucose = bg; }
