#include "cgmevent.h"

CGMEvent::CGMEvent(QDateTime time, float bg): Event(time), currentBloodGlucose(bg){}

QString CGMEvent::getInformation(){
    return QString::number(currentBloodGlucose) + " mmol/L";
}
