/**
 * File: main.cpp
 * Author: Nat Strode
 * Date: 8/16/2024
 * Class ID: CS210
 * Description: The main function creates an instance of the Menu class and interacts with the user.
 *              It displays the menu options, gets the user's choice, and executes the corresponding action.
 *              The program continues to run until the user chooses to exit.
 */

#include "Menu.h"
#include <string>
#include <iostream>

using namespace std;

int main() {

    // Variables
    Menu menu; // Create an instance of the Menu class.
    int choice; // Variable to store the user's choice.

    // Get the name of the data file from the user.
    std::string filename = menu.getDataFileName(); 

    // Load items from the specified file into the itemTracker.
    menu.loadItems(filename); 

    // Create frequency.dat output file
    menu.saveDataToFile("../data/frequency.dat");

    do {
        // Display the menu options.
        menu.displayMenu(); 

        // Get the user's choice.
        menu.getChoice(choice); 

        // Validate the user's choice.
        menu.validateChoice(choice); 

        // Execute the corresponding action.
        menu.executeChoice(choice); 
        
    } while (choice != 4); // Loop until the user chooses to exit.

    return 0;
}