#include "cgm.h"

CGM::CGM(): currentBloodGlucose(7) {
    activeProfile = nullptr;
}

CGM::CGM(float initialBG): currentBloodGlucose(initialBG) {
    activeProfile = nullptr;
}

float CGM::getCurrentBG() const    { return currentBloodGlucose; }
void CGM::setProfile(Profile *p)   { activeProfile = p; }
void CGM::setBGReader(GlucoseReader_Mock *r) { mock_reader = r; }
void CGM::setInsulinUnits(float units) { insulinUnits = units; }
float CGM::readBG_mock()           { return mock_reader->getBG(); }
void CGM::adjustBG(float x)        { addEffect((GlucoseEffect) {x, 1}); }
void CGM::addEffect(const GlucoseEffect &effect) { mock_reader->addEffect(effect); }
float CGM::getIOB()                { return mock_reader->getIOB(); }
int CGM::getExtended()             { return mock_reader->getIOBTime() * 5; }


float CGM::predictBG(int ticks){
    return currentBloodGlucose + (currentBloodGlucose - previousBloodGlucose) * ticks/2;
}

float CGM::basalDelivery(){
    previousBloodGlucose = currentBloodGlucose;
    currentBloodGlucose = readBG_mock();
    float projectedBG = predictBG(6);

    if(projectedBG > 10 && insulinUnits > 0){
        GlucoseEffect e = {projectedBG - 10, 1};
        addEffect(e);
    }

    if(activeProfile == nullptr){
        float insulinUnitsDelivered = mock_reader->applyEffects(insulinUnits);
        return insulinUnitsDelivered;
    }

    float insulinUnitsDelivered = 0; //default below target


    if(projectedBG <= 10 && projectedBG > activeProfile->getTimeSettings()[0]->getTargetGlucose() && insulinUnits > 0){
        GlucoseEffect e = {(activeProfile->getTimeSettings()[0]->getBasalRate() / 12) * activeProfile->getTimeSettings()[0]->getCorrectionFactor(), 1};
        addEffect(e);
    }

     insulinUnitsDelivered = mock_reader->applyEffects(insulinUnits * activeProfile->getTimeSettings()[0]->getCorrectionFactor());

    if(insulinUnits < insulinUnitsDelivered){
        insulinUnitsDelivered = insulinUnits;
    }
    return insulinUnitsDelivered;
}

