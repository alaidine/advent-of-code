#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// first property: return true if the input has at least three vowels
bool first_property(string input) {
	int vowel_count = 0;
	string vowels = "aeiou";

	for (int i = 0; i < input.length(); i++) {
		if (vowels.find(input[i]) != string::npos) vowel_count++;
	}

	if (vowel_count < 3) return false;

	return true
}

// second property: return true if the input contains at least on letter that appears twice in a row
bool second_property() {
	return true;
}

// second property: return true if the input doesn't contain the strings ab, sd, pq or sx
bool third_property() {
	return true;
}

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
