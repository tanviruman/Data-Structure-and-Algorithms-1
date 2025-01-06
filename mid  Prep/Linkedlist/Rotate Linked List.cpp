/*
8. Given a singly linked list and an integer k, rotate the linked list to the left by k places.
Input:
10->20->30->40->50, k = 4
Output:
50->10->20->30->40
*/

#include <iostream>
using namespace std;

// Define a structure for a node in the linked list
struct Node {
    int data; // Data part of the node
    Node* next; // Pointer to the next node
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr; // Initialize the next pointer to nullptr
    return newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

// Function to rotate the linked list to the left by k places
Node* rotateLeft(Node* head, int k) {
    if (!head || k <= 0) {
        return head; // If the list is empty or k is invalid, return the original list
    }

    // Find the length of the linked list
    Node* temp = head;
    int length = 1;
    while (temp->next != nullptr) {
        temp = temp->next;
        length++;
    }

    // Connect the last node to the head to form a circular linked list
    temp->next = head;

    // Find the new head position after k rotations
    k = k % length; // Handle cases where k is greater than the length of the list
    int stepsToNewHead = length - k;

    // Move to the new head and break the loop
    temp = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        temp = temp->next;
    }

    head = temp->next; // New head
    temp->next = nullptr; // Break the loop

    return head;
}

int main() {
    // Input the linked list from the user
    int n, k;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "The list cannot have zero or negative nodes." << endl;
        return 0;
    }

    cout << "Enter the elements of the linked list: ";
    int data;
    cin >> data;

    // Create the linked list
    Node* head = createNode(data);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> data;
        tail->next = createNode(data);
        tail = tail->next;
    }

    cout << "Enter the value of k: ";
    cin >> k;

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Rotate the list
    head = rotateLeft(head, k);

    // Print the rotated list
    cout << "Rotated list: ";
    printList(head);

    return 0;
}
