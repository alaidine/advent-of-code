#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<int> go_north(vector<int> current_position) {
  return {current_position[0], current_position[1]+1};
}


vector<int> go_south(vector<int> current_position) {
  return {current_position[0], current_position[1]-1};
}

vector<int> go_west(vector<int> current_position) {
  return {current_position[0]-1, current_position[1]};
}

vector<int> go_east(vector<int> current_position) {
  return {current_position[0]+1, current_position[1]+1};
}

int read_file(string input) {
  ifstream file(input);
  string line;
  string file_read;


  int number_of_houses_visited = 1;
  vector<vector<int>> history_of_positions = {
    {0, 0}
  };
  while (getline(file, line)) {
    for (char c : line) {
      cout << c << endl;
    }
  }

  return number_of_houses_visited;
}


int main() {
  int input = read_file("./input.txt");

  cout << "the number of houses visited by santa is equal to: " << input << endl;

  return 0;
}
