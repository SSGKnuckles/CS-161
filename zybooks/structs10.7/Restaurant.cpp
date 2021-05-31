#include<iostream>
#include<cstring>
#include <iomanip>
#include "Restaurant.h"
using namespace std;

// Sets restaurantName = newName, foodType = newFood, rating = newRating for aRest
void SetValues(Restaurant& listing, char newName[], char newFood[], double newRating)
{
strcpy(listing.restaurantName, newName);
strcpy(listing.foodType, newFood);
listing.rating = newRating;
};

void PrintValues(Restaurant& listing) {
cout << fixed << setprecision(2);
cout << "Restaurant Name: " << listing.restaurantName << endl;
cout << "Food Type: " << listing.foodType << endl;
cout << "Restaurant Rating: " << listing.rating << endl;
}