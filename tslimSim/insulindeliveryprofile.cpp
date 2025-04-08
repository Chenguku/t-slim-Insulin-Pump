#include "insulindeliveryprofile.h"

InsulinDeliveryProfile::InsulinDeliveryProfile(float b, float c, float cr, float g, const std::string& t): basalRate(b), carbRatio(c), correctionFactor(cr), targetGlucose(g), time(t) {}


//getters
float InsulinDeliveryProfile::getBasalRate() const             { return basalRate; }
float InsulinDeliveryProfile::getCarbRatio() const             { return carbRatio; }
float InsulinDeliveryProfile::getCorrectionFactor() const      { return correctionFactor; }
float InsulinDeliveryProfile::getTargetGlucose() const         { return targetGlucose; }
const std::string& InsulinDeliveryProfile::getTime() const     { return time; }


//setters
void InsulinDeliveryProfile::setBasalRate(float b)             { basalRate = b; }
void InsulinDeliveryProfile::setCarbRatio(float c)             { carbRatio = c; }
void InsulinDeliveryProfile::setCorrectionFactor(float cr)     { correctionFactor = cr; }
void InsulinDeliveryProfile::setTargetGlucose(float g)         { targetGlucose = g; }
void InsulinDeliveryProfile::setTime(const std::string& t)     { time = t; }
