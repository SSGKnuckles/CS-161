#include<iostream>
#include<iomanip>
#include<cstring>

#include "Restaurant.h"
using namespace std;

int main() {
   Restaurant listing1;
   char newName[40];
   char newFood[30];
   double newRating;

   cout << "Enter the Restaurant Name:";
   cin.getline(newName, 101);
   cout << endl;
   cout << "Enter the Food Type:";
   cin.getline(newFood, 101);
   cout << endl;
   cout << "Enter the Restaurant Rating:";
   cin >> newRating;
   cout << endl;

   SetValues(listing1, newName, newFood, newRating);
   PrintValues(listing1);
   
   return 0;
}