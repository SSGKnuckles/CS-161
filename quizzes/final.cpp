#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

void print(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void userInput(int& targetValue) {
    cin >> targetValue;
}

void removeSmallerThanTarget(int userEntry, int array[], int& arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (array[i] < userEntry) {
            for (int j = i; j < arraySize; j++) {
                array[j] = array[j + 1];
            }
            arraySize--;
            i--;
        
        }
    }
}

int main() {
    int count = 10;
    int arrayNum[20] = {1,3,5,6,8,9,10,11,12,14};

    int target = 0; // user defined taret value

    userInput(target);
    print(arrayNum, count);
    removeSmallerThanTarget(target, arrayNum, count);
    print(arrayNum, count);

    return 0;
}