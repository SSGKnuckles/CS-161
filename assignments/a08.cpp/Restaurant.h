#ifndef RESTAURANT_H
#define RESTAURANT_H
using namespace std;

struct restaurant {
    char restaurantName[101];        
    char foodType[101];
    double rating;
};

// Related functions
bool openFile(ifstream& inFile, char filename[]);
void inFileLen(ifstream& inFile, int& fileLength);
void setValues(restaurant& database, char newName[], char newFood[], double newRating);
void welcome();
void menu();
bool readMenuSelect(char& userEntry);
void printValues(restaurant& database, int& fileLength);
void searchValues(char searchString[], restaurant& database, int& filelength);

#endif