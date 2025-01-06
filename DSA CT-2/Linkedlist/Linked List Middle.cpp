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
    // Input the number of nodes for the first linked list
    int n1;
    cout << "Enter the number of nodes in the first linked list: ";
    cin >> n1;

    Node* head1 = nullptr; // Initialize the head for the first linked list
    Node* tail1 = nullptr; // To keep track of the last node in the list

    cout << "Enter the values for the first linked list: ";
    for (int i = 0; i < n1; i++) {
        int value;
        cin >> value;
        Node* newNode = createNode(value); // Create a new node with user input

        if (head1 == nullptr) {
            head1 = newNode; // Set the first node as the head
        } else {
            tail1->next = newNode; // Append the new node to the end
        }
        tail1 = newNode; // Update the tail to the new node
    }

    // Print the middle node of the first linked list
    printMiddle(head1);

    // Input the number of nodes for the second linked list
    int n2;
    cout << "Enter the number of nodes in the second linked list: ";
    cin >> n2;

    Node* head2 = nullptr; // Initialize the head for the second linked list
    Node* tail2 = nullptr; // To keep track of the last node in the list

    cout << "Enter the values for the second linked list: ";
    for (int i = 0; i < n2; i++) {
        int value;
        cin >> value;
        Node* newNode = createNode(value); // Create a new node with user input

        if (head2 == nullptr) {
            head2 = newNode; // Set the first node as the head
        } else {
            tail2->next = newNode; // Append the new node to the end
        }
        tail2 = newNode; // Update the tail to the new node
    }

    // Print the middle node of the second linked list
    printMiddle(head2);

    return 0; // End of the program
}
