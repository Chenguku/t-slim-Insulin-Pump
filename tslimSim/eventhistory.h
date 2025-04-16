#ifndef EVENTHISTORY_H
#define EVENTHISTORY_H

#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include "event.h"

#define RECENT_EVENTS   90

class EventHistory{
    public:
        EventHistory();
        ~EventHistory();
        void addEvent(Event*);
        std::vector<Event*> recentEvents();

        //test function
        //void createEvents();

        //getters
        int getNumEvents() const;
    private:
        int numEvents;
        std::vector<Event*> eventsList;
};

#endif // EVENTHISTORY_H
