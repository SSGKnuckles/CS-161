//*********************************************************
//Author:       Alcantar, Joshua
//Assignment:   Assignment 08
//Date:         06/03/2021
//Description:  Search a table for baby names [1880-1988]
//Input:        User specifies year of interest
//Output:       Greeting, list of restaurants, search results
//Sources:      
//***********************************************************

#include "Restaurant.h"

int main() {
    ifstream inFile;
    char menuSelect = '\0', searchString[51];
    // Build local restaurant database
    char filename[51] = "restaurants.txt";
    if (!openFile(inFile, filename)) {
        cout << "Failed to open data file, exiting." << endl;
        return 0;
    }
    int fileLength = 0; 
    inFileLen(inFile, fileLength);
    Restaurant database[20];
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