#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "md5.h"

int main() {
  for (int i = 0; i < 1000000; i++) {
    std::stringstream ss;
    std::string str;

    ss << i;
    ss >> str;

    std::string input = "bgvyzdsv" + str;

    if (md5(input).substr(0, 5) == "00000") {
      std::cout << md5(input) << std::endl;
      std::cout << "the answer is: " << i << std::endl;
    }
  }


  return 0;
}
