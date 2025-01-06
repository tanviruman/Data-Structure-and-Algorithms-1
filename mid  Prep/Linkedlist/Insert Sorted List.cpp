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
    // Create the initial sorted linked list
    Node* head = createNode(1);
    head->next = createNode(4);
    head->next->next = createNode(6);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(9);
    head->next->next->next->next->next = createNode(11);

    cout << "Original list: ";
    printList(head); // Print the original list

    int num = 3; // Number to insert
    cout << "Inserting " << num << " into the sorted list...\n";

    insertSorted(head, num); // Insert the number into the sorted list

    cout << "Updated list: ";
    printList(head); // Print the updated list

    return 0;
}
