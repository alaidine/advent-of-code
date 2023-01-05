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

int find_result(string input) {
	int current_floor = 0;
	int position = 0;

	for (char c : input) {
		if (current_floor == -1) {
			return position;
		}
		else if (c == '(') {
			current_floor++;
			position++;
		} else if (c == ')') {
			current_floor--;
			position++;
		}
	}

	return current_floor;
}

int main (int argc, char *argv[])
{
	string input_file = read_file("../input.txt");
	int result = find_result(input_file);

	cout << result << endl;
	
	return 0;
}
