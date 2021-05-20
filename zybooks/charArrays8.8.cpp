// Write a program that removes all spaces from the given input. You may assume
// that the input string will not exceed 50 characters.

// Ex: If the input is:

// Hello my name is John.
// the output is:

// HellomynameisJohn.
// Your program must define and call the following function. userString is the
// user specified string. The function assigns userStringNoSpaces with the user
// specified string without spaces.
// void RemoveSpaces(char userString[], char userStringNoSpaces[])

// Note: This is a lab based on a previous chapter that now requires the use of a function.

#include <iostream>
#include <cstring>
using namespace std;

void RemoveSpaces(char userString[], char userStringNoSpaces[]);

int main() {
    char userString[50];
    char userStringNoSpaces[50];
    cin.getline(userString, 50);
    RemoveSpaces(userString, userStringNoSpaces);
    cout << userStringNoSpaces << endl;

   return 0;
}

void RemoveSpaces(char userString[], char userStringNoSpaces[]) {
    for (int i = 0, j = 0; i <= strlen(userString); i++) {
        if (userString[i] != ' ') {
            userStringNoSpaces[j] = userString[i];
            j++;
        }
    }
}