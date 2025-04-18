#include "cgm.h"

CGM::CGM(): currentBloodGlucose(7) {}
CGM::CGM(float initialBG): currentBloodGlucose(initialBG) {}

float CGM::getCurrentBG() const    { return currentBloodGlucose; }
void CGM::setProfile(Profile *p)   { activeProfile = p; }
void CGM::setBGReader(GlucoseReader_Mock *r) { mock_reader = r; }
float CGM::readBG_mock()          { return mock_reader->getBG(); }

float CGM::basalDelivery(int insulinOnBoard){
    currentBloodGlucose = readBG_mock();
    float insulinDelivered = 0; //default below target

    if(currentBloodGlucose > 10.0){

    }

    if(insulinOnBoard < insulinDelivered){
        insulinDelivered = insulinOnBoard;
    }
    return insulinDelivered;
}

