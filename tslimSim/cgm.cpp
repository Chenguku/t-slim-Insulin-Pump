#include "cgm.h"

CGM::CGM(float initialBG): currentBloodGlucose(initialBG) {}

float CGM::getCurrentBG() const     { return currentBloodGlucose; }
void CGM::setCurrentBG(float cbg)   { currentBloodGlucose = cbg; }

void CGM::increaseBG(float x)       { currentBloodGlucose += x; }
void CGM::decreaseBG(float x)       { currentBloodGlucose += x; }

