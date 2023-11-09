#include "Event.cpp"

class EventListener {
public:
    virtual void onEvent(Event* event) = 0;
};