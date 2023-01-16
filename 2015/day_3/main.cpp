#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>

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
  return {current_position[0]+1, current_position[1]};
}

vector<int> update_position(vector<int> current_position, char direction) {
  vector<int> new_position;

  switch (direction) {
    case '^':
      return go_north(current_position);
      break;
    case 'v':
      return go_south(current_position);
      break;
    case '<':
      return go_west(current_position);
      break;
    case '>':
      return go_east(current_position);
      break;
    default:
      return current_position;
  }

  return current_position;
}

int read_file(string input) {
  ifstream file(input);
  string line;
  string file_read;


  vector<int> current_position = {0, 0};
  set<vector<int>> history_of_positions = {
    {0, 0}
  };

  while (getline(file, line)) {
    for (char c : line) {
      current_position = update_position(current_position, c);
      history_of_positions.insert(current_position);
    }
  }

  return history_of_positions.size();
}

int main() {
  int input = read_file("./input.txt");

  cout << "the number of houses visited by santa is equal to: " << input << endl;

  return 0;
}
