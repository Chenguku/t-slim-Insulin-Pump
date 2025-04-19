#include "cgm.h"

CGM::CGM(): currentBloodGlucose(7) {
    activeProfile = new Profile();
    InsulinDeliveryProfile profile(0.715, 10, 2.8, 6.5, QTime());
    activeProfile->addTimeSetting(profile);
}
CGM::CGM(float initialBG): currentBloodGlucose(initialBG) {}

float CGM::getCurrentBG() const    { return currentBloodGlucose; }
void CGM::setProfile(Profile *p)   { activeProfile = p; }
void CGM::setBGReader(GlucoseReader_Mock *r) { mock_reader = r; }
void CGM::setInsulinUnits(float units) { insulinUnits = units; }
float CGM::readBG_mock()           { return mock_reader->getBG(); }
void CGM::adjustBG(float x)        { addEffect((GlucoseEffect) {x, 1}); }
void CGM::addEffect(const GlucoseEffect &effect) { mock_reader->addEffect(effect); }

float CGM::predictBG(int ticks){
    return currentBloodGlucose + (currentBloodGlucose - previousBloodGlucose) * ticks;
}

float CGM::basalDelivery(){
    previousBloodGlucose = currentBloodGlucose;
    currentBloodGlucose = readBG_mock();
    float projectedBG = predictBG(6);

    float insulinUnitsDelivered = 0; //default below target

    if(projectedBG > activeProfile->getTimeSettings()[0].getTargetGlucose() && insulinUnits > 0){
        GlucoseEffect e = {(activeProfile->getTimeSettings()[0].getBasalRate() / 12) * activeProfile->getTimeSettings()[0].getCorrectionFactor(), 1};
        addEffect(e);
    }

     insulinUnitsDelivered = mock_reader->applyEffects(insulinUnits * activeProfile->getTimeSettings()[0].getCorrectionFactor());

    if(insulinUnits < insulinUnitsDelivered){
        insulinUnitsDelivered = insulinUnits;
    }
    return insulinUnitsDelivered;
}

