#include <iostream>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node
    Node(int val) : data(val), next(nullptr) {}  // Constructor initializes data and sets next to null
};

// Linked list class to manage the nodes
class LinkedList {
    Node* head;  // Pointer to the first node in the list
public:
    LinkedList() : head(nullptr) {}  // Constructor initializes empty list

    // Insert a new node with given value at specified position (default: beginning)
    void insert(int val, int pos=-1) {
        Node* newNode = new Node(val);  // Create new node
        if(pos <= 0 || !head) {         // Insert at beginning if position <= 0 or list is empty
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        // Traverse to the position before insertion point
        for(int i=1; i<pos && temp->next; i++)
            temp = temp->next;
        // Insert new node
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Detect and remove any loop in the linked list using Floyd's algorithm
    void removeLoop() {
        Node *slow = head, *fast = head;  // Initialize two pointers
        // Move slow by 1 and fast by 2 until they meet or reach end
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;  // Loop detected
        }
        if(slow == fast) {  // If loop exists
            slow = head;
            // Find the loop starting point
            while(slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = nullptr;  // Break the loop
            cout << "Loop removed\n";
        }
    }

    // Find and print the nth node from the end of the list
    void nthFromEnd(int n) {
        Node *first = head, *second = head;  // Two pointers
        // Move first pointer n nodes ahead
        for(int i=0; i<n && first; i++) first = first->next;
        if(!first) {  // If n is larger than list length
            cout << "Invalid position\n";
            return;
        }
        // Move both pointers until first reaches end
        while(first) {
            first = first->next;
            second = second->next;
        }
        cout << "Value: " << second->data << endl;  // Print the nth node from end
    }

    // Reverse the list in groups of given size k
    void reverseGroups(int k) {
        Node *curr = head, *prev = nullptr, *next = nullptr;
        int count = 0;
        // Reverse k nodes
        while(curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next) {  // If more nodes remain
            head->next = curr;
            // Skip k nodes for next group
            for(int i=0; i<k && curr; i++) curr = curr->next;
            if(curr) reverseGroups(k);  // Recursively reverse next group
        }
        head = prev;  // Update head to new start of reversed list
    }

    // Display the entire linked list
    void display() {
        Node* temp = head;
        while(temp) {  // Traverse until end of list
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";  // Mark end of list
    }
};

int main() {
    LinkedList list;  // Create linked list instance
    int choice, val, pos;

    // Main menu loop
    while(true) {
        cout << "\n1.Insert 2.RemoveLoop 3.NthFromEnd 4.ReverseGroups 5.Display 6.Exit\nChoice: ";
        cin >> choice;

        switch(choice) {
            case 1:  // Insert node
                cout << "Value and position: ";
                cin >> val >> pos;
                list.insert(val, pos);
                break;
            case 2:  // Remove loop
                list.removeLoop();
                break;
            case 3:  // Find nth from end
                cout << "Enter n: ";
                cin >> pos;
                list.nthFromEnd(pos);
                break;
            case 4:  // Reverse in groups
                cout << "Enter k: ";
                cin >> pos;
                list.reverseGroups(pos);
                break;
            case 5:  // Display list
                list.display();
                break;
            case 6:  // Exit program
                return 0;
            default:  // Invalid choice
                cout << "Invalid choice\n";
        }
    }
}
