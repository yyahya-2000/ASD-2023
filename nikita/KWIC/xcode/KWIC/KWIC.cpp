#include "KWIC.h"

using namespace std;

int main()
{
    srand(time(0));

    int amount = Inputter::get_number_of_lines();
    vector<string> lines = Inputter::get_lines(amount);
        

    if (!lines.empty()) {
        Indexator indx = Indexator(amount, lines);
        
        cout << indx.print_result();
    }
}
