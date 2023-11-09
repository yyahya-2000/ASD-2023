#include <iostream>
#include <string>
#include <vector>
#include "Chess_board.h"
#include "../Events/Event.cpp"
#include "../Events/EventListener.cpp"
#include "../Events/EventPublisher.cpp"

using namespace std;

int counter = 0;

int main() {
    Event* chess_event;
    EventPublisher publisher;
    
    Chess_board board(chess_event, &publisher);
    board.start();

    // join

    if (chess_event->solutions >= 12)
        publisher.publishEvent(chess_event);
    else
        cout << "NOT ENOUGHT SOLUTIONS! >> " + chess_event->solutions << endl;
}