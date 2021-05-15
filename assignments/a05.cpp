//****************************************************************************
//   Author:      Joshua Alcantar
//   Assignment:  CS-161 Assignment 5
//   Date:        05/11/2021
//   Description: Interactive menu that outputs cost of gym membership
//   Input:       Menu selection, user age, and training sessions 
//   Output:      Menu options, discounts, line costs and total cost
//   Returns:     None
//   Sources:     None
//****************************************************************************

#include <iomanip>
#include <iostream>

using namespace std;

// Constants
const int MONTH_COST = 20;
const int SESSION_COST = 10;
const double ANNUAL_DISCOUNT = 0.10;
const double SESSION_DISCOUNT = 0.20;
const double SENIOR_DISCOUNT = 0.30;

// Functions declared
void welcome();
void getInfo(bool& senior, int& months, int& personal);
void calcCost(bool senior, int months, int personal);

// Main code block
int main() {
   cout << fixed << setprecision(2);
   // variable declarations
   char userEntry = ' ';
   bool senior = false;
   int months = 0, personal = 0;

   while (userEntry != 'b') {
      welcome();
      cout << "\n>> ";
      cin >> userEntry;
      if (userEntry == 'b')
         continue;
      if (userEntry == 'a') {
         getInfo(senior, months, personal);
         calcCost(senior, months, personal);
         cout << "\nThank you for checking out my fitClub center!! " \
        << "Come back and be fit!\n\n\n" << endl;
      }
   }
   
   return 0;
}

// Functions defined
void welcome() {
   cout << "Welcome to my fitClub program!!" << endl;
   cout << "The cost to become a member of the fitClub center is as follows:" \
        << endl;
   cout << "\t\u2022 The membership fee per month is $20.00" << endl;
   cout << "\t\u2022 The personal training session fee per session is $10.00" \
        << endl;
   cout << "\t\u2022 If the membership is bought and paid for 12 or more " << \
           "months, the" << endl;
   cout << "\t  discount is 10% off membership cost" << endl;
   cout << "\t\u2022 If more than five personal training sessions are bought and" << endl;
   cout << "\t  paid for, the discount on each session is 20%." << endl;
   cout << "\t\u2022 The senior citizens discount is 30% off the total amount." << endl;
   cout << "\nPlease pick one of the following options:\n" << endl;
   cout << "\t\t a. Calculate membership costs." << endl;
   cout << "\t\t b. quit this program." << endl;
}

void getInfo(bool& senior, int& months, int& personal) {
   char userEntry = ' ';
   cout << "\nAre you a Senior Citizen (y/n): ";
   cin >> userEntry;
   if (userEntry == 'y') {
      senior = true;
   }
   cout << "\nHow many months of membership would you like? ";
   cin >> months;
   cout << "\nHow many personal training sessions would you like? ";
   cin >> personal;
}

void calcCost(bool senior, int months, int personal) {
   double totalCost = 0;
   double trainingCost = 0;

   if (months >= 12) {
      totalCost = months * MONTH_COST * (1-ANNUAL_DISCOUNT);
      cout << "\nYour membership cost after the 10% off is $" << totalCost << endl;
   }

   else {
      totalCost = months * MONTH_COST;
      cout << "\nYour membership cost with no annual discount is $" << totalCost \
      << endl;
   }

   if (personal > 5) {
      trainingCost = personal * SESSION_COST * (1-SESSION_DISCOUNT);
   }
   else {
      trainingCost = personal * SESSION_COST;
   }
   cout << "\nYour personal training cost for " << personal << \
        " sessions is $" << trainingCost << endl;
   totalCost += trainingCost;
   cout << "\nYour total membership cost is $" << totalCost << endl;

   if (senior) {
      totalCost *= (1-SENIOR_DISCOUNT);
      cout << "\nAfter your Senior discount, your membership cost is $" \
           << totalCost << endl;
   }
}