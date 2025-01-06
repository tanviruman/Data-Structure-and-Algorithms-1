#include <iostream>  // Include necessary library for input/output operations
#include <cctype>    // Include library for character functions like isalpha and tolower
using namespace std; // Use the standard namespace

// Define a Node structure for the custom stack
struct Node {
    char data;        // Data part of the node (stores a character)
    Node* next;       // Pointer to the next node
};

// Global pointer to the top of the stack
Node* top = NULL;

// Function to push a character onto the stack
void push(char value) {
    Node* newNode = new Node(); // Allocate memory for a new node
    newNode->data = value;      // Assign the value to the new node
    newNode->next = top;        // Link the new node to the current top node
    top = newNode;              // Update the top pointer to the new node
}

// Function to pop a character from the stack
char pop() {
    if (top == NULL) {          // Check if the stack is empty
        return '\0';            // Return null character if stack is empty
    }
    char value = top->data;     // Get the character from the top node
    Node* temp = top;           // Temporary pointer to the top node
    top = top->next;            // Update the top pointer to the next node
    delete temp;                // Free memory of the old top node
    return value;               // Return the popped character
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == NULL;
}

// Function to check if a given string is a palindrome
bool isPalindrome(string str) {
    // Step 1: Process the input string
    for (char c : str) {
        if (isalpha(c)) {           // Check if the character is alphabetic
            c = tolower(c);         // Convert the character to lowercase
            push(c);                // Push the character onto the stack
        }
    }

    // Step 2: Verify the palindrome property
    for (char c : str) {
        if (isalpha(c)) {           // Check if the character is alphabetic
            c = tolower(c);         // Convert the character to lowercase
            char topChar = pop();   // Pop the top character from the stack
            if (c != topChar) {     // Compare the characters
                return false;       // If mismatch, return false
            }
        }
    }

    return true; // If all characters match, the string is a palindrome
}

int main() {
    string input; // Declare a string variable to store user input

    // Prompt the user to enter a string
    cout << "Enter a string to check if it is a palindrome: ";
    getline(cin, input); // Read the entire line (string) from the user

    // Call the isPalindrome function and display the result
    if (isPalindrome(input)) {
        cout << "Palindrome" << endl; // If true, the string is a palindrome
    } else {
        cout << "Not a Palindrome" << endl; // Otherwise, it is not a palindrome
    }

    return 0; // End of the program
}
