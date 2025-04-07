#include <iostream>
#include <vector>         // For using vector container
#include <map>            // For using map container
#include <algorithm>      // For sort() function
using namespace std;

// Class to manage people's names and ages
class PeopleManager {
private:
    vector<string> names;      // Stores all names in insertion order
    map<string, int> nameAgeMap;  // Maps names to ages for quick lookup

public:
    // Adds a new person to the manager
    void addPerson(const string& name, int age) {
        names.push_back(name);       // Add name to vector
        nameAgeMap[name] = age;      // Add name-age pair to map
        cout << "Added: " << name << " (Age " << age << ")\n";  // Confirmation
    }

    // Finds and displays people above specified age
    void findAboveAge(int ageLimit) {
        cout << "\nPeople above age " << ageLimit << ":\n";
        bool found = false;  // Flag to check if any matches found

        // Iterate through all name-age pairs
        for (const auto& entry : nameAgeMap) {
            if (entry.second > ageLimit) {  // Check age condition
                cout << entry.first << " - " << entry.second << " years\n";
                found = true;  // Mark as found
            }
        }

        // If no matches found
        if (!found) {
            cout << "No one found above age " << ageLimit << ".\n";
        }
    }

    // Displays names sorted alphabetically with ages
    void displaySortedNames() {
        cout << "\nNames sorted alphabetically:\n";
        vector<string> sortedNames = names;  // Create copy for sorting
        sort(sortedNames.begin(), sortedNames.end());  // Sort alphabetically

        // Display each name with age
        for (const string& name : sortedNames) {
            cout << name << " (Age " << nameAgeMap[name] << ")\n";
        }
    }
};

int main() {
    PeopleManager manager;  // Create manager instance
    int choice;            // For menu selection

    // Main program loop
    do {
        // Display menu
        cout << "\n--- Menu ---\n";
        cout << "1. Add person\n";
        cout << "2. Find people above certain age\n";
        cout << "3. Display sorted names\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string name;  // For storing input name
        int age;      // For storing input age

        // Process user choice
        switch (choice) {
            case 1:  // Add person
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                manager.addPerson(name, age);
                break;

            case 2:  // Find people above age
                cout << "Enter age limit: ";
                cin >> age;
                manager.findAboveAge(age);
                break;

            case 3:  // Display sorted names
                manager.displaySortedNames();
                break;

            case 4:  // Exit program
                cout << "Exiting...\n";
                break;

            default:  // Invalid choice
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);  // Continue until user chooses to exit

    return 0;  // End program
}
