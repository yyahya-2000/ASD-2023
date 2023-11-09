#pragma once

#include <string>
#include <vector>
#include <thread>

#include "Queen.h"
#include "../Events/Event.cpp"
#include "../Events/EventListener.cpp"
#include "../Events/EventPublisher.cpp"

using namespace std;

class Chess_board : public EventListener {

    vector<vector<bool>> board;
    vector<Queen> queens;
    Event* chess_event;
    EventPublisher* publisher;

public:
    int get_size_x() {
        return board[0].size();
    }

    int get_size_y() {
        return board.size();
    }

    bool get_value(int index_x, int index_y) { 
        return board[index_y][index_x]; 
    }

    bool check_cell(int index_x, int index_y);
    void place_queen(int index_x, int index_y);
    void displace_queen(int index_x, int index_y);

    //string to_string();

    Chess_board(Event* chess_event, EventPublisher* publisher) {
        init_board(8, 8);

        this->chess_event = chess_event;
        this->publisher = publisher;
        publisher->addListener((EventListener*)this);
    }

    Chess_board(Event* chess_event, EventPublisher* publisher, 
        vector<vector<bool>> prev_board, vector<Queen> prev_queens, int prev_index) {
        recreate_board(prev_board);
        recreate_queens(prev_queens);

        this->chess_event = chess_event;
        this->publisher = publisher;
        publisher->addListener((EventListener*)this);

        algo(prev_index);
    }

    void start();
private:
    void onEvent(Event* event) override {
        // Handle the event
        this->print_queens();
        this->print_board();
        event->counter++;
    }

    void init_board(int size_x, int size_y);
    void recreate_board(vector<vector<bool>> prev_board);
    void recreate_queens(vector<Queen> prev_queens);
    void algo(int prev_index = 0);

    void print_queens();
    void print_board();
};
