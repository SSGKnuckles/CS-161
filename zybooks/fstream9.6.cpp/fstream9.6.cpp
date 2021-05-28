// 9.6 Lab: All-consuming (File Input)
// Develop a program that estimates your annual consumption of a commodity based on how much you consume a normal weekday and a normal weekend day. You are given a file called consuming.txt with the input data in the below format.

// Name-of-item quantity-consumed-weekday quantity-consumed-weekendDay

// Assumptions: The term week denotes 5 weekdays and 2 weekend days. A year has 52 weeks (yes, we know a real year is longer, but we will ignore that in this program). User supplied numbers are integers.

// Requirements: Open the file and check to see if the file opened. Read data from the file. The program uses the data from the file to compute and report the estimate of the quantity consumed in a year. Use this formula based on the Assumptions given above: totalNum = (weekdayQty * 5 * 52) + (weekendQty * 2 *52). Use while(!inFS.eof(() to read until there is no more data in the file.

// Then output the data to the screen with the following information: Name-of-item quantity-consumed-weekday quantity-consumed-weekendDay totalNum

// The data in the text file looks like this: You can download the text file to see how it looks.

// paper-napkins 6 0

// pretzels 5 10

// MandMs 10 100

// jellyBeans 10 50

// chocolate 5 25

//This program estimates your annual consumption of a commodity based on how much you consume a normal weekday and a normal weekend day.
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int rows = 0;
    char item[5][20];
    int avgs[5][2];
    int totals[5];
    ifstream inFile;
    inFile.open("C:\\Users\\joshu\\Documents\\PCC Spring 2021\\CS-161\\zybooks\\fstream9.6.cpp\\consuming.txt");
    if (!inFile.is_open()) {
        cout << "Open file failed!" << endl;
        return 1;
    }
// read in the data from file
    while (!inFile.eof()) {
        inFile >> item[rows] >> avgs[rows][0] >> avgs[rows][1];
        rows++;
    }
// calculate annual avgs
    for (int i = 0; i < rows; i ++) {
        totals[i] = (avgs[i][0] * 5 * 52) + (avgs[i][1] * 2 * 52);
        cout << item[i] << " " << avgs[i][0] << " " << avgs[i][1] << " " << totals[i] << endl;
    }  
   
   
   return 0;
}