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

int solution_first_part(string input) {
  ifstream file(input);
  string line;


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

int solution_second_part(string input) {
  ifstream file(input);
  string line;

  vector<int> santas_current_position = {0, 0};
  vector<int> robo_current_position = {0, 0};
  set<vector<int>> history_of_positions = {
    {0, 0}
  };
  while(getline(file, line)) {
    for (long unsigned int i = 1; i < line.size(); i = i + 2) {
      santas_current_position = update_position(santas_current_position, line[i-1]);
      robo_current_position = update_position(robo_current_position, line[i]);

      history_of_positions.insert(santas_current_position);
      history_of_positions.insert(robo_current_position);
    }
  }

  return history_of_positions.size();
}

int main() {
  int first_part = solution_first_part("./input.txt");
  int second_part = solution_second_part("./input.txt");

  cout << "the number of houses visited by santa is equal to: " << first_part << endl;
  cout << "the number of houses visited by santa and robo santa is equal to: " << second_part << endl;

  return 0;
}
