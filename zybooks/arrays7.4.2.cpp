// Write a loop that sets newScores to oldScores shifted once left, with element 0 copied to the end. Ex: If oldScores = {10, 20, 30, 40}, then newScores = {20, 30, 40, 10}.

// Note: These activities may test code with different test values. This activity will perform two tests, both with a 4-element array (int oldScores[4]). See "How to Use zyBooks".

// Also note: If the submitted code tries to access an invalid array element, such as newScores[9] for a 4-element array, the test may generate strange results. Or the test may crash and report "Program end never reached", in which case the system doesn't print the test case that caused the reported message.

#include <iostream>
using namespace std;

int main() {
   const int SCORES_SIZE = 4;
   int oldScores[SCORES_SIZE];
   int newScores[SCORES_SIZE];
   int i;

   for (i = 0; i < SCORES_SIZE; ++i) {
      cin >> oldScores[i];
   }

   for (i = 0; i < SCORES_SIZE - 1; i++) {
       newScores[i] = oldScores[i + 1];
   }
   newScores[SCORES_SIZE - 1] = oldScores[0];

   for (i = 0; i < SCORES_SIZE; ++i) {
      cout << newScores[i] << " ";
   }
   cout << endl;

   return 0;
}