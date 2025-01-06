// Question:
// Delete all the even numbers from a linked list.
// Example:
// Input: 1 -> 4 -> 6 -> 7 -> 9 -> 11
// Output: 1 -> 7 -> 9 -> 11

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

// Function to delete all even numbers from the linked list
void deleteEvens(Node*& head) {
    // Handle the case where the head contains even numbers
    while (head != nullptr && head->data % 2 == 0) {
        Node* temp = head; // Store the current head
        head = head->next; // Move the head to the next node
        delete temp; // Delete the old head
    }

    // Traverse the list to remove even nodes
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data % 2 == 0) { // If the next node is even
            Node* temp = current->next; // Store the node to be deleted
            current->next = current->next->next; // Skip the even node
            delete temp; // Delete the even node
        } else {
            current = current->next; // Move to the next node
        }
    }
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
    // Create the linked list from user input
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n == 0) {
        cout << "The list is empty!" << endl;
        return 0;
    }

    Node* head = nullptr; // Initialize the head of the linked list
    Node* tail = nullptr; // Keep track of the last node

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

    cout << "Original list: ";
    printList(head); // Print the original list

    cout << "Deleting all even numbers from the list...\n";

    deleteEvens(head); // Delete all even numbers from the list

    cout << "Updated list: ";
    printList(head); // Print the updated list

    return 0;
}
