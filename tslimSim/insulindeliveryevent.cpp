#include "insulindeliveryevent.h"

InsulinDeliveryEvent::InsulinDeliveryEvent(int time, float ud): Event(time), unitsDelivered(ud){}

QString InsulinDeliveryEvent::getInformation(){
    return QString::number(unitsDelivered) + " units";
}
