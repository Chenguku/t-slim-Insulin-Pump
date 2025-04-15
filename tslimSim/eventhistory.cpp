#include "eventhistory.h"

EventHistory::EventHistory(){
    numEvents = 0;
    createEvents();
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

std::vector<Event*> EventHistory::recentEvents(){
    std::vector<Event*> result;

    //start copying elements from most recent to least recent
    if (numEvents < RECENT_EVENTS){
        for (int i = numEvents - 1; i >= 0; i--){
            result.push_back(eventsList[i]);
        }
    }
    else{
        for (int i = numEvents - 1; i >= numEvents - RECENT_EVENTS; i--){
            result.push_back(eventsList[i]);
        }
    }

    return result;
}


void EventHistory::createEvents(){
    std::string eventNames[5] = {"NRG", "SEN", "MIBR", "G2", "KRU"};
    std::string ratings[5] = {"FNS", "N4RRATE", "ASPAS", "JAWGEMO", "SHYY"};
    int randomNum;
    std::srand(std::time(nullptr));
    for (int i = 0; i < 1000; i++){
        randomNum = rand() % 5;
        addEvent(new Event(i+1, eventNames[randomNum], ratings[randomNum]));
    }
}



