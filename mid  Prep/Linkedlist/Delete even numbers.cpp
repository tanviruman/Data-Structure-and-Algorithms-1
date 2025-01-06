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
    // Create the initial linked list
    Node* head = createNode(1);
    head->next = createNode(4);
    head->next->next = createNode(6);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(9);
    head->next->next->next->next->next = createNode(11);

    cout << "Original list: ";
    printList(head); // Print the original list

    cout << "Deleting all even numbers from the list...\n";

    deleteEvens(head); // Delete all even numbers from the list

    cout << "Updated list: ";
    printList(head); // Print the updated list

    return 0;
}
