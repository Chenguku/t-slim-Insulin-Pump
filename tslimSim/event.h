#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QDateTime>

class Event{
    public:
        Event();
        Event(QDateTime);
        //make it virtual so that the proper destructors are also called
        virtual ~Event();
        virtual QString getInformation() = 0;

        //getters
        QDateTime getEventTime() const;

        //formatted time
        QString formattedTime() const;


    private:
        QDateTime eventTime;
};

#endif // EVENT_H
