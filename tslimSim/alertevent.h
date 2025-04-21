#ifndef ALERTEVENT_H
#define ALERTEVENT_H

#include <QString>
#include <QDateTime>

#include "event.h"

class AlertEvent : public Event{
    public:
        AlertEvent(QDateTime, QString);
        QString getInformation() override;
    private:
        QString warningType;
};

#endif // ALERTEVENT_H
