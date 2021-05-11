// ***************************************************************************
// Author:		Joshua Alcantar
// Assignment:	CS-161 Assignment 1
// Date:		April 25, 2021
// Description:	This program tells a user about COVID-19 vaccine eligibility
// Input:		User age as an integer
//				Medical employment as a character (y/n)
//				Underlying health conditions as a character (y/n)
// Output:		Vaccine eligibility registration date
// Sources:		None
// ***************************************************************************

#include <iostream>
#include <cmath>
using namespace std;
// Declare global constants
const double PI = 3.14159265359;
const double LOADFACTOR = 0.698;

int main() {
// Declare all variables
   double jellyBeanLength;
   double jellyBeanHeight;
   double jarVolume;
   double beanVolume;
   unsigned int maxBeans;

// Greet user and explain program
   cout << "Hello, let's play a game called \"Spill the Beans\"." << endl;
   cout << "to two decimal places and press Enter: " << endl;
   cout << "Enter the average length (cm), height (cm), and jar size \
   separated by space:" << endl; 		   
   cin >> jellyBeanLength, jellyBeanHeight, jarVolume;
   
// Run calculations
   beanVolume = (5 * PI * jellyBeanLength * pow(jellyBeanHeight, 2)) / 24;
   maxBeans = jarVolume * LOADFACTOR / beanVolume;
   
// Display output
   cout << "There are: " << maxBeans << " jelly beans in that jar." << endl;

return 0;
}
   cout << "Wondering how many jelly beans are in that jar?" << endl;
   cout << "Enter only numbers and decimals, no letters!" << endl << endl;