#include "cgm.h"

CGM::CGM(): currentBloodGlucose(7) {}
CGM::CGM(float initialBG): currentBloodGlucose(initialBG) {}

float CGM::getCurrentBG() const    { return currentBloodGlucose; }
void CGM::setProfile(Profile *p)   { activeProfile = p; }
void CGM::setBGReader(GlucoseReader_Mock *r) { mock_reader = r; }
float CGM::readBG_mock()          { return mock_reader->getBG(); }
void CGM::addEffect(const GlucoseEffect &effect) { mock_reader->addEffect(effect); }
float CGM::predictBG(int ticks){
    return currentBloodGlucose + (currentBloodGlucose - previousBloodGlucose) * ticks;
}

float CGM::basalDelivery(int insulinOnBoard){
    previousBloodGlucose = currentBloodGlucose;
    currentBloodGlucose = readBG_mock();
    float projectedBG = predictBG(6);
    if(true){
        return 0;
    }
    float insulinUnitsDelivered = 0; //default below target

    if(projectedBG > activeProfile->getTimeSettings()[0].getTargetGlucose()){
        GlucoseEffect e = {activeProfile->getTimeSettings()[0].getBasalRate(), 1};
        addEffect(e);
    }

    if(insulinOnBoard < insulinUnitsDelivered){
        insulinUnitsDelivered = insulinOnBoard;
    }
    return insulinUnitsDelivered;
}

