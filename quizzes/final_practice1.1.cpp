// Create an array with a capacity of 20 elements.  Fill the array with 10 random numbers.  You can do this however you want.  DO NOT create a new array.  In this array try to the following or any variations of the following:
// Remove all even values in the array
// Remove the first and last values in the array
// Insert a new random number after every existing element in the array and make sure you are not going over the capacity.

// 2) Now create a char array with a line of text.  This should include spaces.  Try to do the following in this array:
// Remove all vowels in the array.  Don’t change anything else in the array.
// Replace all vowels with the consonant right after that vowel in the alphabet.  An example below:
// Brown fox jumps over the dog.  
// Brpwn fpx jvmps pvfr thf dpg.

#include <cstring>
#include <iostream>
#include <cmath>

void removeEvens(int array[], int& count);

using namespace std;

int main() {
    int count = 10;
    int arrayNum[20] = {1,3,5,6,8,9,10,11,12,14};
    int TESTNUM[10] = {1,3,5,9,11};
    char arrayChar[50] = "this is a test of the emergency broadcast system";

    removeEvens(arrayNum, count);

    for (int i = 0; i < count; i++) {
        cout << arrayNum[i] << ", ";
    }
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << TESTNUM[i] << ", ";
    }
    cout << endl;
}
void removeEvens(int array[], int& count) {
    
    for (int i = 0; i < count; i++) {    //i = 0, i = 1....i = 6, 
        if (array[i] % 2 == 0) {
            for (int j = i; j < count - 1; j++) { //shift
                array[j] = array[j + 1];
            }    
            count--;
            i--;
        }
    }
    if (array[count - 1] % 2 == 0) {
        count--;
    }
}