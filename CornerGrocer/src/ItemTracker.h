/**
 * File: ItemTracker.h
 * Author: Nat Strode
 * Date: 8/16/2024
 * Class ID: CS210
 * Description: The ItemTracker class is responsible for tracking and analyzing items from a store.
 *              It can read items from a file, search for a specific item, and generate reports
 *              such as frequency lists and histograms of items.
 */

#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <vector>

class ItemTracker {
private:
    std::vector<std::string> items; // Vector to store the items

public:
    // Read in the items from the file
    void readFromFile(const std::string& filename);

    // Get the frequency of a searched item
    int searchItem(const std::string& search) const;

    // Print the frequency of the item within the vector
    void printFrequency() const;

    // Print a histogram representation of the frequency of the items
    void printHistogram() const;

    // Print the output to a file
    void printToOutputFile(const std::string& filename) const;
};

#endif // ITEM_TRACKER_H