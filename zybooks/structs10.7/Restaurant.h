#ifndef RESTAURANT_H
#define RESTAURANT_H

struct Restaurant;
Restaurant listing {
    char restaurantName[101];        
    char foodType[101;
    double rating;
}

// Related functions
void SetValues(Restaurant& listing, char newName[], char newFood[], double newRating);

void PrintValues(Restaurant& listing);

#endif