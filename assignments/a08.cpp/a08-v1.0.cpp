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
    ifstream inFile;
    char filename[51] = "restaurants.txt";
    openFile(inFile, filename);
    int fileLength = fileLength(inFile, fileLength);
    restaurant database[fileLength];
    



    return 0;
}