#include <iostream>
#include <string>
#include <fstream>
#include <md5.h>

using namespace std;

int main() {
  string input = "bgvyzdsv";

  for (int i = 0; i < 1000000; i++) {
    string md5_hash = md5(input + itoa(i));

    if (md5_hash.substr(0, 5) == "00000") {
      std::cout << "the answer is: " << md5_hash << std::endl;
      break;
    }
  }

  return 0;
}
