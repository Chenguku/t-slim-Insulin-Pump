#include "cgmevent.h"

CGMEvent::CGMEvent(int time, float bg): Event(time), currentBloodGlucose(bg){}

QString CGMEvent::getInformation(){
    return QString::number(currentBloodGlucose) + " mmol/L";
}
