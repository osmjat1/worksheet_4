#include <iostream>
using namespace std;

// Define a Queue class
class Queue {
    int arr[10], front, rear, size; // Array for storing queue elements, and front, rear, size variables
    const int MAX = 10;             // Constant max size of queue

public:
    // Constructor to initialize queue
    Queue() : front(0), rear(-1), size(0) {}

    // Function to add an element to the queue
    void enqueue(int x) {
        if (size == MAX) {          // If queue is full
            cout << "Overflow!\n";  // Print overflow message
            return;
        }
        rear = (rear + 1) % MAX;    // Circularly move rear
        arr[rear] = x;              // Insert value at new rear
        size++;                     // Increase size
    }

    // Function to remove and return front element
    int dequeue() {
        if (size == 0) {            // If queue is empty
            cout << "Underflow!\n"; // Print underflow message
            return -1;              // Return error value
        }
        int val = arr[front];       // Get value at front
        front = (front + 1) % MAX;  // Move front circularly
        size--;                     // Decrease size
        return val;                 // Return dequeued value
    }

    // Function to reverse first k elements of the queue
    void reverseK(int k) {
        if (k > size || k <= 0) {       // Validate value of k
            cout << "Invalid K!\n";
            return;
        }
        for (int i = 0; i < k/2; i++) { // Swap first k elements
            int left = (front + i) % MAX;
            int right = (front + k - 1 - i) % MAX;
            swap(arr[left], arr[right]); // Swap elements at left and right
        }
    }

    // Function to interleave the two halves of the queue
    void interleave() {
        if (size % 2 != 0) {             // Only works if size is even
            cout << "Need even size!\n";
            return;
        }
        int half = size / 2;             // Midpoint of the queue
        for (int i = 0; i < half; i++) { // Swap i-th elements from first and second halves
            int first = (front + i) % MAX;
            int second = (front + half + i) % MAX;
            swap(arr[first], arr[second]);
        }
    }

    // Function to display queue elements
    void display() {
        for (int i = 0; i < size; i++)               // Loop through all valid elements
            cout << arr[(front + i) % MAX] << " ";   // Print each element circularly
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;                        // Create a Queue object
    int choice, val, k;             // Variables for user input

    // Infinite menu-driven loop
    while (true) {
        // Menu options
        cout << "\n 1. Enqueue\n 2. Dequeue\n 3. Reverse K \n 4. Interleave\n 5. Exit\nChoice: ";
        cin >> choice;              // Read user choice

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;             // Read value to enqueue
                q.enqueue(val);         // Call enqueue function
                q.display();            // Display queue after enqueue
                break;

            case 2:
                val = q.dequeue();      // Call dequeue function
                if (val != -1)          // If not underflow
                    cout << "Dequeued: " << val << endl;
                q.display();            // Display queue after dequeue
                break;

            case 3:
                cout << "Enter K: ";
                cin >> k;               // Read value of K
                q.reverseK(k);          // Reverse first K elements
                q.display();            // Display queue
                break;

            case 4:
                q.interleave();         // Interleave the two halves
                q.display();            // Display result
                break;

            case 5:
                return 0;               // Exit program

            default:
                cout << "Invalid choice!\n"; // Handle invalid inputs
        }
    }
}
