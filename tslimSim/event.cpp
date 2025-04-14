#include "event.h"

Event::Event(): eventTime(0) {}
Event::Event(int i): eventTime(i) {}

int Event::getEventTime() const{return eventTime;}
