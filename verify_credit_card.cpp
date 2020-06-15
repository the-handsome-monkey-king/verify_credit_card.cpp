/******************
*
*  verify_credit_card.cpp
*
*  @author Ryan Morehouse
*  @license MIT
*
*  Verify a credit card number using the Luhn Algorithm.
*  This will not test whether a credit card is valid or not, but
*  will test whether the input number adheres to accepted checksum
*  creation against non-malicious mistakes.
*
********************/

#include <iostream>
#include <string>
#include <vector>

void error_msg() {
  std::cout << "Usage: verify_credit_card.o [n]\n";
  std::cout << "[n] = credit card number without spaces\n";
}

bool is_cc_valid(std::vector<int> *digits) {
  // traverse digits in reverse
  int sum = 0;
  for(int i = digits->size() -1; i >= 0; i--) {
    int j = (*digits)[i];
    if (i % 2 != 0) {
      j *= 2;
      if (j > 9)
        j -= 9;
    }
    sum += j;
  }

  if (sum % 10 == 0)
    return true;
  return false;
}


int main(int argc, char *argv[]) {
  // user input
  int n;

  // verify arg exists
  if (argc < 2) {
    error_msg();
    return 1;
  }

  // get digits of cc number
  std::vector<int> digits;
  std::string cc = argv[1];
  for(std::string::iterator it = cc.begin(); it != cc.end(); it++) {
    if(isdigit(*it)) {
      int j = *it;
      digits.push_back(j);
    }
  }

  if (is_cc_valid(&digits))
    std::cout << cc << " is valid against Luhn's Algorithm.\n";
  else
    std::cout << cc << " is not valid against Luhn's Algorithm.\n";
  
  return 0;
}
