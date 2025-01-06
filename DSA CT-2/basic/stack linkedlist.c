#include <stdio.h> // Include standard input/output library for I/O operations
#include <stdlib.h> // Include standard library for memory allocation and other utilities

// Define a structure for the stack node
struct Node {
    int data;              // Data part of the node
    struct Node* next;     // Pointer to the next node
};

// Global pointer for the top of the stack
struct Node* top = NULL; // Initially, the stack is empty

// Function to push a value onto the stack
void push(int value) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) { // Check if memory allocation fails
        printf("Memory allocation failed. Stack Overflow.\n");
        return; // Exit the function if allocation fails
    }
    newNode->data = value; // Assign the value to the new node
    newNode->next = top;   // Link the new node to the current top node
    top = newNode;         // Update the top pointer to the new node
    printf("Value %d pushed to the stack.\n", value); // Confirm the value is pushed
}

// Function to pop a value from the stack
int pop() {
    if (top == NULL) { // Check if the stack is empty
        printf("Stack Underflow.\n"); // Print underflow message
        return -1; // Return -1 to indicate failure
    }
    int value = top->data; // Store the value of the top node
    struct Node* temp = top; // Temporary pointer to the current top node
    top = top->next; // Update the top pointer to the next node
    free(temp); // Free the memory of the old top node
    printf("Value %d popped from the stack.\n", value); // Confirm the value is popped
    return value; // Return the popped value
}

// Function to print all elements of the stack
void printStack() {
    if (top == NULL) { // Check if the stack is empty
        printf("Stack is empty.\n"); // Print empty stack message
        return; // Exit the function
    }
    struct Node* current = top; // Start from the top of the stack
    printf("Stack elements:\n");
    while (current != NULL) { // Traverse the stack until the end
        printf("%d ", current->data); // Print the data of the current node
        current = current->next; // Move to the next node
    }
    printf("\n"); // Move to the next line after printing all elements
}

// Main function to provide a menu-driven interface
int main() {
    int choice, value; // Variables for user input

    // Display a menu for stack operations
    do {
        printf("\nChoose an option:\n");
        printf("1. Push\n"); // Option to push a value onto the stack
        printf("2. Pop\n");  // Option to pop a value from the stack
        printf("3. Print Stack\n"); // Option to print the stack
        printf("4. Exit\n"); // Option to exit the program
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read the user's choice

        if (choice == 1) { // If the choice is 1 (Push operation)
            printf("Enter the value to push: "); // Prompt the user for a value
            scanf("%d", &value); // Read the value
            push(value); // Call the push function to add the value to the stack
        } else if (choice == 2) { // If the choice is 2 (Pop operation)
            pop(); // Call the pop function to remove the top value from the stack
        } else if (choice == 3) { // If the choice is 3 (Print stack)
            printStack(); // Call the printStack function to display all stack elements
        } else if (choice == 4) { // If the choice is 4 (Exit)
            printf("Exiting...\n"); // Print exit message
        } else { // If the choice is invalid
            printf("Invalid choice. Please try again.\n"); // Print an error message
        }
    } while (choice != 4); // Repeat the menu until the user chooses to exit

    return 0; // Indicate successful program termination
}
