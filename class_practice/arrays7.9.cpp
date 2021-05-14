/*
Write a program that reads a list of integers, 
and outputs those integers in reverse. 
The input begins with an integer indicating 
the number of integers that follow. For coding 
simplicity, follow each output integer by a space, 
including the last one. Assume that the list will 
always contain less than 20 integers.

Ex: If the input is:

5 2 4 6 8 10
the output is:

10 8 6 4 2
To achieve the above, first read the integers into an array. 
Then output the array in reverse.
*/

#include <iostream>
using namespace std;

int main() {
   const int NUM_ELEMENTS = 20;         // Number of input integers
   int userVals[NUM_ELEMENTS];          // Array to hold the user's input integers
   int count = 0;
    cin >> count;
   for (int j = 0; j < count; j++) {
      cin >> userVals[j];
   }

   for (int i = count - 1; i >= 0; i--) {
      cout << userVals[i] << " ";
   }
   cout << endl;

   return 0;
}