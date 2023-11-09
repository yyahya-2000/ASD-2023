#include <iostream>
#include <string>
#include "../8Q/Queen.h"
#include "../8Q/Chess_board.h"

class Event {
public:
    virtual ~Event() {}

    int counter = 0;
    int solutions = 0;
};