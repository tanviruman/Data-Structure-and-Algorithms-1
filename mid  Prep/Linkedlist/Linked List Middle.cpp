// Question:
// Given the head of a linked list, print the value of the middle node.
// Input: 34->12->55->42->11
// Output: 55
// Input: 12->8->65->10
// Output: 8

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

// Function to find and print the middle node's value
void printMiddle(Node* head) {
    Node* slow = head; // Slow pointer, moves one step at a time
    Node* fast = head; // Fast pointer, moves two steps at a time

    // Traverse the list with the two pointers
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps
    }

    // When fast reaches the end, slow is at the middle
    if (slow != nullptr) {
        cout << "Middle node value: " << slow->data << endl;
    }
}

int main() {
    // Create the linked list for the first input: 34->12->55->42->11
    Node* head1 = createNode(34); // Create the head node with data 34
    head1->next = createNode(12); // Link the second node with data 12
    head1->next->next = createNode(55); // Link the third node with data 55
    head1->next->next->next = createNode(42); // Link the fourth node with data 42
    head1->next->next->next->next = createNode(11); // Link the fifth node with data 11

    // Print the middle node of the first linked list
    printMiddle(head1);

    // Create the linked list for the second input: 12->8->65->10
    Node* head2 = createNode(12); // Create the head node with data 12
    head2->next = createNode(8);  // Link the second node with data 8
    head2->next->next = createNode(65); // Link the third node with data 65
    head2->next->next->next = createNode(10); // Link the fourth node with data 10

    // Print the middle node of the second linked list
    printMiddle(head2);

    return 0; // End of the program
}
