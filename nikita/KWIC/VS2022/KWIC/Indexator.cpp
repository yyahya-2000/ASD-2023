#include "Indexator.h"

void Indexator::clear_text(vector<string>& line)
{
	for (int i = 0; i < line.size(); ++i) {
		line[i].erase(remove_if(line[i].begin(), line[i].end(), [](char a) {return (a == '.') || (a == ',') || (a == '!'); }), line[i].end());
	}
}

vector<tuple<int, string>> Indexator::find_key_words(vector<string> line)
{
	vector<tuple<int, string>> result;

	for (int i = 0; i < line.size(); ++i) {
		if (rand() % 3 == 1)
			result.push_back(make_tuple(i, line[i]));
	}

	return result;
}

void Indexator::add_context_everything()
{
	int current_length;
	int start_index;
	int end_index;
	string result;

	for (int i = 0; i < indexed_list.size(); ++i) {
		current_length = orig_lines[get<0>(indexed_list[i])].size();

		start_index = rand() % (get<1>(indexed_list[i]) + 1);
		end_index = get<1>(indexed_list[i]) + rand() % (current_length - get<1>(indexed_list[i]));

		// 0 1 2 3 4 5
		// l d A s d a

		result = "";
		for (int word_i = start_index; word_i <= end_index; ++word_i) {
			if (result != "")
				result = result + " " + orig_lines[get<0>(indexed_list[i])][word_i];
			else result += orig_lines[get<0>(indexed_list[i])][word_i];
		}

		get<3>(indexed_list[i]) = result;
	}
}

void Indexator::split_everything(vector<string>& init_lines, bool is_orig)
{
	string element;
	vector<string> current_line;

	for (int i = 0; i < number; ++i) {
		current_line.clear();
		element = "";

		for (char symb : init_lines[i]) {
			if (symb != ' ') element += symb;
			else {
				current_line.push_back(element);
				element = "";
			}
		}

		current_line.push_back(element);
		if (is_orig) orig_lines.push_back(current_line);
		else lines.push_back(current_line);
	}
}

void Indexator::sort_indexes()
{
	tuple<int, int, string, string> temp;

	for (int i = 0; i < indexed_list.size(); ++i) {
		for (int j = 0; j < indexed_list.size() - 1; ++j) {
			if (get<2>(indexed_list[j]).compare(get<2>(indexed_list[j + 1])) > 0) {
				temp = indexed_list[j + 1];
				indexed_list[j + 1] = indexed_list[j];
				indexed_list[j] = temp;
			}
		}
	}
}

void Indexator::lower_all_indexes()
{
	for (int i = 0; i < indexed_list.size(); ++i) { 
		for (int j = 0; j < get<2>(indexed_list[i]).size(); ++j)
			get<2>(indexed_list[i])[j] = tolower(get<2>(indexed_list[i])[j]);
	}
}
