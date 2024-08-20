/**
 * File: Menu.cpp
 * Author: Nat Strode
 * Date: 8/16/2024
 * Class ID: CS210
 * Description: The Menu class is responsible for interacting with the user.
 *              It displays the menu, gets and validates user choices, and executes the corresponding actions.
 */

#include "Menu.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Loads items from the specified file into the itemTracker.
void Menu::loadItems(const string& filename) {
    string filepath = "../data/" + filename; // Adjusted path to go up one directory
    cout << "Attempting to open file: " << filepath << endl;
    itemTracker.readFromFile(filepath);
}

// Asks the user for the name of the data file and returns it.
string Menu::getDataFileName() {
    string filename;
    cout << "Please enter the name of the data file: ";
    cin >> filename;
    return filename;
}

// Displays the menu options to the user.
void Menu::displayMenu() {
    cout << "1) Search for an item" << endl;
    cout << "2) Print frequency of all items" << endl;
    cout << "3) Print histogram of all items" << endl;
    cout << "4) Exit" << endl;
}

// Reads and stores the user's choice.
void Menu::getChoice(int &choice) {
    while (true) {
        std::cout << "Enter your choice: ";
        if (std::cin >> choice && choice >= 1 && choice <= 4) {
            break; // Valid choice
        } else {
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        }
    }
}

// Validates the user's choice to ensure it is within the allowed range.
void Menu::validateChoice(int &choice) {
    while (choice < 1 || choice > 4) {
        cout << "Invalid choice. Please enter a valid choice: ";
        cin >> choice;
    }
}

// Executes the action corresponding to the user's choice.
void Menu::executeChoice(int choice) {
    string search;
    switch (choice) {
        case 1: // If the user chooses to search for an item:
            cout << "Enter the item you would like to search for: ";
            cin >> search;
            itemTracker.searchItem(search); // Search for the item and print the result.
            break;
        case 2: // If the user chooses to print the frequency of all items:
            itemTracker.printFrequency(); // Print the frequency of each item.
            break;
        case 3: // If the user chooses to print a histogram of all items:
            itemTracker.printHistogram(); // Print the histogram.
            break;
        case 4: // If the user chooses to exit:
            saveDataToFile("../data/frequency.dat"); // Save the current items to a file in the correct directory.
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
}

// Saves the data to a file
void Menu::saveDataToFile(const std::string& outputFilename) {
    itemTracker.printToOutputFile(outputFilename); // Call the method on the private member
}