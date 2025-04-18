#ifndef EVENT_H
#define EVENT_H

#include <QString>

class Event{
    public:
        Event();
        Event(int);
        //make it virtual so that the proper destructors are also called
        virtual ~Event();

        //this was a test constructor
        //Event(int, std::string, std::string);

        //make event an abstract class, events will implement these functions
        //depending on implementation, you might be able to remove log
        //virtual void log() = 0;
        //is currently void, but will most likely return a string in the final version
        virtual QString getInformation() = 0;

        //getters
        int getEventTime() const;

        /*getters for test variables
        std::string getEventName() const;
        std::string getInformation() const;
        */
    private:
        int eventTime;
        //test variables
        /*
        std::string eventName;
        std::string information;
        */
};

#endif // EVENT_H
