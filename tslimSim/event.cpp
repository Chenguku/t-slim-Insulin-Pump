#include "event.h"

Event::Event(): eventTime(0) {}
Event::Event(int i): eventTime(i) {}
Event::~Event() {}
//Event::Event(int i, std::string e, std::string info): eventTime(i), eventName(e), information(info) {}

int Event::getEventTime() const{return eventTime;}
//std::string Event::getEventName() const{return eventName;}
//std::string Event::getInformation() const{return information;}
