// ***************************************************************************
// Author:		Joshua Alcantar
// Assignment:	CS-161 Assignment 1
// Date:		April 26, 2021
// Description:	This program computes max volume of jelly beans in a jar.
// Input:		User age as an integer
// Output:		Number of jelly beans in user's jar
// Sources:		a01-v1.2.cpp
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
   cin >> jellyBeanLength >> jellyBeanHeight >> jarVolume;
   
// Run calculations
   beanVolume = (5 * PI * jellyBeanLength * pow(jellyBeanHeight, 2)) / 24;
   maxBeans = jarVolume * LOADFACTOR / beanVolume;
   
// Display output
   cout << "There are: " << maxBeans << " jelly beans in that jar." << endl;

return 0;
}