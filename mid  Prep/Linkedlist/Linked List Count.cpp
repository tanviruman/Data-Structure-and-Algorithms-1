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
    // Input the number of nodes in the linked list
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    Node* head = nullptr; // Initialize the head of the linked list
    Node* tail = nullptr; // Keep track of the last node

    // Input the node values from the user
    cout << "Enter the node values: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        Node* newNode = createNode(value); // Create a new node with the user input

        if (head == nullptr) {
            head = newNode; // Set the first node as the head
        } else {
            tail->next = newNode; // Append the new node to the end
        }
        tail = newNode; // Update the tail to the new node
    }

    // Input the number to count occurrences of
    int num;
    cout << "Enter the number to count occurrences of: ";
    cin >> num;

    // Calculate and print the number of occurrences of the given number
    cout << "Number of occurrences of " << num << ": " << countOccurrences(head, num) << endl;

    return 0; // End of the program
}
