/**
 * File: ItemTracker.cpp
 * Author: Nat Strode
 * Date: 8/16/2024
 * Class ID: CS210
 * Description: The ItemTracker class is responsible for tracking and analyzing items from a store.
 *              It can read items from a file, search for a specific item, and generate reports
 *              such as frequency lists and histograms of items.
 */

#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <algorithm> // For transform function

using namespace std;

// Reads items from the specified file and stores them in the 'items' vector.
// Each item is formatted so that the first letter is capitalized, and the rest are lowercase.
void ItemTracker::readFromFile(const string& filename) {
    ifstream inputFile(filename); // Open the file for reading.

    if (!inputFile.is_open()) { // Check if the file was opened successfully.

        cout << "Unable to open file: " << filename << endl; // Print an error message.

        return; // Exit the function early.
    }

    string item; // To store each item read from the file.

    while (inputFile >> item) { // Read items from the file until the end is reached.

        // Format the item so that the first letter is capitalized, and the rest are lowercase.
        item[0] = toupper(item[0]);
        transform(item.begin() + 1, item.end(), item.begin() + 1, ::tolower);

        items.push_back(item); // Add the formatted item to the 'items' vector.
    }
    inputFile.close(); // Close the file after reading.

    if (items.empty()) { // If there are no items in the vector:

        cout << "No items were read from the file." << endl; // Print a message indicating that no items were read.
    
    } else { // If items were successfully loaded:
        
        cout << "Items successfully loaded from the file." << endl; // Print a success message.
    }
} // End of readFromFile

// Searches for the given item in the 'items' vector and returns the count of its occurrences.
// The search term is formatted to match the case style of the stored items.
int ItemTracker::searchItem(const string& search) const {
    
    // Create a copy of the search term and format it to match the case of stored items.
    string formattedSearch = search;

    // Capitalize the first letter of the search term.
    formattedSearch[0] = toupper(formattedSearch[0]);

    // Convert the rest of the search term to lowercase.
    transform(formattedSearch.begin() + 1, formattedSearch.end(), formattedSearch.begin() + 1, ::tolower);

    // Initialize a count to store the number of occurrences of the search term.
    int count = 0;

    for (const auto& item : items) { // Iterate through all items in the list.

        string formattedItem = item; // Make a copy of the item from the list

        // Format the item to match the case style of the search term.
        formattedItem[0] = toupper(formattedItem[0]);
        transform(formattedItem.begin() + 1, formattedItem.end(), formattedItem.begin() + 1, ::tolower);

        // Check if the formatted item matches the formatted search term.
        if (formattedItem == formattedSearch) {
            count++;
        }
    }

    // Print the number of occurrences of the search term.
    cout << "The item " << formattedSearch << " was found " << count << " times." << endl;
    
    return count; // Return the count of occurrences.
} // End of searchItem

// Prints the frequency of each unique item in the 'items' vector.
void ItemTracker::printFrequency() const {
    
    vector<string> uniqueItems; // To store unique items.
    vector<int> frequency; // To store the frequency of each unique item.

    // Iterate through all items to build the frequency list.
    for (const auto& item : items) {

        // Check if the item is already in the uniqueItems vector.
        auto it = find(uniqueItems.begin(), uniqueItems.end(), item);

        if (it != uniqueItems.end()) { // If the item is already in the uniqueItems vector:

            int index = distance(uniqueItems.begin(), it); // Get the index of the item.

            frequency[index]++; // Increment the corresponding frequency.

        } else { // If the item is not in the uniqueItems vector:

            uniqueItems.push_back(item); // Add the item to uniqueItems.

            frequency.push_back(1); // Start the frequency count at 1.
        }
    }

    // Print each unique item along with its frequency.
    for (size_t i = 0; i < uniqueItems.size(); i++) {

        cout << uniqueItems[i] << " " << frequency[i] << endl;

    }
} // End of printFrequency

// Prints a histogram where each item is followed by a number of asterisks corresponding to its frequency.
void ItemTracker::printHistogram() const {
    vector<string> uniqueItems; // To store unique items.
    vector<int> frequency; // To store the frequency of each unique item.

    // Iterate through all items to build the frequency list.
    for (const auto& item : items) {

        auto it = find(uniqueItems.begin(), uniqueItems.end(), item);

        if (it != uniqueItems.end()) { // If the item is already in the uniqueItems vector:

            int index = distance(uniqueItems.begin(), it); // Get the index of the item.

            frequency[index]++; // Increment the corresponding frequency.

        } else { // If the item is not in the uniqueItems vector:

            uniqueItems.push_back(item); // Add the item to uniqueItems.

            frequency.push_back(1); // Start the frequency count at 1.
        }
    }

    // Print each unique item along with a number of asterisks representing its frequency.
    for (size_t i = 0; i < uniqueItems.size(); i++) { // Iterate through all unique items.

        cout << uniqueItems[i] << " "; // Print the item name.

        for (int j = 0; j < frequency[i]; j++) { // Iterate through the frequency of the item.

            cout << "*"; // Print an asterisk for each occurrence of the item.
        }
        cout << endl;
    }
} // End of printHistogram

// Writes the current list of items to the specified file, one item per line.
void ItemTracker::printToOutputFile(const string& filename) const {
    
    // Open the file for writing.
    ofstream outputFile(filename);

    if (outputFile.is_open()) { // Check if the file was opened successfully.
        vector<string> uniqueItems; // To store unique items.
        vector<int> frequency; // To store the frequency of each unique item.

        // Iterate through all items to build the frequency list.
        for (const auto& item : items) {

            auto it = find(uniqueItems.begin(), uniqueItems.end(), item);

            if (it != uniqueItems.end()) { // If the item is already in the uniqueItems vector:

                int index = distance(uniqueItems.begin(), it); // Get the index of the item.

                frequency[index]++; // Increment the corresponding frequency.

            } else { // If the item is not in the uniqueItems vector:

                uniqueItems.push_back(item); // Add the item to uniqueItems.

                frequency.push_back(1); // Start the frequency count at 1.
            }
        }

        // Write each unique item along with its frequency to the output file.
        for (size_t i = 0; i < uniqueItems.size(); i++) {

            outputFile << uniqueItems[i] << " " << frequency[i] << endl;
        }

        outputFile.close(); // Close the file after writing.

    } else { // If the file could not be opened:
        cout << "Unable to open file: " << filename << endl;
    }
} // End of printToOutputFile