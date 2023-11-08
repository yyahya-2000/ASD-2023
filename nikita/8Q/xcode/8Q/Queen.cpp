#include "Queen.h"

bool Queen::check(Chess_board board) {
    for (int y = 0; y < board.get_size_y(); ++y) {
        for (int x = 0; x < board.get_size_x(); ++x) {
            if (x == this->position_x && board.check_cell(x, y))
                return false;
            if (y == this->position_y && board.check_cell(x, y))
                return false;
            if ((abs(x - this->position_x) == abs(y - this->position_y)) && board.check_cell(x, y))
                return false;
        }
    }
    
    return true;
}
