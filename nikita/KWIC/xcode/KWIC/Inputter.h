#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Inputter
{
public:
    static int get_number_of_lines();
    static vector<string> get_lines(int& number);

private:
    static void fill_with_example(int& number, vector<string>& lines);
};
