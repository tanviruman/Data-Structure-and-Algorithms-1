/*
6. Reverse a doubly linked list.
   Input:  7 <-> 12 <-> -8 <-> 65 <-> 10
   Output: 10 <-> 65 <-> -8 <-> 12 <-> 7
*/

#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;         // Holds the data
    Node* prev;       // Pointer to the previous node
    Node* next;       // Pointer to the next node

    // Constructor to initialize the node
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Function to reverse the doubly linked list
void reverseDoublyLinkedList(Node*& head) {
    Node* current = head; // Pointer to traverse the list
    Node* temp = nullptr; // Temporary pointer to swap prev and next

    // Traverse the list and swap next and prev pointers
    while (current != nullptr) {
        temp = current->prev;       // Store the previous pointer
        current->prev = current->next; // Swap prev and next
        current->next = temp;       // Update next with the stored value
        current = current->prev;    // Move to the next node (which is the old previous node)
    }

    // Update the head to the new front of the list
    if (temp != nullptr) {
        head = temp->prev; // After the loop, temp points to the new head's next node
    }
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* current = head; // Pointer to traverse the list
    while (current != nullptr) {
        cout << current->data; // Print the current node's data
        if (current->next != nullptr) {
            cout << " <-> "; // Print separator for nodes
        }
        current = current->next; // Move to the next node
    }
    cout << endl; // End of the list
}

// Function to create a doubly linked list based on user input
Node* createList(int n) {
    if (n <= 0) {
        return nullptr;
    }

    int value;
    cout << "Enter the value for node 1: ";
    cin >> value;

    Node* head = new Node(value); // Create the head node
    Node* current = head;         // Pointer to keep track of the last node

    for (int i = 2; i <= n; i++) {
        cout << "Enter the value for node " << i << ": ";
        cin >> value;

        Node* newNode = new Node(value); // Create a new node
        current->next = newNode;         // Link the current node to the new node
        newNode->prev = current;         // Link the new node to the current node
        current = newNode;               // Move to the new node
    }

    return head; // Return the head of the list
}

// Main function
int main() {
    int n;
    cout << "Enter the number of nodes in the list: ";
    cin >> n;

    // Create the doubly linked list
    Node* head = createList(n);

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Reverse the doubly linked list
    reverseDoublyLinkedList(head);

    // Print the reversed list
    cout << "Reversed list: ";
    printList(head);

    return 0;
}
