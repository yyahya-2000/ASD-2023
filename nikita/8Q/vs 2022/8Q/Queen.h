#pragma once
#include "Chess_board.h"

class Queen {
public:
    int position_x;
    int position_y;

public:
    Queen(int x, int y) {
        position_x = x;
        position_y = y;
    }

    bool check(Chess_board board);
};
