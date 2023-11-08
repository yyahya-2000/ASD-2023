#pragma once
#include <string>
#include <vector>
#include<tuple>
#include <random>
#include <cstring>

using namespace std;

class Indexator
{
    int number;
    vector<vector<string>> lines;
    vector<vector<string>> orig_lines;
    vector<tuple<int, int, string, string>> indexed_list;

public:
    Indexator(int number, vector<string> lines) {
        this->number = number;
        vector<string> init_lines = lines;

        split_everything(init_lines, true);

        clear_text(init_lines);
        split_everything(init_lines);

        for (int i = 0; i < number; ++i) {
            for (tuple<int, string> tp : find_key_words(this->lines[i])) {
                if (get<1>(tp) != "")
                    indexed_list.push_back(make_tuple(i, get<0>(tp), get<1>(tp), ""));
            }
        }

        add_context_everything();
        lower_all_indexes();
        sort_indexes();
    }

    string print_result() {
        string return_list_str = "";

        for (tuple<int, int, string, string> entry : indexed_list) {
            if (get<2>(entry).size() > 7)
                return_list_str += get<2>(entry) + "\tpage " + to_string(get<0>(entry) + 1) + "\t\t" + get<3>(entry) + "\n";
            else
                return_list_str += get<2>(entry) + "\t\tpage " + to_string(get<0>(entry) + 1) + "\t\t" + get<3>(entry) + "\n";
        }

        return return_list_str;
    }

private:
    void clear_text(vector<string>& line);
    vector<tuple<int, string>> find_key_words(vector<string> line);
    void add_context_everything();
    void split_everything(vector<string>& init_lines, bool is_orig = false);
    void sort_indexes();
    void lower_all_indexes();
};
