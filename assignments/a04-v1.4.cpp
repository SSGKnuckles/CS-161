//****************************************************************************
// Author:      Joshua Alcantar
// Assignment:  CS-161 Assignment 4
// Date:        May 8, 2021
// Description: Interactive restaurant menu
// Input:       Single character menu selection
//              Multi character item selection
// Output:      Greeting, item selection confirmation, rolling and final
//              totals, goodbye
// Returns:     None
// Sources:     None
// ***************************************************************************

#include <iostream>
#include <string>
#include <iomanip>

// Constants declared
const double DONUT = 0.99, MUFFIN = 1.99, PASTRY = 2.99;
const double BAGEL = 1.99, TOAST = 0.99;
const double COFFEE = 2.99, TEA = 0.99;
enum menuList {MAIN_MENU = 0, SWEETS_MENU = 1, \
SAVORY_MENU = 2, DRINKS_MENU = 3, QUIT = 4};
// valid menu entries in case more items added later
  const std::string VALID0 = "1234";
  const std::string VALID1 = "DMPQ";
  const std::string VALID2 = "BTQ";
  const std::string VALID3 = "CTQ";

using namespace std;

// Function prototypes
void welcome();                     // working
void displayMenu(menuList currentMenu);  // working
// list of available menus
void mainMenu();                    // working
void sweetsMenu();                  // working
void savoryMenu();                  // working
void drinksMenu();                  // working
// Take user entry
char readOption();                  // working
// Validate user entry
bool validateOption(menuList currentMenu, char& userEntry);
// Switch from main to submenus
void menuSwitch(char userEntry, menuList& currentMenu);
// if valid entry, execute entry
double executeOption(menuList& currentMenu, bool validEntry, char userEntry);

int main() {
// Declared variables
  char userEntry = ' ';
  bool validEntry = false;
  double totalCost = 0;
  cout << fixed << setprecision(2);
  menuList currentMenu = MAIN_MENU;

// Main code
  welcome();
  while (userEntry != '4') {
    displayMenu(currentMenu);
    userEntry = readOption();
    validEntry = validateOption(currentMenu, userEntry);
    if (!validEntry) {
      cout << "Invalid entry, please try again." << endl;
      userEntry = ' ';
      continue;
    }
    else if (userEntry == '4') {
      break;
    }
    else if (userEntry == 'Q') {
      currentMenu = MAIN_MENU;
      continue;
    }
    else if (currentMenu == MAIN_MENU) {
      menuSwitch(userEntry, currentMenu);
      continue;
    }
    totalCost += executeOption(currentMenu, validEntry, userEntry);
    cout << "Total Cost: $" << totalCost << endl;
  }
  cout << "Thanks for visiting my coffee shop!" << endl;
  cout << "Total Cost: $" << totalCost << endl;
  
  return 0;
}

void welcome() {
  cout << "Welcome to my Coffee Shop!" << endl;
}

void displayMenu(menuList currentMenu) {
  switch (currentMenu) {
    case MAIN_MENU:
      mainMenu();
      break;

    case SWEETS_MENU:
      sweetsMenu();
      break;

    case SAVORY_MENU:
      savoryMenu();
      break;

    case DRINKS_MENU:
      drinksMenu();
      break;

    case QUIT:
      break;
  }
}

// Displays main menu options
void mainMenu() {
  cout << "Please pick an option below:" << endl;
  cout << "  1. Donuts/Muffins/Pastries" << endl;
  cout << "  2. Bagel/Toast" << endl;
  cout << "  3. Coffee/Tea" << endl;
  cout << "  4. Quit" << endl;
}
// submenus
void sweetsMenu() {
  cout << "What sweet eats would you like?" << endl;
  cout << "  Donut  (D) $" << DONUT << endl;
  cout << "  Muffin (M) $" << MUFFIN << endl;
  cout << "  Pastry (P) $" << PASTRY << endl;
  cout << "  Back   (Q) to main menu" << endl;
}
void savoryMenu() {
  cout << "What savory eats would you like?" << endl;
  cout << "  Bagel  (B) $" << BAGEL << endl;
  cout << "  Toast  (T) $" << TOAST << endl;
  cout << "  Back   (Q) to main menu" << endl;
}
void drinksMenu() {
  cout << "What beverages would you like?" << endl;
  cout << "Coffee  (C) $" << COFFEE << endl;
  cout << "Tea     (T) $" << TEA << endl;
  cout << "Back    (Q) to main menu" << endl;
}

// Reads user menu selection
char readOption() {
  char userEntry = ' ';
  cin.clear();
  cin >> userEntry;
  return static_cast<char>(toupper(userEntry));
}

bool validateOption(menuList currentMenu, char& userEntry) {
  if (currentMenu == MAIN_MENU) {
    for (int i = 0; i < 5; i++) {
      if (userEntry == VALID0.at(i))
        return true;
    }
  }
  else if (currentMenu == SWEETS_MENU) {
    for (int i = 0; i < VALID1.size(); i++) {
      if (userEntry == VALID1.at(i))
        return true;
    }
  }
  else if (currentMenu == SAVORY_MENU) {
    for (int i = 0; i < VALID2.size(); i++) {
      if (userEntry == VALID2.at(i))
        return true;
    }
    return false;
  }
  else if (currentMenu == DRINKS_MENU) {
    for (int i = 0; i < VALID3.size(); i++) {
      if (userEntry == VALID3.at(i))
        return true;
    }
    return false;
  }
  return false;
}
void menuSwitch(char userEntry, menuList& currentMenu) {
  if (userEntry == '1')
    currentMenu = SWEETS_MENU;
  if (userEntry == '2')
    currentMenu = SAVORY_MENU;
  if (userEntry == '3')
    currentMenu = DRINKS_MENU;
  if (userEntry == '4')
    currentMenu = QUIT;
}
// if entry valid, execute choice, return price
double executeOption(menuList& currentMenu, bool validEntry, char userEntry) {
  switch (currentMenu) {
    case SWEETS_MENU:
      switch (userEntry) {
        case 'D':
          cout << "Donut added  - $" << DONUT << endl;
          return DONUT;
        case 'M':
          cout << "Muffin added - $" << MUFFIN << endl;
          return MUFFIN;
        case 'P':
          cout << "Pastry added - $" << PASTRY << endl;
          return PASTRY;
        case 'Q':
          currentMenu = MAIN_MENU;
          return 0;
      }
    case SAVORY_MENU:
      switch (userEntry) {
        case 'B':
          cout << "Bagel added - $" << BAGEL << endl;
          return BAGEL;
        case 'T':
          cout << "Toast added - $" << TOAST << endl;
          return TOAST;
        case 'Q':
          currentMenu = MAIN_MENU;
          return 0;
      }
    case DRINKS_MENU:
      switch (userEntry) {
        case 'C':
          cout << "Coffee added - $" << COFFEE << endl;
          return COFFEE;
        case 'T':
          cout << "Tea added - $" << TEA << endl;
          return TEA;
        case 'Q':
          currentMenu = MAIN_MENU;
          return 0;
      }
    case QUIT:
      return 0;
    default:
      return 0;
  }
}