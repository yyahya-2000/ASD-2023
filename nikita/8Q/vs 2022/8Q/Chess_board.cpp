#include "Chess_board.h"

void Chess_board::print_queens() {
    cout << "=========Version " + to_string(chess_event->counter) + "==========" << endl;
    cout << (queens.size() == 8) ? "SUCCESS" : "TIMEOUT";
    for (int i = 0; i < queens.size(); ++i) {
        cout << to_string(queens[i].position_x) + ":" + to_string(queens[i].position_y) << endl;
    }
    
    cout << endl;
}

void Chess_board::print_board() {
    string result = "";

    for (int y = 0; y < this->get_size_y(); ++y) {
        for (int x = 0; x < this->get_size_x(); ++x) {
            result += this->get_value(y, x) ? "1 " : "0 ";
        }
        result += "\n";
    }

    cout << result << endl;
    cout << "====================================" << endl;
}

void Chess_board::place_queen(int index_x, int index_y) {
    board[index_y][index_x] = true;
}

void Chess_board::displace_queen(int index_x, int index_y) {
    board[index_y][index_x] = false;
}

bool Chess_board::check_cell(int index_x, int index_y) {
    return board[index_y][index_x];
}

void Chess_board::start()
{
    algo();
}

void Chess_board::init_board(int size_x, int size_y) {
    vector<bool> line(size_x);

    for (int y = 0; y < size_y; ++y) {
        board.push_back(line);
    }
}

void Chess_board::recreate_board(vector<vector<bool>> prev_board) {
    vector<bool> current_line;

    for (int y = 0; y < prev_board.size(); ++y) {
        current_line.clear();
        for (int x = 0; x < prev_board[y].size(); ++x) {
            current_line.push_back(prev_board[y][x]);
        }

        board.push_back(current_line);
    }
}

void Chess_board::recreate_queens(vector<Queen> prev_queens) {
    for (int i = 0; i < prev_queens.size(); ++i) {
        queens.push_back(prev_queens[i]);
    }
}

void Chess_board::algo(int prev_index) {
    for (int queen_index = ++prev_index; queen_index < 64; ++queen_index) {
        if (queens.size() == 8) {
            chess_event->solutions++;
            return;
        } 
        
        //cout << to_string(queen_index % 8) + " " + to_string(queen_index / 8) + ": " + to_string(queens.size()) << endl;

        Queen queen(queen_index % 8, queen_index / 8);

        if (!check_cell(queen.position_x, queen.position_y) && queen.check(*this)) {
            place_queen(queen.position_x, queen.position_y);
            queens.push_back(queen);

            Chess_board new_board(chess_event, publisher, board, queens, queen_index); // new_board
            //std::thread(new_board);
        }
        displace_queen(queen.position_x, queen.position_y);
        queens.pop_back();
    }
}