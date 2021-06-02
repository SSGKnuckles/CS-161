#ifndef RESTAURANT_H
#define RESTAURANT_H

struct restaurant {
    char restaurantName[101];        
    char foodType[101];
    double rating;
}

// Related functions
void welcome();

bool readMenuSelect(char& userEntry);

void setValues(restaurant& listing, char newName[], char newFood[], double newRating);

void printValues(Restaurant& listing, int& fileLength);

void openFile(ifstream& inFile, char filename[]);

int inFileLen(ifstream& inFile, int& fileLength);

void searchValues(char searchString[], restaurant& database, int& filelength);
    



#endif