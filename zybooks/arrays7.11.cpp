// When analyzing data sets, such as data for human heights or for human weights, a common step is to adjust the data. This can be done by normalizing to values between 0 and 1, or throwing away outliers.

// For this program, adjust the values by subtracting the smallest value from all the values. The input begins with an integer indicating the number of integers that follow. Assume that the list will always contain less than 20 integers.

// Ex: If the input is:

// 5 30 50 10 70 65
// the output is:

// 20 40 0 60 55
// The 5 indicates that there are five values in the list, namely 30, 50, 10, 70, and 65. 10 is the smallest value in the list, so is subtracted from each value in the list.

// For coding simplicity, follow every output value by a space, including the last one.

#include <iostream>
using namespace std;

int main(void) {
    int listSize = 0;

    cin >> listSize;
    int list[listSize];
    for (int i = 0; i < listSize; i++) {
        cin >> list[i];
    }
    int minVal = list[0];
            
    for (int i = 0; i < listSize; i++) {
        if (minVal > list[i])
            minVal = list[i];
    }
    for (int i = 0; i < listSize; i++) {
        cout << list[i] - minVal << " ";
    }
    cout << endl;
   return 0;
}