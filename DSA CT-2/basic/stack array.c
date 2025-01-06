#include<stdio.h> // Include standard input/output header for I/O operations

// Define a global array to act as the stack
int arr[200]; // Array to store stack elements
int top = -1; // Variable to track the top index of the stack; -1 indicates the stack is empty
int size = 5; // Maximum size of the stack

// Function to push a value onto the stack
void push(int value) {
    if (top == size - 1) { // Check if the stack is full (overflow condition)
        printf("Stack Overflow\n"); // Print overflow message
        return; // Exit the function if the stack is full
    }
    top++; // Increment the top index to add a new element
    arr[top] = value; // Store the value at the new top position
    printf("Value %d pushed to the stack.\n", value); // Confirm the value was pushed
}

// Function to pop a value from the stack
int pop() {
    if (top == -1) { // Check if the stack is empty (underflow condition)
        printf("Stack Underflow\n"); // Print underflow message
        return -1; // Return -1 to indicate failure
    }
    int y = arr[top]; // Retrieve the value at the top of the stack
    top--; // Decrement the top index to remove the top element
    printf("Value %d popped from the stack.\n", y); // Confirm the value was popped
    return y; // Return the popped value
}

// Function to print the current elements of the stack
void printStack() {
    if (top == -1) { // Check if the stack is empty
        printf("Stack is empty.\n"); // Print an empty stack message
    } else {
        for (int i = 0; i <= top; i++) { // Iterate through the stack from bottom to top
            printf("%d ", arr[i]); // Print each element of the stack
        }
        printf("\n"); // Move to the next line after printing all elements
    }
}

int main() {
    int choice, value; // Variables for menu choice and stack value

    // Menu-driven program to perform stack operations
    do {
        printf("\nChoose an option:\n"); // Print the menu
        printf("1. Push\n"); // Option to push an element onto the stack
        printf("2. Pop\n"); // Option to pop an element from the stack
        printf("3. Print Stack\n"); // Option to print the stack
        printf("4. Exit\n"); // Option to exit the program
        printf("Enter your choice: "); // Prompt the user for their choice
        scanf("%d", &choice); // Read the user's choice

        if (choice == 1) { // If the choice is 1 (push operation)
            printf("Enter the value to push: "); // Prompt for the value to push
            scanf("%d", &value); // Read the value from the user
            push(value); // Call the push function with the input value
        } else if (choice == 2) { // If the choice is 2 (pop operation)
            pop(); // Call the pop function
        } else if (choice == 3) { // If the choice is 3 (print stack)
            printStack(); // Call the printStack function
        } else if (choice == 4) { // If the choice is 4 (exit)
            printf("Exiting...\n"); // Print exit message
        } else { // If the choice is invalid
            printf("Invalid choice. Please try again.\n"); // Print error message
        }
    } while (choice != 4); // Repeat the menu until the user chooses to exit

    return 0; // Indicate successful program termination
}
