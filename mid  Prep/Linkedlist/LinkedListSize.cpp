// Question:
// Print the size of a linked list.
// Input: 34->12->55->42->11
// Output: 5

#include <iostream> // Include necessary library for input/output operations
using namespace std; // Use the standard namespace

// Define a Node structure for the linked list
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node
};

// Function to create a new node and return its pointer
Node* createNode(int value) {
    Node* newNode = new Node(); // Allocate memory for a new node
    newNode->data = value;      // Assign the value to the node
    newNode->next = nullptr;    // Set the next pointer to null (no next node yet)
    return newNode;             // Return the pointer to the new node
}

// Function to calculate the size of the linked list
int getSize(Node* head) {
    int count = 0;       // Initialize a counter for the size
    Node* current = head; // Start traversing from the head node

    // Traverse the linked list until the end
    while (current != nullptr) {
        count++;            // Increment the counter for each node
        current = current->next; // Move to the next node
    }

    return count; // Return the total count (size of the linked list)
}

int main() {
    // Create the linked list with the given input: 34->12->55->42->11
    Node* head = createNode(34); // Create the head node with data 34
    head->next = createNode(12); // Link the second node with data 12
    head->next->next = createNode(55); // Link the third node with data 55
    head->next->next->next = createNode(42); // Link the fourth node with data 42
    head->next->next->next->next = createNode(11); // Link the fifth node with data 11

    // Calculate and print the size of the linked list
    cout << "Size of the linked list: " << getSize(head) << endl;

    return 0; // End of the program
}
