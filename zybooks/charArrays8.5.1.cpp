// Find the maximum value and minimum value in milesTracker. 
// Assign the maximum value to maxMiles, and the minimum value to minMiles. 
// Sample output for the given program:
// Min miles: -10
// Max miles: 40

#include <iostream>
using namespace std;

int main() {
   const int NUM_ROWS = 2;
   const int NUM_COLS = 2;
   int milesTracker[NUM_ROWS][NUM_COLS];
   int i;
   int j;
   int maxMiles = 0; // Assign with first element in milesTracker before loop
   int minMiles = 0; // Assign with first element in milesTracker before loop
   int value;

   for (i = 0; i < NUM_ROWS; i++){
      for (j = 0; j < NUM_COLS; j++){
         cin >> value;
         milesTracker[i][j] = value;
      }
   }
    minMiles = milesTracker[0][0];
    maxMiles = milesTracker[0][0];
    for (i = 0; i < NUM_ROWS; i++){
      for (j = 0; j < NUM_COLS; j++){
         if (minMiles > milesTracker[i][j])
            minMiles = milesTracker[i][j];
         if (maxMiles < milesTracker[i][j])
            maxMiles = milesTracker[i][j];
      }
    }

   cout << "Min miles: " << minMiles << endl;
   cout << "Max miles: " << maxMiles << endl;

   return 0;
}