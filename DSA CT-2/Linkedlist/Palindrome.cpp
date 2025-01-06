#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
};

// Function to insert a node at the end of the list
void insertNode(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    // Step 1: Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    Node* prev = nullptr;
    Node* curr = slow;
    Node* nextNode;
    while (curr != nullptr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Step 3: Compare the two halves
    Node* firstHalf = head;
    Node* secondHalf = prev; // prev now points to the head of the reversed second half
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

// Main function
int main() {
    /*
    9. Given a singly linked list, print "YES" if it is a palindrome otherwise print "NO".
    Example:
        Input: 1->2->2->1  Output: YES
        Input: 1->2->3->1  Output: NO
    */
    
    Node* head = nullptr; // Initialize an empty linked list

    cout << "Enter the number of elements in the linked list: ";
    int n;
    cin >> n;

    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        insertNode(head, value);
    }

    // Check if the linked list is a palindrome and print the result
    if (isPalindrome(head)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
