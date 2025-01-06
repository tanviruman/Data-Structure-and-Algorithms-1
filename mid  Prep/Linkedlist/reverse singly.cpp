// Question: Reverse a singly linked list.
// Input: 7 -> 12 -> 8 -> 65 -> 10
// Output: 10 -> 65 -> 8 -> 12 -> 7

#include <iostream>
using namespace std;

// Definition of a node in the linked list
struct Node {
    int data; // Data part of the node
    Node* next; // Pointer to the next node

    Node(int value) { // Constructor to initialize a new node
        data = value;
        next = nullptr;
    }
};

// Function to reverse the linked list
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr; // Previous node pointer initialized to nullptr
    Node* current = head; // Current node pointer starts at the head of the list
    Node* nextNode = nullptr; // Next node pointer

    while (current != nullptr) { // Traverse the list until the end
        nextNode = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current; // Move the previous pointer to the current node
        current = nextNode; // Move to the next node
    }

    return prev; // New head of the reversed list
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> "; // Print arrow between nodes
        }
        temp = temp->next; // Move to the next node
    }
    cout << endl;
}

int main() {
    cout << "Enter the number of nodes in the linked list: ";
    int n;
    cin >> n; // Number of nodes in the list

    if (n <= 0) {
        cout << "Invalid number of nodes!" << endl;
        return 0;
    }

    cout << "Enter the values of the nodes: " << endl;
    int value;
    cin >> value; // Input the first node value

    // Create the head of the linked list
    Node* head = new Node(value);
    Node* tail = head; // Tail pointer to keep track of the last node

    // Create the rest of the linked list
    for (int i = 1; i < n; i++) {
        cin >> value; // Input next node value
        tail->next = new Node(value); // Create a new node and link it
        tail = tail->next; // Move the tail to the new node
    }

    cout << "Original linked list: ";
    printLinkedList(head); // Print the original list

    head = reverseLinkedList(head); // Reverse the linked list

    cout << "Reversed linked list: ";
    printLinkedList(head); // Print the reversed list

    return 0;
}
