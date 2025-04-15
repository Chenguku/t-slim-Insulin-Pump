#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event{
    public:
        Event();
        Event(int);
        Event(int, std::string, std::string);
        //make event an abstract class, events will implement these functions
        //virtual void log() = 0;
        //virtual void getInformation() = 0;

        //getters
        int getEventTime() const;
        std::string getEventName() const;
        std::string getInformation() const;
    private:
        int eventTime;
        std::string eventName;
        std::string information;
};

#endif // EVENT_H
