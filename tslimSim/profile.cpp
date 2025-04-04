#include "profile.h"

//constructor
Profile::Profile(float b, float c, float cr, float g): basalRate(b), carbRatio(c), correctionFactor(cr), targetGlucose(g) {}


//getters
float Profile::getBasalRate() const             { return basalRate; }
float Profile::getCarbRatio() const             { return carbRatio; }
float Profile::getCorrectionFactor() const      { return correctionFactor; }
float Profile::getTargetGlucose() const         { return targetGlucose; }

//setters
void Profile::setBasalRate(float b)             { basalRate = b; }
void Profile::setCarbRatio(float c)             { basalRate = c; }
void Profile::setCorrectionFactor(float cr)     { basalRate = cr; }
void Profile::setTargetGlucose(float g)         { basalRate = g; }
