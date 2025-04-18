#include "insulindeliveryevent.h"

InsulinDeliveryEvent::InsulinDeliveryEvent(int time, float br): Event(time), basalRate(br){}

QString InsulinDeliveryEvent::getInformation(){
    return QString::number(basalRate);
}
