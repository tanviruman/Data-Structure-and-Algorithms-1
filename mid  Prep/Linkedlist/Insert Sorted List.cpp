// Question:
// Given a sorted linked list, insert a number so that after insertion, it remains sorted.
// Example:
// Input: 1 -> 4 -> 6 -> 7 -> 9 -> 11, num = 3
// Output: 1 -> 3 -> 4 -> 6 -> 7 -> 9 -> 11

#include <iostream>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data; // Data part of the node
    Node* next; // Pointer to the next node
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr; // Initially, the next pointer is set to null
    return newNode;
}

// Function to insert a number into a sorted linked list
void insertSorted(Node*& head, int num) {
    Node* newNode = createNode(num); // Create a new node with the given number

    // If the list is empty or the number should be inserted at the beginning
    if (head == nullptr || head->data >= num) {
        newNode->next = head; // Point the new node to the current head
        head = newNode; // Update the head to the new node
        return;
    }

    // Traverse the list to find the correct insertion point
    Node* current = head;
    while (current->next != nullptr && current->next->data < num) {
        current = current->next; // Move to the next node
    }

    // Insert the new node at the correct position
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> "; // Print an arrow if there's a next node
        }
        temp = temp->next; // Move to the next node
    }
    cout << endl;
}

int main() {
    // Input the number of nodes and their values from the user
    int n;
    cout << "Enter the number of nodes in the sorted linked list: ";
    cin >> n;

    Node* head = nullptr; // Initialize the head of the linked list
    Node* tail = nullptr; // Keep track of the last node

    cout << "Enter the node values in sorted order: ";
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

    cout << "Original list: ";
    printList(head); // Print the original list

    // Input the number to insert
    int num;
    cout << "Enter the number to insert into the sorted list: ";
    cin >> num;

    cout << "Inserting " << num << " into the sorted list...\n";

    insertSorted(head, num); // Insert the number into the sorted list

    cout << "Updated list: ";
    printList(head); // Print the updated list

    return 0;
}
