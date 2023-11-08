#include "Inputter.h"

using namespace std;

int Inputter::get_number_of_lines()
{
    int amount = NULL;
    string input;

    while (!amount) {
        cout << "Print the number of following lines (greater than 0)\nOr print 0 for auto text >> ";
        try {
            getline(cin, input);
            amount = stoi(input);
        }
        catch (exception ex) { cout << "Error message >> " << ex.what(); }

        if (amount == 0) break;
    }

    return amount;
}

vector<string> Inputter::get_lines(int& number)
{
    string current_line = "";
    vector<string> lines;

    if (number != 0) {
        for (int i = 0; i < number; ++i) {
            cout << ">> ";
            getline(cin, current_line);
            lines.push_back(current_line);
        }
    }
    else {
        fill_with_example(number, lines);
    }

    return lines;
}

void Inputter::fill_with_example(int& number, vector<string>& lines) {
    number = 3;

    lines.push_back("This work was done by some genius!");
    lines.push_back("KWIC is an acronym for Key Word In Context, the most common format for concordance lines");
    lines.push_back("the free encyclopedia");
}
