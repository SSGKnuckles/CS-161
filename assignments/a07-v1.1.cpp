//*********************************************************
//Author:       Alcantar, Joshua
//Assignment:   Assignment 07
//Date:         05/28/2021
//Description:  Search a table for baby names [1880-1988]
//Input:        User specifies year of interest
//Output:       Most popular girl and boy names for the year
//Sources:      kaggle.com "nationalnames.csv"
//***********************************************************

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <array>
#include <iomanip>

using namespace std;

bool openFile(ifstream& inFile, char fileName[]);
void readUserSearchArgs(int& userYear);
void findFemaleName(int& userYear, ifstream& inFile, char femaleName[], int& femaleCount);
void findMaleName(int& userYear, ifstream& inFile, char maleName[], int& maleCount);
void printSearchResults(int userYear, char femaleName[], char maleName[], int femaleCount, int maleCount);

int main() {
    ifstream inFile;
    char filename[200] = "NationalNames.csv";
    int userYear, femaleCount, maleCount;
    char femaleName[41], maleName[41];
    

    if (!openFile(inFile, filename)){ 
        cout << "Failed to open file" << endl;
        return 0;
    }
    readUserSearchArgs(userYear);
    findFemaleName(userYear, inFile, femaleName, femaleCount);
    //rewinds the file back to the beginning.
	inFile.clear();
	inFile.seekg(0);
    findMaleName(userYear, inFile, maleName, maleCount);
    inFile.close();
    printSearchResults(userYear, femaleName, maleName, femaleCount, maleCount);

    return 0;
}
// Passed unit testing 05/28/2021 by Joshua Alcantar
bool openFile(ifstream& inFile, char fileName[]) {
	inFile.open(fileName);
	if (!inFile.is_open())
	{
		return false;
	}
	return true;
}

// Passed unit testing 05/28/2021 by Joshua Alcantar 
void readUserSearchArgs(int& userYear) {
    cout << "Enter the year of interest to find the most" << endl;
    cout << "popular names for boys and girls in the US that year" << endl;
    cout << "Enter year (1880-1988): ";
    cin >> userYear;
    while (!(userYear >= 1880) && !(userYear <= 1988)) {
        cout << "Invalid input, please try again." << endl;
        cout << "Enter year (1880-1988): ";
        cin >> userYear; 
    }
    cout << "Searching for most popular names in year: " << userYear << endl;
}

void findFemaleName(int& userYear, ifstream& inFile, char femaleName[], int& femaleCount) {
    // Read inFile variables into these
    char name[41], gender;
    int row, year, count;
    // Ignore table header
    inFile.ignore(100, '\n');
    // Find first matching row
    while (!inFile.eof()) {
        inFile >> row >> name >> year >> gender >> count;
        if (year == userYear && gender == 'F') { 
            femaleCount = count;
            strcpy(femaleName, name);
            break;
        }
    }
    while (!inFile.eof()) {
        inFile >> row >> name >> year >> gender >> count;
        if (userYear == year && gender == 'F') {
            if (femaleCount < count) {
                femaleCount = count;
                strcpy(femaleName, name);
            }
        }
    }
}

void findMaleName(int& userYear, ifstream& inFile, char maleName[], int& maleCount) {
    // Read inFile variables into these
    int row, year, count;
    char name[41], gender;
    int step = 0; 
    // Ignore table header
    inFile.ignore(200, '\n');
    // Find first matching row
    while (!inFile.eof()) {
        inFile >> row >> name >> year >> gender >> count;
        if (year == userYear && gender == 'M') { 
            maleCount = count;
            strcpy(maleName, name);
            break;
        }
    }
    maleCount = count;
    strcpy(maleName, name);
    while (!inFile.eof()) {
        inFile >> row >> name >> year >> gender >> count;
        if (userYear == year && gender == 'M') {
            if (maleCount < count) {
                maleCount = count;
                strcpy(maleName, name);
            }
        }
    }
}
void printSearchResults(int userYear, char femaleName[], char maleName[], int femaleCount, int maleCount) {
    cout << endl;
    cout << "The most popular female name in " << userYear << " was: " << endl;
    cout << femaleName << " with " << femaleCount << " female babies.\n";
    cout << endl;
    cout << "The most popular male name in " << userYear << " was: " << endl;
    cout << maleName << " with " << maleCount << " male babies." << endl;
}
