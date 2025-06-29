# CS210-Portfolio

## GroceryTracker - Corner Grocer Item Tracker

# CS 210 Project: Grocery Item Tracker

## 📝 Project Overview
A C++ program that analyzes daily purchase data for Corner Grocer, providing:
- Individual item frequency lookup
- Complete frequency list output
- Visual histogram display
- Automatic data backup to `frequency.dat`

## 🛠️ How to Run
1. **Compile**:  
   ```bash
   g++ GroceryTracker.cpp -o tracker
Execute:

bash
./tracker
Reflection
1. Project Purpose
This program solves Corner Grocer's need to analyze customer purchases by tracking how often each item appears in their daily sales data. It helps optimize store layout by identifying popular items.

2. Strengths
Clean architecture: Used OOP principles with a GroceryTracker class

User-friendly: Simple menu system with input validation

Efficient: Leveraged C++ maps for fast frequency counting

Documented: Added clear comments explaining key functions

3. Improvement Opportunities
Enhanced security: Add input sanitization

Error handling: Implement try-catch for file operations

Performance: Switch to unordered_map for larger datasets

4. Challenges & Solutions
File I/O Issues:
Initially struggled with file stream errors. Fixed by:

Verifying #include <fstream> was present

Adding is_open() checks

Testing with different file paths

Case Sensitivity:
Created a lowercase conversion function to ensure "Apple" and "apple" are counted together.

5. Transferable Skills
C++ fundamentals: Classes, STL containers, file I/O

Debugging techniques: Isolated issues using print statements

Problem-solving: Broke down requirements into modular components

6. Maintainability Features
Modular design: Separate functions for each menu option

Clear naming: Descriptive variables like itemFrequency

Scalable structure: Easy to add new features like date filtering

Files Included
GroceryTracker.cpp - Main program source

frequency.dat - Sample output file

README.md - This documentation
