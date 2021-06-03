#include <iostream>
#include <cstring>
#include <iomanip>
#include <istream>

#include "Restaurant.h"

using namespace std;

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

// Reads data from file and stores local database in struct
void setValues(ifstream& inFile, restaurant database[], int& fileLength) {
    int i = 0;
    while (!inFile.eof()) {
        inFile >> database[i].restaurantName >> database[i].foodType >> database[i].rating;
        i++;
    }
    inFile.close();
}

void printValues(restaurant database[], int& fileLength) {
    cout << fixed << setprecision(2);
    for (int i = 0; i < fileLength; i++) {
        cout << "Restaurant Name: " << database[i].restaurantName << endl;
        cout << "Food Type: " << database[i].foodType << endl;
        cout << "Restaurant Rating: " << database[i].rating << endl;
    }
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
    fileLength = 0;
    while (!inFile.eof()) {
        inFile.ignore(100, '\n');
        fileLength++;
    }
// Rewinds the file back to the beginning
	inFile.clear();
	inFile.seekg(0);
}

void searchValues(char searchString[], restaurant database[], int& filelength) {
    bool match = false;
    cout << "\nInput restaurant name to search for: " << endl;
    cin.getline(searchString, 100, '\n');
    for (int i = 0; i < strlen(searchString); i++) {
        if (searchString[i] == ' ') {
            searchString[i] = '_';
        }
    }
    for (int row = 0; row < filelength; row++) {
        if (strstr(searchString, database[row].restaurantName) != NULL) {
            match = true;
            cout << database[row].restaurantName << " " << database[row].foodType << " " << database[row].rating << endl;
        }
            
            // searchString[0] == database[row].restaurantName[index]) {
            // if (strcmp(searchString, database[row].restaurantName.substr(index, strlen(searchString) - 1) == 0) {
    }
    if (!match)
        cout << "No matches found for: " << searchString << endl;
}
