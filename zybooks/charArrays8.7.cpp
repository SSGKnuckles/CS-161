// Write a program that reads a list of words. Then, the program outputs those words and their frequencies. The input begins with an integer indicating the number of words that follow. Assume that the list will always contain less than 20 words. Each word will always contain less than 10 characters and no spaces.

// Ex: If the input is:

// 5 hey hi Mark hi mark
// Then, the output is:

// hey 1
// hi 2
// Mark 1
// hi 2
// mark 1
// Hint: Use two arrays, one array for the strings and one array for the frequencies.

#include <iostream>
#include <cstring>
using namespace std;

int main() {
   
   int words;
   cin >> words;
   char input[words][10];
   int freq[words];
   int count = 0;

   for (int i = 0; i < words; i++) {
      cin >> input[i];
   }
   for (int i = 0; i < words; i++) {
      count = 0;
      for (int j = 0; j < words; j++) {
         if (strcmp(input[i], input[j]) == 0)
            count++;
      }
      freq[i] = count;
   }
   for (int i = 0; i < words; i++) {
      cout << input[i] << " " << freq[i] << endl;
   }

   return 0;
}
