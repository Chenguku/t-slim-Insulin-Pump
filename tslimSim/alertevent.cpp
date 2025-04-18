#include "alertevent.h"

AlertEvent::AlertEvent(int time, QString warning): Event(time), warningType(warning){}

QString AlertEvent::getInformation(){
    return warningType;
}
