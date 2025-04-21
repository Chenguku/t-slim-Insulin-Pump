#ifndef INSULINDELIVERYEVENT_H
#define INSULINDELIVERYEVENT_H

#include <QTime>

#include "event.h"

class InsulinDeliveryEvent : public Event{
    public:
        InsulinDeliveryEvent(QDateTime, float);
        QString getInformation() override;
    private:
        float unitsDelivered;
};

#endif // INSULINDELIVERYEVENT_H
