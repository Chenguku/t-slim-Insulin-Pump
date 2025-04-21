#include "alertevent.h"

AlertEvent::AlertEvent(QDateTime time, QString warning): Event(time), warningType(warning){}

QString AlertEvent::getInformation(){
    return warningType;
}
