#pragma once
#include <string>
#include <vector>
#include<tuple>
#include <random>

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
		sort_tuple(indexed_list);
	}

	//operator std::string() const {
	//	string return_list_str;

	//	for (tuple<int, int, string, string> entry : indexed_list) {
	//		return_list_str += (get<3>(entry)) + "\n";
	//	}

	//	return return_list_str;
	//}

	string print_result() {
		string return_list_str = "";
		
		for (tuple<int, int, string, string> entry : indexed_list) {
			return_list_str += get<2>(entry) + " (page " + to_string(get<0>(entry) + 1) + "): " + get<3>(entry) + "\n";
		}

		return return_list_str;
	}

private:
	void clear_text(vector<string>& line);
	vector<tuple<int, string>> find_key_words(vector<string> line);
	void add_context_everything();
	void split_everything(vector<string>& init_lines, bool is_orig = false);
	void sort_tuple(vector<tuple<int, int, string, string>>);
};