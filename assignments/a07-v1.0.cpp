//*********************************************************
//Author:       Alcantar, Joshua
//Assignment:   Assignment 07
//Date:         05/14/2021
//Description:  
//Input:        No input
//Output:       List of numbers
//Sources:      'a06.cpp starter file' by GD Iyer
//***********************************************************

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

void welcome();
void inputFilename(ifstream inFile, char filename[]);
// bool validateFilename(); ?? combined with inputFilename()
void readFilename();
// void inputState(); // initialize char userState[]
// bool validateState(char userState[]);
// void countIdeology(char ideology[], int count[]);
// void countOrgSize(char organization[], int count[]);
// void printData();

int main() {
// Declare variables
    ifstream inFile;
    char filename[31], userState[3];
    bool validFilename = false;
    bool validState = false;
    int ideologyCount, organizationCount;
    char ideology[1000][31], organization[1000][31];

    welcome();
    inputFilename(inFile, filename[]);

    return 0;
}
void welcome() {
    cout << "Welcome to the Southern Poverty Law Center's US hategroup data.\n";
    cout << "You'll see the most popular hate group ideology in your state";
    cout << endl;
    cout << "and the largest hate group in your state by number of chapters.\n";
}
void inputFilename(ifstream inFile, char filename[]) {
    do {
        cout << "Please input filename for hate group data: ";
        for (int i = 0; i < 31; i++) {
            cin >> filename[i];
        }
        inFile.open(filename);
        if (!inFile.is_open()) {
            cout << "Please enter a valid filename:"
        }
        else {
            cout << filename << " accepted." << endl;
            break;
        }
    } while (!inFile.is_open());
    inFile.close();
}
// bool validateFilename(); // not used
// void readFilename();
// void inputState(); // initialize char userState[]
// bool validateState(char userState[]);
// void countIdeology(char ideology[], int count[]);
// void countOrgSize(char organization[], int count[]);
// void printData();