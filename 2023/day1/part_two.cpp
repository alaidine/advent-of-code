#include "day1.hpp"

void part_two()
{
    string x;
    unordered_map<string, int> map;
    vector<string> digits_in_letters = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<int> digits_in_line;
    vector<string>::iterator it;
    int output = 0;

    map["zero"] = 0;
    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;
    map["four"] = 4;
    map["five"] = 5;
    map["six"] = 6;
    map["seven"] = 7;
    map["eight"] = 8;
    map["nine"] = 9;
    freopen("input", "r", stdin);
    while (cin >> x) {
        digits_in_line.clear();
    }
    cout << "The answer of part two is: " << output << endl;
}
