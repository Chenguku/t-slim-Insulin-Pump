#include "cgm.h"

CGM::CGM(float initialBG): currentBloodGlucose(initialBG) {}

bool CGM::getStatus() const { return isConnected; }

float CGM::getCurrentBG() const     { return currentBloodGlucose; }
void CGM::setCurrentBG(float cbg)   { currentBloodGlucose = cbg; }

void CGM::adjustBG(float x)       { currentBloodGlucose += x; }

