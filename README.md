# CornerGrocer Item-Tracking Program

## Author
Nat Strode

## Course
CS210 - Introduction to Programming

## Date
August 20, 2024

## Project Overview
The CornerGrocer Item-Tracking Program is a console-based application developed in C++. The program helps a grocery store analyze and track the frequency of items purchased throughout the day. By reading an input file containing a list of items, the program calculates the frequency of each item, provides options to search for specific items, and displays this data in both list and histogram formats. Additionally, the program automatically generates a backup file, `frequency.dat`, which stores the frequency of all items.

### Features:
- **Search for Item Frequency**: Users can input an item name to see how many times it was purchased.
- **Frequency Listing**: The program lists the frequency of all items purchased during the day.
- **Histogram Display**: The program visualizes the frequency of items using a histogram format.
- **Automatic Backup**: The program generates a `frequency.dat` file at the start, storing the frequency of each item.

## Reflections

### Summary of the Project
The CornerGrocer program was created to solve the problem of tracking item purchases efficiently. By calculating and displaying item frequencies, the grocery store can optimize its layout based on purchasing patterns.

### What I Did Well
I utilized C++ classes to organize the program’s functionality, making the code modular and easy to maintain. The program also adheres to best practices in terms of readability and documentation.

### Enhancements and Improvements
One possible improvement is to add functionality for tracking purchases over multiple days, allowing the store to analyze trends over time. This could be implemented by adding a feature that appends daily data to the existing `frequency.dat` file rather than overwriting it, and by creating additional functions to report on weekly or monthly trends. This would provide the store with more comprehensive data for decision-making and could help identify longer-term purchasing patterns.

### Challenges Faced and Solutions
One of the more challenging aspects was ensuring the accuracy of the file handling processes. I overcame this by debugging and validating the paths and file operations, ensuring that the data was correctly read, processed, and saved.

### Transferable Skills
The skills gained in organizing the code into classes, handling file operations, and implementing input validation will be useful in future projects and coursework. These skills are transferable to other programming languages and more complex systems.

### Code Maintainability
To ensure the program is maintainable, readable, and adaptable, I implemented clear naming conventions, consistent commenting, and modular code design. This approach makes it easier to update or extend the program with additional features or improvements.

## How to Run the Program
1. **Compile the Code**: Use a C++ compiler to compile the program files (`main.cpp`, `Menu.cpp`, `ItemTracker.cpp`).
2. **Input File**: Place your input file in the specified directory (e.g., `data/frequency.dat`).
3. **Run the Executable**: Execute the compiled program from the terminal.
4. **Follow the Prompts**: The program will guide you through the available options.
