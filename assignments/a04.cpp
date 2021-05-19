//*****************************************************************************
// Author:      Joshua Alcantar
// Assignment:  CS-161 Assignment 4
// Date:        April 29, 2021
// Description: Interactive restaurant menu
// Input:       Integers in main menu, capital letters in submenus
// Output:      Greeting, total items selected and subtotals then total cost
//              and saluation. Will correct user for invalid entry
// Returns:     
// Sources:     None
// ***************************************************************************

#include <iostream>
#include <string>
#include <iomanip>

// Constants declared
const double DONUT = 0.99, MUFFIN = 1.99, PASTRY = 2.99;
const double BAGEL = 1.99, TOAST = 0.99;
const double COFFEE = 2.99, TEA = 0.99;

using namespace std;
// Print welcome message
void welcome();
// Display menu
void menu();
// Check for valid user input
void submenus();
// Display receipt
double receipt();
// Salutation message
void goodbye();

// Declared variables
int topMenuEntry = 0;
int donuts = 0, muffins = 0, pastries = 0;
int bagels = 0, toast = 0;
int coffee = 0, tea = 0;
char sweetsMenuEntry = ' ';
char savoryMenuEntry = ' ';
char drinksMenuEntry = ' ';
double total = 0;

int main() {
  welcome();
  menu();
  submenus();
  receipt();
  goodbye();

  return 0;
}