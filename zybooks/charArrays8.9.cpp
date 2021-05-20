// A palindrome is a word or a phrase that is the same when read both forward 
// and backward. Examples are: "bob," "sees," or "never odd or even" (ignoring 
// spaces). Write a program whose input is a word or phrase, and that outputs 
// whether the input is a palindrome. You may assume that the input string will 
// not exceed 50 characters.

// Ex: If the input is bob, the output is:

// bob is a palindrome
// Ex: If the input is bobby, the output is:

// bobby is not a palindrome
// Hint: Start by just handling single-word input, and submit for grading. Once
// passing single-word test cases, extend the program to handle phrases. If the
// input is a phrase, remove or ignore spaces.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int i = 0;
    bool palindrome = false;
    char userString[50];
    cin.getline(userString, 50);
    for (i = 0; i <= strlen(userString) / 2; i++) {
        if (userString[i] == userString[strlen(userString) - i]) {
            palindrome = true;
        }
        else {
            palindrome = false;
            break;
        }
    }
    if (palindrome) 
        cout << userString << " is a palindrome" << endl;
    else
        cout << userString << " is not a palindrome" << endl;

   return 0;
}
