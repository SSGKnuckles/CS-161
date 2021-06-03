#include<iostream>
#include<cstring>
#include <iomanip>
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
    cout << endl;
    for (int i = 0; i < strlen(acceptedInput)) {
        if (strcmp(acceptedInput[i], userEntry)) { 
        // if (acceptedInput[i] == userEntry) {
            return true;
        }
    }
    return false;
}

// Reads data from file and stores local database in struct
void setValues(ifstream& inFile, restaurant& database[], int& fileLength) {
    while (!inFile.eof()) {
        inFile >> database[i].restaurantName >> database[i].foodType >> database[i].rating;
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

int inFileLen(ifstream& inFile, int& fileLength) {
    fileLength = 0;
    while (!inFile.eof()) {
        inFile.ignore(100, '\n');
        fileLength++;
    }
// Rewinds the file back to the beginning
	inFile.clear();
	inFile.seekg(0);
    return fileLength;
}

void 

void searchValues(char searchString[], restaurant database[], int& filelength) {
    cout << "\nInput restaurant name to search for: " << endl;
    cin.getline(searchString, 100, '\n');
    for (int i = 0; i < strlen(searchString); i++) {
        if (searchString[i] == ' ') {
            searchString[i] = '_';
        }
    }
    for (int row = 0; row < filelength; j++) {
        for (int index = 0; index < strlen(database[row].restaurantName); index++) {
                if (searchString[0] == database[row].restaurantName[index]) {
                    if (strcmp(tolower(searchString), tolower(database[row].restaurantName.substr(index, strlen(searchString)) - 1) == 0) {

                    }
            }
        }
    }
}