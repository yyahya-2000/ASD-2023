#include "Chess_board.h"

void Chess_board::place_queen(int index_x, int index_y) {
    board[index_y][index_x] = true;
}

bool Chess_board::check_cell(int index_x, int index_y) {
    return board[index_y][index_x];
}

void Chess_board::init_board(int size_x, int size_y) {
    vector<bool> line(size_x);
    
    for (int y = 0; y < size_y; ++y) {
        board.push_back(line);
    }
}
