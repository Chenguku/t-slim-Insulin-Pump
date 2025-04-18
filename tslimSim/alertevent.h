#ifndef ALERTEVENT_H
#define ALERTEVENT_H

#include <QString>

#include "event.h"

class AlertEvent : public Event{
    public:
        AlertEvent(int, QString);
        QString getInformation() override;
    private:
        QString warningType;
};

#endif // ALERTEVENT_H
