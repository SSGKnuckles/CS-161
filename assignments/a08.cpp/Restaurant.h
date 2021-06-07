#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <array>
#include <iomanip>

using namespace std;

struct Restaurant {
    char restaurantName[101];        
    char foodType[101];
    double rating;
};

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