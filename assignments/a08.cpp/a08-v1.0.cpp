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

// struct and prototypes
#include "Restaurant.h"
#include "Restaurant.cpp"

using namespace std;

int main() {
    char menuSelect, searchString[51];
    // Build local restaurant database
    ifstream inFile;
    char filename[51] = "restaurants.txt";
    if (!openFile(inFile, filename)) {
        cout << "Failed to open data file, exiting."
        return 0;
    }
    int fileLength; 
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
                searchValues(searchString, inFile, fileLength);
                break;

            default:
                break;
        }

    }







    return 0;
}