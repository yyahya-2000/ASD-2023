#include "EventListener.cpp"

class EventPublisher {
public:
    void addListener(EventListener* listener) {
        listeners.push_back(listener);
    }

    void publishEvent(Event* event) {
        for (auto listener : listeners) {
            listener->onEvent(event);
        }
    }

private:
    std::vector<EventListener*> listeners;
};