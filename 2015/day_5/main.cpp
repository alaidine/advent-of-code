#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_string_nice(string input) {
	// check if a string is nice

	return true;
}

void read_file(string input) {
	fstream file(input);
	int ok_strings_counter = 0;

	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			// the new line character is not included in the getline() function
			cout << line << endl;

			if (is_string_nice(line)) ok_strings_counter++; 
		}
	}

	cout << endl << "number of ok strings: " << ok_strings_counter << endl;
}

int main() {
	read_file("input.txt");
}
