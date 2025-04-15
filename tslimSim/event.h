#ifndef EVENT_H
#define EVENT_H

class Event{
    public:
        Event();
        Event(int);
        //make event an abstract class, events will implement log functions
        virtual void log() = 0;

        //getters
        int getEventTime() const;
    private:
        int eventTime;
};

#endif // EVENT_H
