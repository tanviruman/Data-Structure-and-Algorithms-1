#include <iostream>  // For input and output operations
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
    Node* newNode = new Node(); // Create a new node
    newNode->data = value;      // Store the character in the new node
    newNode->next = top;        // Link the new node to the current top
    top = newNode;              // Update the top pointer
}

// Function to pop a character from the stack
char pop() {
    if (top == NULL) {          // Check if the stack is empty
        return '\0';            // Return null character if stack is empty
    }
    char value = top->data;     // Get the character from the top node
    Node* temp = top;           // Temporary pointer to the top node
    top = top->next;            // Move the top pointer to the next node
    delete temp;                // Free the memory of the old top node
    return value;               // Return the popped character
}

// Function to convert uppercase characters to lowercase
char toLowercase(char c) {
    if (c >= 'A' && c <= 'Z') { // If the character is uppercase
        return c + 32;          // Convert to lowercase
    }
    return c;                   // Return the character as is if it's already lowercase
}

// Function to check if a character is alphabetic
bool isAlphabetic(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); // Check if the character is in the alphabet range
}

// Function to check if a given string is a palindrome
bool isPalindrome(string str) {
    // Step 1: Process the input string and push alphabetic characters onto the stack
    for (int i = 0; str[i] != '\0'; i++) { // Loop through each character in the string
        char c = str[i];                   // Get the current character
        if (isAlphabetic(c)) {             // Check if the character is alphabetic
            push(toLowercase(c));          // Convert to lowercase and push onto the stack
        }
    }

    // Step 2: Verify the palindrome property
    for (int i = 0; str[i] != '\0'; i++) { // Loop through the string again
        char c = str[i];                   // Get the current character
        if (isAlphabetic(c)) {             // Check if the character is alphabetic
            c = toLowercase(c);            // Convert to lowercase
            char topChar = pop();          // Pop the top character from the stack
            if (c != topChar) {            // Compare the characters
                return false;              // If mismatch, return false
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
