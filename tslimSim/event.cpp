#include "event.h"

Event::Event() {}
Event::Event(QDateTime t): eventTime(t) {}
Event::~Event() {}

QDateTime Event::getEventTime() const{return eventTime;}

QString Event::formattedTime() const{return eventTime.time().toString("hh:mm");}
