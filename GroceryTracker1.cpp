#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequency;

    void loadHardcodedData() {
        // All grocery items hardcoded
        std::vector<std::string> items = {
            "Spinach", "Radishes", "Broccoli", "Peas", "Cranberries", "Broccoli",
            "Potatoes", "Cucumbers", "Radishes", "Cranberries", "Peaches", "Zucchini",
            "Potatoes", "Cranberries", "Cantaloupe", "Beets", "Cauliflower", "Cranberries",
            "Peas", "Zucchini", "Peas", "Onions", "Potatoes", "Cauliflower", "Spinach",
            "Radishes", "Onions", "Zucchini", "Cranberries", "Peaches", "Yams", "Zucchini",
            "Apples", "Cucumbers", "Broccoli", "Cranberries", "Beets", "Peas", "Cauliflower",
            "Potatoes", "Cauliflower", "Celery", "Cranberries", "Limes", "Cranberries",
            "Broccoli", "Spinach", "Broccoli", "Garlic", "Cauliflower", "Pumpkins", "Celery",
            "Peas", "Potatoes", "Yams", "Zucchini", "Cranberries", "Cantaloupe", "Zucchini",
            "Pumpkins", "Cauliflower", "Yams", "Pears", "Peaches", "Apples", "Zucchini",
            "Cranberries", "Zucchini", "Garlic", "Broccoli", "Garlic", "Onions", "Spinach",
            "Cucumbers", "Cucumbers", "Garlic", "Spinach", "Peaches", "Cucumbers", "Broccoli",
            "Zucchini", "Peas", "Celery", "Cucumbers", "Celery", "Yams", "Garlic", "Cucumbers",
            "Peas", "Beets", "Yams", "Peas", "Apples", "Peaches", "Garlic", "Celery", "Garlic",
            "Cucumbers", "Garlic", "Apples", "Celery", "Zucchini", "Cucumbers", "Onions"
        };

        // Count item frequencies
        for (const auto& item : items) {
            itemFrequency[item]++;
        }

        // Create backup file (as required)
        std::ofstream outputFile("frequency.dat");
        for (const auto& pair : itemFrequency) {
            outputFile << pair.first << " " << pair.second << std::endl;
        }
        outputFile.close();
    }

public:
    GroceryTracker() {
        loadHardcodedData();
    }

    int getItemFrequency(const std::string& item) const {
        auto it = itemFrequency.find(item);
        return (it != itemFrequency.end()) ? it->second : 0;
    }

    void printAllFrequencies() const {
        std::cout << "\nItem Frequencies:\n";
        std::cout << "-----------------\n";
        for (const auto& pair : itemFrequency) {
            std::cout << std::setw(15) << std::left << pair.first
                << ": " << pair.second << std::endl;
        }
    }

    void printHistogram() const {
        std::cout << "\nItem Histogram:\n";
        std::cout << "---------------\n";
        for (const auto& pair : itemFrequency) {
            std::cout << std::setw(15) << std::left << pair.first
                << ": " << std::string(pair.second, '*') << std::endl;
        }
    }
};

void displayMenu() {
    std::cout << "\nCorner Grocer Item Tracker\n";
    std::cout << "-------------------------\n";
    std::cout << "1. Search item frequency\n";
    std::cout << "2. Display all frequencies\n";
    std::cout << "3. Display histogram\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice (1-4): ";
}

int main() {
    GroceryTracker tracker;

    int choice;
    std::string searchItem;

    do {
        displayMenu();
        std::cin >> choice;

        // Input validation
        while (std::cin.fail() || choice < 1 || choice > 4) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 4: ";
            std::cin >> choice;
        }

        switch (choice) {
        case 1:
            std::cout << "Enter item to search: ";
            std::cin >> searchItem;
            std::cout << "Frequency of " << searchItem << ": "
                << tracker.getItemFrequency(searchItem) << std::endl;
            break;
        case 2:
            tracker.printAllFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        }
    } while (choice != 4);

    return 0;
}