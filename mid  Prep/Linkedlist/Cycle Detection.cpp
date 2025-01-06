/*
10. Given the head of a linked list, determine if the linked list has a cycle in it.

Input:
3 -> 2 -> 0 -> 4
        |     
        6 <---

Output: YES

Input:
3 -> 2 -> 0 -> 4 -> NULL

Output: NO
*/

#include <iostream>
using namespace std;

// Definition for the Node structure
struct Node {
    int data;      // Data in the node
    Node* next;    // Pointer to the next node
};

// Function to check if there is a cycle in the linked list
bool hasCycle(Node* head) {
    Node* slow = head; // Slow pointer
    Node* fast = head; // Fast pointer

    // Traverse the linked list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow pointer by one step
        fast = fast->next->next;    // Move fast pointer by two steps

        if (slow == fast) {         // If slow and fast pointers meet, cycle exists
            return true;
        }
    }

    return false; // No cycle found
}

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node(); // Allocate memory for the new node
    newNode->data = value;      // Assign the value
    newNode->next = NULL;       // Initialize the next pointer to NULL
    return newNode;
}

int main() {
    // Input to create the linked list
    int n, cyclePos;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    if (n == 0) {
        cout << "NO" << endl;
        return 0;
    }

    Node* head = NULL; // Head of the linked list
    Node* tail = NULL; // Tail of the linked list

    cout << "Enter the node values: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = createNode(value); // Create a new node

        if (head == NULL) {
            head = newNode; // Set the head for the first node
        } else {
            tail->next = newNode; // Link the new node to the previous node
        }
        tail = newNode; // Update the tail
    }

    cout << "Enter the position to create a cycle (-1 for no cycle): ";
    cin >> cyclePos;

    if (cyclePos != -1) {
        Node* cycleNode = head;
        for (int i = 0; i < cyclePos; i++) {
            cycleNode = cycleNode->next; // Navigate to the node at cyclePos
        }
        tail->next = cycleNode; // Create the cycle
    }

    // Check if the linked list has a cycle
    if (hasCycle(head)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
