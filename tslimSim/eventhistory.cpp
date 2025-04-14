#include "eventhistory.h"

EventHistory::EventHistory(){
    numEvents = 0;
}

EventHistory::~EventHistory(){
    for (int i = 0; i < numEvents; i++){
        delete eventsList[i];
    }
}

//getters
int EventHistory::getNumEvents() const{return numEvents;}

void EventHistory::addEvent(Event* e){
    eventsList.push_back(e);
    numEvents++;
}

std::vector<Event*> EventHistory::lastTenEvents(){
    std::vector<Event*> result;

    //start copying elements from most recent to least recent
    if (numEvents < 10){
        for (int i = numEvents - 1; i >= 0; i--){
            result.push_back(eventsList[i]);
        }
    }
    else{
        for (int i = numEvents - 1; i >= numEvents - 10; i--){
            result.push_back(eventsList[i]);
        }
    }

    return result;
}

/*
void EventHistory::createEvents(){
    for (int i = 0; i < 10; i++){
        addEvent(new Event(i));
    }
}
*/


