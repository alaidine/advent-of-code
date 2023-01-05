#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find_numbers(string input) {
  vector<int> numbers;

  int start = 0;
  int length = 0;
  int number_of_x = 0;

  for (unsigned long i = 0; i < input.length(); i++) {
    length++;
    if (input[i] != 'x') continue;

    number_of_x++;
    numbers.push_back(stoi(input.substr(start, length-1)));
    if (number_of_x == 2) numbers.push_back(stoi(input.substr(i+1, input.length())));
    start = length;
    length = 0;
  }

  return numbers;
}

int extra_paper_needed(vector<int> input) {
  int length = input[0];
  int width = input[1];
  int height = input[2];

  vector<int> sides = {length*width, width*height, height*length};
  auto smallest_side = min_element(sides.begin(), sides.end());

  int output = *smallest_side;

  // figure out the area of the smallest side and add it to the output


  return output;
}

int wrapping_paper_needed(vector<int> input) {
  int length = input[0];
  int width = input[1];
  int height = input[2];

  int wrapping_paper;
  int output;

  wrapping_paper = 2*length*width + 2*width*height + 2*height*length;

  output = wrapping_paper;

  return output;
}

int find_result(string input) {
  ifstream file(input);
  string line;
  int result;

  result = 0;
  while (getline(file, line)) {
    result += wrapping_paper_needed(find_numbers(line));
    result += extra_paper_needed(find_numbers(line));
  }

  return result;
}

int ribbon_needed(string input) {
  ifstream file(input);
  string line;
  int output;

  output = 0;
  while(getline(file, line)) {
    vector<int> i = find_numbers(line);

    int length = i[0];
    int width = i[1];
    int height = i[2];

    vector<int> perimeters = {2*(length+width), 2*(width+height), 2*(height+length)};
    auto smallest_perimeter = min_element(perimeters.begin(), perimeters.end());
    int cubic_volume = length*width*height;

    output += *smallest_perimeter;
    output += cubic_volume;
  }

  return output;
}

int main() {
  int result = find_result("./input.txt");
  int ribbon = ribbon_needed("./input.txt");

  cout << "the total amount of wrapping paper needed is: " << result << " squared feet." << endl;
  cout << "the total amount of ribbon needed is equal to: " << ribbon << " feet" << endl;



  return 0;
}
