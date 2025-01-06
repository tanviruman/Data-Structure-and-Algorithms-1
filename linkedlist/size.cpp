//Print the size of a linked list.
#include <iostream> 
// Includes the standard input-output stream library for input (cin) and output (cout).

#include <cstdlib> 
// Includes the C Standard General Utilities Library, which provides the `malloc` function for memory allocation.

#include <cctype> 
// Includes the C Standard Library for character handling (not used in this code).

using namespace std; 
// Allows the use of standard library names (e.g., cout, cin) without the "std::" prefix.

struct list { 
    int data; 
    // Integer field to store the data of the node.

    struct list *next; 
    // Pointer to the next node in the linked list.
};
typedef struct list node; 
// Creates an alias `node` for `struct list` to simplify usage in the code.

void display(node* head) { 
    // Function to display the data of the linked list and count its size.
    
    int count = 0; 
    // Variable to count the number of nodes in the linked list.

    node* temp; 
    // Temporary pointer to traverse the linked list.

    temp = head; 
    // Initialize the temporary pointer to the head of the linked list.

    while (temp != NULL) { 
        // Loop until the end of the linked list (NULL).
        
        count++; 
        // Increment the counter for each node.

        cout << " " << temp->data; 
        // Print the data of the current node.

        temp = temp->next; 
        // Move to the next node in the linked list.
    }
    
    cout << " "; 
    // Print a space for better formatting.

    cout << " size of linked list:" << count; 
    // Print the total number of nodes in the linked list.
}

int main() { 
    // Entry point of the program.
    
    node *head, *temp, *prev; 
    // Declare pointers for the linked list:
    // - `head` points to the first node.
    // - `temp` is used for creating new nodes.
    // - `prev` keeps track of the previous node to link the new node.

    head = (node*)malloc(sizeof(node)); 
    // Dynamically allocate memory for the first node.

    int i, value; 
    // Declare variables:
    // - `i` is used for the loop.
    // - `value` stores the data input by the user.

    head->data = 10; 
    // Assign 10 to the data field of the first node.

    head->next = NULL; 
    // Initialize the next pointer of the first node to NULL (end of the list).

    prev = head; 
    // Initialize `prev` to point to the first node.

    for (i = 2; i <= 6; i++) { 
        // Loop to create 5 additional nodes (2nd to 6th nodes).
        
        temp = (node*)malloc(sizeof(node)); 
        // Dynamically allocate memory for a new node.

        cin >> value; 
        // Take input from the user for the data of the new node.

        temp->data = value; 
        // Assign the user input value to the data field of the new node.

        temp->next = NULL; 
        // Set the next pointer of the new node to NULL (end of the list).

        prev->next = temp; 
        // Link the previous node to the new node.

        prev = temp; 
        // Update `prev` to point to the new node (making it the last node).
    }
    
    display(head); 
    // Call the `display` function to print the linked list and its size.

    return 0; 
    // Return 0 to indicate successful program execution.
}
