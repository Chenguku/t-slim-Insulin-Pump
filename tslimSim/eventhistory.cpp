#include "eventhistory.h"

EventHistory::EventHistory(){
    numEvents = 0;
    //createEvents();
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

std::vector<Event*> EventHistory::recentEvents(QString filter){
    std::vector<Event*> result;

    //start copying elements from most recent to least recent based on filter
    if (filter == "CGM Reading"){
        result = recentCGMEvents();
    }
    else if (filter == "Insulin Delivery"){
        result = recentInsulinEvents();
    }
    else if (filter == "Warning"){
        result = recentWarningEvents();
    }

    return result;
}

std::vector<Event*> EventHistory::recentCGMEvents(){
    std::vector<Event*> filtered;
    for (int i = numEvents - 1; i >= 0; i--){
        if (filtered.size() >= RECENT_EVENTS) break;
        if (dynamic_cast<CGMEvent*>(eventsList[i])){
            filtered.push_back(eventsList[i]);
        }
    }
    return filtered;
}

std::vector<Event*> EventHistory::recentInsulinEvents(){
    std::vector<Event*> filtered;
    for (int i = numEvents - 1; i >= 0; i--){
        if (filtered.size() >= RECENT_EVENTS) break;
        if (dynamic_cast<InsulinDeliveryEvent*>(eventsList[i])){
            filtered.push_back(eventsList[i]);
        }
    }
    return filtered;
}

std::vector<Event*> EventHistory::recentWarningEvents(){
    //Warnings class has not been created yet
    std::vector<Event*> filtered;
    for (int i = numEvents - 1; i >= 0; i--){
        if (filtered.size() >= RECENT_EVENTS) break;
        if (dynamic_cast<AlertEvent*>(eventsList[i])){
            filtered.push_back(eventsList[i]);
        }
    }
    return filtered;
}

/*
 * Test function
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
*/



