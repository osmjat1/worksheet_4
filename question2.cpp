#include <iostream>
using namespace std;


// Define a Stack class
class Stack {
private:
    int arr[10];     // Array to store stack elements (max size = 10)
    int top;         // Variable to track top of the stack

public:
    // Constructor to initialize stack
    Stack() {
        top = -1;               // -1 indicates stack is empty
    }

    // Push function to add element to the stack
    void push(int value) {
        if (top >= 9) {         // Check if stack is full (index 0 to 9)
            cout << "Stack Overflow! Cannot push more elements.\n";
            return;             // Exit function if overflow
        }
        arr[++top] = value;     // Increment top and insert value
        cout << "Pushed: " << value << endl;
    }

    // Pop function to remove top element from stack
    void pop() {
        if (top == -1) {        // Check if stack is empty
            cout << "Stack Underflow! No elements to pop.\n";
            return;             // Exit function if underflow
        }
        cout << "Popped: " << arr[top--] << endl; // Display and remove top element
    }

    // Function to display stack contents from top to bottom
    void display() {
        if (top == -1) {        // If stack is empty
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {  // Loop from top to bottom
            cout << arr[i] << " ";       // Print each element
        }
        cout << endl;
    }

    // Function to find and display the middle element
    void findMiddle() {
        if (top == -1) {        // If stack is empty
            cout << "Stack is empty.\n";
            return;
        }
        int midIndex = top / 2; // Find middle index
        cout << "Middle element: " << arr[midIndex] << endl; // Show middle value
    }

    // Function to reverse only the bottom half of the stack
    void reverseBottomHalf() {
        if (top <= 0) {         // If stack has 0 or 1 element, nothing to reverse
            cout << "Not enough elements to reverse bottom half.\n";
            return;
        }

        int half = (top + 1) / 2;   // Number of elements in bottom half
        for (int i = 0; i < half / 2; i++) {
            // Swap i-th element with its mirror in bottom half
            int temp = arr[i];
            arr[i] = arr[half - 1 - i];
            arr[half - 1 - i] = temp;
        }

        cout << "Bottom half reversed.\n";
    }
};

// Main function to drive the program
int main() {
    Stack s;                  // Create stack object
    int choice, value;        // For user input

    // Menu-driven loop
    do {
        // Display menu
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Find Middle\n5. Reverse Bottom Half\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;        // Take user choice

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;     // Input value from user
            s.push(value);    // Call push function
            break;

        case 2:
            s.pop();          // Call pop function
            break;

        case 3:
            s.display();      // Call display function
            break;

        case 4:
            s.findMiddle();  // Call findMiddle function
            break;

        case 5:
            s.reverseBottomHalf();  // Call reverse bottom half function
            break;

        case 6:
            cout << "Exiting...\n"; // Exit message
            break;

        default:
            cout << "Invalid choice! Try again.\n"; // Invalid input
        }

    } while (choice != 6);    // Repeat until user chooses to exit

    return 0;
}
