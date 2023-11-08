#pragma once
#include <vector>

using namespace std;

class Chess_board {

    vector<vector<bool>> board;
    
public:
    Chess_board() {
        init_board(8, 8);
    }
    
    int get_size_x() {
        return board[get_size_y()].size();
    }
    
    int get_size_y() {
        return board.size();
    }
    
    bool check_cell(int index_x, int index_y);
    void place_queen(int index_x, int index_y);
    
private:
    void init_board(int size_x, int size_y);
};
