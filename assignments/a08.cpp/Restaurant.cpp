#include<iostream>
#include<cstring>
#include <iomanip>
#include "Restaurant.h"
using namespace std;

// Sets restaurantName = newName, foodType = newFood, rating = newRating for aRest
void setValues(Restaurant& listing, char newName[], char newFood[], double newRating)
{
strcpy(listing.restaurantName, newName);
strcpy(listing.foodType, newFood);
listing.rating = newRating;
};

void printValues(Restaurant& listing) {
cout << fixed << setprecision(2);
cout << "Restaurant Name: " << listing.restaurantName << endl;
cout << "Food Type: " << listing.foodType << endl;
cout << "Restaurant Rating: " << listing.rating << endl;
}

bool openFile(ifstream& inFile, char filename[]) {
    inFile.open(filename);
    if (!inFile.is_open()) {
        cout << filename << " failed to open." << endl;
        return false;
    }
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