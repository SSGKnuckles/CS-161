#ifndef RESTAURANT_H
#define RESTAURANT_H

struct restaurant {
    char restaurantName[101];        
    char foodType[101];
    double rating;
}

ifstream inFile;

// Related functions
void setValues(restaurant& listing, char newName[], char newFood[], double newRating);

void printValues(restaurant& listing);

void openFile(ifstream& inFile, char filename[]);

#endif