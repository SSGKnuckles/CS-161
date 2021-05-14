// Add each element in origList with the corresponding value in offsetAmount. Print each sum followed by a comma (no spaces).

// Ex: If origList = {4, 5, 10, 12} and offsetAmount = {2, 4, 7, 3}, print:
// 6,9,17,15,
#include <iostream>
#include <string.h>
using namespace std;

int main() {
   const int NUM_VALS = 4;
   int origList[NUM_VALS];
   int offsetAmount[NUM_VALS];
   int i;

   cin >> origList[0];
   cin >> origList[1];
   cin >> origList[2];
   cin >> origList[3];

   cin >> offsetAmount[0];
   cin >> offsetAmount[1];
   cin >> offsetAmount[2];
   cin >> offsetAmount[3];

   for (int i = 0; i < NUM_VALS; i++) {
       cout << origList[i] + offsetAmount[i] << ",";
   }

   cout << endl;

   return 0;
}