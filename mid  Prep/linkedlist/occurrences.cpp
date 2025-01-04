//Print the number of occurrences of a given number in a linked list.

#include <iostream>
using namespace std;

// Structure to represent a node in the linked list
struct Node {
    int data;   // Stores the data value
    Node* next; // Pointer to the next node
};

// Function to display the linked list
void display(Node* head) {
    Node* temp = head; // Start from the head node
    while (temp != nullptr) { 
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->next;         // Move to the next node
    }
    cout << endl; // Print a newline for better readability
}

// Function to count and display the number of occurrences of a given value
void countOccurrences(Node* head, int value) {
    Node* temp = head; // Start from the head node
    int count = 0;     // Initialize the count to 0

    while (temp != nullptr) { 
        if (temp->data == value) { 
            count++; // Increment count if the value matches
        }
        temp = temp->next; // Move to the next node
    }
    cout << "Number of occurrences of " << value << ": " << count << endl;
}

int main() {
    // Creating the linked list
    Node* head = nullptr;
    Node* temp = nullptr;
    Node* prev = nullptr;

    // Dynamically allocate memory for the head node
    head = new Node();
    head->data = 12;      // Assign data to the head node
    head->next = nullptr; // Initialize the next pointer
    prev = head;          // Set prev to point to the head

    // Create additional nodes
    int value;
    for (int i = 0; i < 5; i++) { 
        cout << "Enter value for node " << i + 2 << ": ";
        cin >> value;

        temp = new Node(); // Dynamically allocate memory for a new node
        temp->data = value; // Assign user input to the node
        temp->next = nullptr; // Set the next pointer to nullptr
        prev->next = temp;    // Link the previous node to the new node
        prev = temp;          // Update prev to point to the new node
    }

    // Display the linked list
    cout << "Linked List: ";
    display(head);

    // Count the occurrences of the value 1 in the linked list
    countOccurrences(head, 1);

    // Free the allocated memory
    while (head != nullptr) {
        Node* toDelete = head; // Save the current node
        head = head->next;     // Move to the next node
        delete toDelete;       // Delete the current node
    }

    return 0;
}
