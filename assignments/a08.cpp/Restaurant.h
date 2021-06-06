#ifndef RESTAURANT_H
#define RESTAURANT_H
using namespace std;

struct Restaurant {
    char restaurantName[101];        
    char foodType[101];
    double rating;
};

ifstream inFile;

// Related functions
bool openFile(ifstream& inFile, char filename[]);
void inFileLen(ifstream& inFile, int& fileLength);
void setValues(ifstream& inFile, Restaurant database[], int& fileLength);
void welcome();
void menu();
bool readMenuSelect(char& userEntry);
void printValues(Restaurant database[], int& fileLength);
void searchValues(char searchString[], Restaurant database[], int& filelength);

#endif