#ifndef CGMEVENT_H
#define CGMEVENT_H

#include <QTime>

#include "event.h"

class CGMEvent : public Event{

    public:
        CGMEvent(QDateTime, float);
        QString getInformation() override;

    private:
        float currentBloodGlucose;
};

#endif // CGMEVENT_H
