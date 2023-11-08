#include <iostream>
#include <vector>
#include "Chess_board.h"
#include "Queen.h"

using namespace std;

Chess_board board;
int counter = 0;
vector<Queen> queens;

void print_result() {
    ++counter;
    cout << "=========Version " + to_string(counter) + "==========" << endl;
    for (int i = 0; i < queens.size(); ++i) {
        cout << to_string(queens[i].position_x) + ":" + to_string(queens[i].position_y) << endl;
    }
    cout << "====================================" << endl;
    cout << endl;
}

void algo() {
    for (int queen_index = 0; queen_index < 64; ++queen_index) {
        if (queens.size() == 8) return;
        
        Queen queen = Queen(queen_index % 8, queen_index / 8);
        
        if (!board.check_cell(queen.position_x, queen.position_y) && queen.check(board)) {
            board.place_queen(queen.position_x, queen.position_y);
            queens.push_back(queen);
            
            algo();
        }
    }
}

void to_defaults();

int main() {
    board = Chess_board();
    
    // x is horizontal
    // y is vertical
    
    algo();
    print_result();
}


