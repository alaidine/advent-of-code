#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string read_file(string input) {
	stringstream buffer;
	ifstream file(input);

	if (file.is_open()) {
		buffer << file.rdbuf();
		file.close();
	} else {
		cout << "Unable to open file" << endl;
	}

	string contents = buffer.str();

	return contents;
}

int find_right_floor(string input) {
	int current_floor = 0;

	for (char c : input) {
		if (c == '(') {
			current_floor++;
		} else if (c == ')') {
			current_floor--;
		}
	}

	return current_floor;
}

int main (int argc, char *argv[])
{
	string input_file = read_file("../input.txt");
	int right_floor = find_right_floor(input_file);

	cout << right_floor << endl;
	
	return 0;
}
