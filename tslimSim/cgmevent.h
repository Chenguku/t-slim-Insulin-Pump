#ifndef CGMEVENT_H
#define CGMEVENT_H

#include "event.h"

class CGMEvent : public Event{

    public:
        CGMEvent(int, float);
        QString getInformation() override;

    private:
        float currentBloodGlucose;
};

#endif // CGMEVENT_H
