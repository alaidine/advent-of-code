#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream file("./input.txt");
    string line;

    while(getline(file, line)) {
        cout << line << endl;
    }

    return 0;
}
