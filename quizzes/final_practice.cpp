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

using namespace std;

const int SIZE = 20;

int main() {

    int count = 0;
    int array1[SIZE];

    int array2[SIZE] {1,3,4,7,8,9,10,12,13,15};
    // for (int i = 0; i < 10; i++) {
    //     array1[i] = rand();
    //     count++;
    // }
    char arrayA[50] = "this is a test of the emergency broadcast system";

    return 0;
}
void removeEvens(char array2[], int count) {
    for (int i = 0, j = i + 1; i < count; i++) {
        if (isEven(array2[i])) {

            if (!isEven(array2[j])){
                array2[i] = array2[j];
            } else {
                
                while (isEven(array2[j] && j < SIZE)) {
                    j++;
                }
            }

        }

    }
}
bool isEven(int num) {
    if (num % 2 == 0) {
        return true;
    }
    return false;
}   
