// Question:
// Print the number of occurrences of a given number in a linked list.
// Input: 1->2->1->2->1->3->1, num = 1
// Output: 4

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

// Function to count the occurrences of a given number in the linked list
int countOccurrences(Node* head, int num) {
    int count = 0;       // Initialize a counter for occurrences
    Node* current = head; // Start traversing from the head node

    // Traverse the linked list
    while (current != nullptr) {
        if (current->data == num) { // Check if the current node's data matches the given number
            count++; // Increment the counter if it matches
        }
        current = current->next; // Move to the next node
    }

    return count; // Return the total count of occurrences
}

int main() {
    // Create the linked list with the given input: 1->2->1->2->1->3->1
    Node* head = createNode(1); // Create the head node with data 1
    head->next = createNode(2); // Link the second node with data 2
    head->next->next = createNode(1); // Link the third node with data 1
    head->next->next->next = createNode(2); // Link the fourth node with data 2
    head->next->next->next->next = createNode(1); // Link the fifth node with data 1
    head->next->next->next->next->next = createNode(3); // Link the sixth node with data 3
    head->next->next->next->next->next->next = createNode(1); // Link the seventh node with data 1

    int num = 1; // The number to count occurrences of

    // Calculate and print the number of occurrences of the given number
    cout << "Number of occurrences of " << num << ": " << countOccurrences(head, num) << endl;

    return 0; // End of the program
}
