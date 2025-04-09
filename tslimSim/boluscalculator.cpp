#include "boluscalculator.h"

BolusCalculator::BolusCalculator(float c, float bg): carbValue(c), bloodGlucose(bg) {}


//getters
float BolusCalculator::getCarbValue() const         { return carbValue; }
float BolusCalculator::getBloodGlucose() const      { return bloodGlucose; }

float BolusCalculator::getCarbBolus() const         { return (carbValue / ICR); }

float BolusCalculator::getCorrectionBolus() const {
}

float BolusCalculator::getTotalBolus() const {}
float BolusCalculator::getFinalBolus() const {}
float BolusCalculator::getImmediateBolus() const {}
float BolusCalculator::getExtendedBolus() const {}
float BolusCalculator::getBolusRate() const {}


