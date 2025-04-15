#ifndef EVENTHISTORY_H
#define EVENTHISTORY_H

#include <vector>
#include <iostream>
#include "event.h"

class EventHistory{
    public:
        EventHistory();
        ~EventHistory();
        void addEvent(Event*);
        std::vector<Event*> lastTenEvents();

        //test function
        //void createEvents();

        //getters
        int getNumEvents() const;
    private:
        int numEvents;
        std::vector<Event*> eventsList;
};

#endif // EVENTHISTORY_H
