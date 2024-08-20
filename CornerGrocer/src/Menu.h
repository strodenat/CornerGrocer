/**
 * File: Menu.h
 * Author: Nat Strode
 * Date: 8/16/2024
 * Class ID: CS210
 * Description: The Menu class is responsible for interacting with the user.
 *              It displays the menu, gets and validates user choices, and executes the corresponding actions.                  
 */

#ifndef MENU_H
#define MENU_H

#include "ItemTracker.h"
#include <string> // Include string for the new method

// The Menu class is responsible for interacting with the user.
// It displays the menu, gets and validates user choices, and executes the corresponding actions.
class Menu {
private:
    ItemTracker itemTracker; // An instance of ItemTracker to manage item data.

public:
    // Asks the user for the name of the data file and returns it.
    std::string getDataFileName();

    // Loads items from the specified file into the itemTracker.
    void loadItems(const std::string& filename);

    // Displays the menu options to the user.
    void displayMenu();

    // Reads and stores the user's choice.
    void getChoice(int &choice);

    // Validates the user's choice to ensure it is within the allowed range.
    void validateChoice(int &choice);

    // Executes the action corresponding to the user's choice.
    void executeChoice(int choice);

    // Saves the data to a file
    void saveDataToFile(const std::string& outputFilename);
};

#endif // MENU_H