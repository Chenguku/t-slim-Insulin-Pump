#include "profile.h"

//constructor
Profile::Profile(){
    basalRate = 0;
    carbRatio = 0;
    correctionFactor = 0;
    targetGlucose = 0;
}

//getters

float Profile::getBasalRate() const{
    return basalRate;
}

float Profile::getCarbRatio() const{
    return carbRatio;
}

float Profile::getCorrectionFactor() const{
    return correctionFactor;
}

float Profile::getTargetGlucose() const{
    return targetGlucose;
}
