//*********************************************************
//Author:       Alcantar, Joshua
//Assignment:   Assignment 08
//Date:         06/03/2021
//Description:  Search a table for baby names [1880-1988]
//Input:        User specifies year of interest
//Output:       Greeting, list of restaurants, search results
//Sources:      
//***********************************************************

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <array>
#include <iomanip>


// // struct and prototypes
// #include "Restaurant.h"
// #include "Restaurant.cpp"

using namespace std;

struct restaurant {
    char restaurantName[101];        
    char foodType[101];
    double rating;
};

ifstream inFile;

// Related functions
bool openFile(ifstream& inFile, char filename[]);
void inFileLen(ifstream& inFile, int& fileLength);
void setValues(ifstream& inFile, restaurant database[], int& fileLength);
void welcome();
void menu();
bool readMenuSelect(char& userEntry);
void printValues(restaurant database[], int& fileLength);
void searchValues(char searchString[], restaurant database[], int& filelength);

int main() {
    int debug = 0;
    char menuSelect, searchString[51];
    // Build local restaurant database
    char filename[51] = "restaurants.txt";
    if (!openFile(inFile, filename)) {
        cout << "Failed to open data file, exiting." << endl;
        return 0;
    }
    int fileLength = 0; 
    inFileLen(inFile, fileLength);
    restaurant database[fileLength];
    setValues(inFile, database, fileLength);

    // Start UX    
    welcome();

    while (tolower(menuSelect) != 'q') {
        menu();
        while (!readMenuSelect(menuSelect)) {
            cout << "**Invalid entry**" << endl;
        }
        switch (tolower(menuSelect)) {
            case 'p':
                printValues(database, fileLength);
                break;

            case 's':
                searchValues(searchString, database, fileLength);
                break;

            default:
                break;
        }

    }

    return 0;
}

bool openFile(ifstream& inFile, char filename[]) {
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << filename << " failed to open." << endl;
        return false;
    }
    return true;
}

void inFileLen(ifstream& inFile, int& fileLength) {
    while (!inFile.eof()) {
        inFile.ignore(100, '\n');
        fileLength++;
    }
// Rewinds the file back to the beginning
	inFile.clear();
	inFile.seekg(0);
}

// Reads data from file and stores local database in struct
void setValues(ifstream& inFile, restaurant database[], int& fileLength) {
    for (int i = 0; i < fileLength; i++) {
        inFile >> database[i].restaurantName >> database[i].foodType >> database[i].rating;
    }
    inFile.close();
}

void welcome() {
    cout << "Welcome to my Restaurant Database" << endl;
    cout << "Pick from one of the following options:" << endl;
}

void menu() {
    cout << "   (p) Print the restaurant list" << endl;
    cout << "   (s) Search the restaurant list by name" << endl;
    cout << "   (q) Quit" << endl;
}

bool readMenuSelect(char& userEntry) {
    char acceptedInput[7] = "pPsSqQ";
    cout << "Enter an option: ";
    cin >> userEntry;
    cin.clear();
    cout << endl;
    for (int i = 0; i < strlen(acceptedInput); i++) {
        // if (strcmp(acceptedInput[i], userEntry)) { 
        if (acceptedInput[i] == userEntry) {
            return true;
        }
    }
    return false;
}

void printValues(restaurant database[], int& fileLength) {
    cout << fixed << setprecision(2);
    cout << setw(25) << left << "Restaurant Name";
    cout << setw(25) << left << "Food Type";
    cout << setw(25) << left << "Rating" << "\n" << endl;
    for (int i = 0; i < fileLength - 1; i++) {
        cout << setw(25) << left << database[i].restaurantName;
        cout << setw(25) << left << database[i].foodType;
        cout << setw(25) << left << database[i].rating << endl;
    }
    cout << "\n";
}

void searchValues(char searchString[], restaurant database[], int& filelength) {
    bool match = false;
    cout << "Input restaurant name to search for: " << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin.getline(searchString, 100, '\n');
    for (int i = 0; i < strlen(searchString); i++) {
        if (searchString[i] == ' ') {
            searchString[i] = '_';
        }
    }
    for (int row = 0; row < filelength; row++) {
        if (stristr(searchString, database[row].restaurantName) != nullptr) {
            match = true;
            cout << setw(25) << left << database[row].restaurantName;
            cout << setw(25) << left << database[row].foodType;
            cout << setw(25) << left << database[row].rating << endl;
        }
            
            // searchString[0] == database[row].restaurantName[index]) {
            // if (strcmp(searchString, database[row].restaurantName.substr(index, strlen(searchString) - 1) == 0) {
    }
    if (!match)
        cout << "No matches found for: " << searchString << endl;
}