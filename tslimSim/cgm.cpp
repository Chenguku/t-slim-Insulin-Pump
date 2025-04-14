#include "cgm.h"

CGM::CGM(): currentBloodGlucose(7) {}
CGM::CGM(float initialBG): currentBloodGlucose(initialBG) {}

bool CGM::getStatus() const { return isConnected; }

float CGM::getCurrentBG() const     { return currentBloodGlucose; }
void CGM::setCurrentBG(float cbg)   { currentBloodGlucose = cbg; }
void CGM::setProfile(Profile *p) { activeProfile = p; }
void CGM::setBGReader(GlucoseReader_Mock *r) { mock_reader = r; }

void CGM::adjustBG(float x)       { currentBloodGlucose += x; }
float CGM::readBG_mock(){ return mock_reader->readBG_mock(); }

