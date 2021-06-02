//*********************************************************
//Author:       Alcantar, Joshua
//Assignment:   Assignment 07
//Date:         05/28/2021
//Description:  Search a table for baby names [1880-1988]
//Input:        User specifies year of interest
//Output:       Greeting, ist of restaurants, search results,
//               
//Sources:      
//***********************************************************

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <array>
#include <iomanip>

using namespace std;

int main() {
    char menuSelect, searchString[51];
    // Build local restaurant database
    ifstream inFile;
    char filename[51] = "restaurants.txt";
    if (!openFile(inFile, filename) {
        cout << "Failed to open data file, exiting."
        return 0
    }
    int fileLength = inFileLen(inFile, fileLength);
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
                
                break;

            default:
                break;
        }

    }







    return 0;
}