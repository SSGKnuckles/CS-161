int main() {

    welcomeMessage(); // function
    while (userEntry != 'Q') {
    displayMenu(MENU_NAME); // switch for different menus
    userEntry = readSelection(); // take user input
    validEntry = validateEntry(userEntry); // returns to read selection if invalid
    if (validEntry)
        executeSelection(userEntry) // if main menu, change MENU_NAME, else select item or quit to main
    }  

    return 0;
}