#include <iostream>

using namespace std;

int main() {
// vars for main
  int userNum1 = 0, userNum2 = 0;
  cout << "Please enter two integers, smaller then larger, separated by space" << endl;
  cout << "I'll tell you all the numbers in the range between." << endl;
  cin >> userNum1 >> userNum2;
  for (int i = userNum1; i <= userNum2; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      cout << "FizzBuzz" << " ";
    }
    else if (i % 3 == 0) {
      cout << "Fizz" << " ";
    }
    else if (i % 5 == 0) {
      cout << "Buzz" << " ";
    }
    else {
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}