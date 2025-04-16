#ifndef EVENTHISTORY_H
#define EVENTHISTORY_H

#include <QString>
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include "event.h"
#include "cgm.h"
#include "insulindeliveryprofile.h"

#define RECENT_EVENTS   90

class EventHistory{
    public:
        EventHistory();
        ~EventHistory();
        void addEvent(Event*);
        std::vector<Event*> recentEvents(QString);

        //test function
        //void createEvents();

        //getters
        int getNumEvents() const;
    private:
        int numEvents;
        std::vector<Event*> eventsList;

        //only EventHistory should be able to use these functions
        std::vector<Event*> recentCGMEvents();
        std::vector<Event*> recentInsulinEvents();
        std::vector<Event*> recentWarningEvents();
};

#endif // EVENTHISTORY_H
