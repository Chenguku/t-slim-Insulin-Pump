#ifndef INSULINDELIVERYEVENT_H
#define INSULINDELIVERYEVENT_H

#include "event.h"

class InsulinDeliveryEvent : public Event{
    public:
        InsulinDeliveryEvent(int, float);
        QString getInformation() override;
    private:
        float unitsDelivered;
};

#endif // INSULINDELIVERYEVENT_H
