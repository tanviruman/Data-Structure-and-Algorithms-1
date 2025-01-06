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
    // Input the number of nodes for the linked list
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    Node* head = nullptr; // Initialize the head for the linked list
    Node* tail = nullptr; // To keep track of the last node in the list

    cout << "Enter the values for the linked list: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value; // Input the value for the current node
        Node* newNode = createNode(value); // Create a new node with the input value

        if (head == nullptr) {
            head = newNode; // Set the first node as the head
        } else {
            tail->next = newNode; // Append the new node to the end
        }
        tail = newNode; // Update the tail to the new node
    }

    // Calculate and print the size of the linked list
    cout << "Size of the linked list: " << getSize(head) << endl;

    return 0; // End of the program
}
