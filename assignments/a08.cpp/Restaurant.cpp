#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

#include "Restaurant.h"

using namespace std;

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
void setValues(ifstream& inFile, Restaurant database[], int& fileLength) {
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
    cout << "\n";
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

void printValues(Restaurant database[], int& fileLength) {
    cout << fixed << setprecision(1);
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

void searchValues(char searchString[], Restaurant database[], int& filelength) {
    bool match = false;
    cout << "Input restaurant name to search for: ";
    cin.clear();
    cin.ignore(100, '\n');
    cin.getline(searchString, 100, '\n');
    for (int i = 0; i < strlen(searchString); i++) {
        if (searchString[i] == ' ') {
            searchString[i] = '_';
        }
    }
    for (int row = 0; row < filelength; row++) {
        if (strstr(database[row].restaurantName, searchString) != nullptr) {
            match = true;
            cout << "\n";
            cout << setw(25) << left << database[row].restaurantName;
            cout << setw(25) << left << database[row].foodType;
            cout << setw(25) << left << database[row].rating << endl;
        }
    }
    if (!match)
        cout << "\nNo matches found for: " << searchString << "\n";
}