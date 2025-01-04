#include <stdio.h>
#include <stdlib.h>

// Define Node structure for Doubly Linked List
struct Node {
    int val;               // Value stored in the node
    struct Node *prev;     // Pointer to the previous node
    struct Node *next;     // Pointer to the next node
};

struct Node *head = NULL;  // Global head pointer, initially NULL

// Insert a Node at the beginning of the Doubly Linked List
void insertHead(int value) {
    struct Node *newNode = malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->val = value;    // Assign the value to the node
    newNode->prev = NULL;    // New node's prev pointer is NULL
    newNode->next = head;    // New node's next points to the current head

    if (head != NULL) {      // If the list is not empty, update head's prev pointer
        head->prev = newNode;
    }
    head = newNode;          // Update head to point to the new node
}

// Insert a Node at the end of the Doubly Linked List
void insertTail(int value) {
    struct Node *newNode = malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->val = value;    // Assign the value to the node
    newNode->next = NULL;    // New node's next pointer is NULL

    if (head == NULL) {      // If the list is empty
        newNode->prev = NULL; // Set prev to NULL
        head = newNode;       // Update head to the new node
    } else {
        struct Node *traveller = head; // Start from head
        while (traveller->next != NULL) { // Traverse to the last node
            traveller = traveller->next;
        }
        traveller->next = newNode; // Attach the new node at the end
        newNode->prev = traveller; // Update the new node's prev to the last node
    }
}

// Insert a Node after a specific value
void insertAfter(int oldValue, int newValue) {
    struct Node *traveller = head; // Start from head

    while (traveller != NULL) {    // Traverse the list
        if (traveller->val == oldValue) {
            break; // Stop if the specified value is found
        }
        traveller = traveller->next;
    }

    if (traveller == NULL) {       // If the specified value is not found
        printf("The value %d does not exist!\n", oldValue);
    } else {
        struct Node *newNode = malloc(sizeof(struct Node)); // Allocate memory for the new node
        newNode->val = newValue; // Assign the value to the new node
        newNode->next = traveller->next; // New node's next points to traveller's next
        newNode->prev = traveller;       // New node's prev points to traveller

        if (traveller->next != NULL) {   // If traveller is not the last node
            traveller->next->prev = newNode; // Update next node's prev pointer
        }
        traveller->next = newNode;       // Update traveller's next pointer
    }
}

// Delete the head node
void deleteHead() {
    if (head == NULL) {                 // Check if the list is empty
        printf("The list is empty, nothing to delete!\n");
        return;
    }

    struct Node *temp = head;           // Store the head node temporarily
    head = head->next;                  // Update head to the next node

    if (head != NULL) {                 // If the list is not empty after update
        head->prev = NULL;              // Set the new head's prev to NULL
    }

    free(temp);                         // Free memory of the old head
}

// Delete the tail node
void deleteTail() {
    if (head == NULL) {                 // Check if the list is empty
        printf("The list is empty, nothing to delete!\n");
        return;
    }

    if (head->next == NULL) {           // If there's only one node in the list
        free(head);                     // Free the single node
        head = NULL;                    // Update head to NULL
        return;
    }

    struct Node *traveller = head;      // Start from head
    while (traveller->next != NULL) {   // Traverse to the last node
        traveller = traveller->next;
    }

    traveller->prev->next = NULL;       // Update second last node's next to NULL
    free(traveller);                    // Free the last node
}

// Delete a node after a specific value
void deleteAfter(int oldValue) {
    struct Node *traveller = head;      // Start from head

    while (traveller != NULL && traveller->val != oldValue) { // Traverse to find the specified value
        traveller = traveller->next;
    }

    if (traveller == NULL || traveller->next == NULL) { // If the value doesn't exist or is the last node
        printf("Cannot delete after %d as it doesn't exist or is the last node!\n", oldValue);
    } else {
        struct Node *temp = traveller->next; // Temporarily store the node to be deleted
        traveller->next = temp->next;       // Update traveller's next to skip the deleted node

        if (temp->next != NULL) {           // If temp is not the last node
            temp->next->prev = traveller;   // Update next node's prev pointer
        }
        free(temp);                         // Free memory of the deleted node
    }
}

// Print the Doubly Linked List
void printLinkedList() {
    printf("Doubly linked list: ");
    struct Node *traveller = head;          // Start from head

    while (traveller != NULL) {             // Traverse the list
        printf("%d <-> ", traveller->val);  // Print the value of the current node
        traveller = traveller->next;        // Move to the next node
    }
    printf("Null\n");                       // Indicate the end of the list
}

// Main function to display menu and take user input
int main() {
    int choice, value, oldValue;

    while (1) { // Infinite loop for menu-driven interface
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a value\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete after a value\n");
        printf("7. Print the doubly linked list\n");
        printf("8. Exit\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);

        // Process user choice
        if (choice == 1) {
            printf("Enter the value to insert at the beginning: ");
            scanf("%d", &value);
            insertHead(value);
        } else if (choice == 2) {
            printf("Enter the value to insert at the end: ");
            scanf("%d", &value);
            insertTail(value);
        } else if (choice == 3) {
            printf("Enter the value after which to insert: ");
            scanf("%d", &oldValue);
            printf("Enter the new value to insert: ");
            scanf("%d", &value);
            insertAfter(oldValue, value);
        } else if (choice == 4) {
            deleteHead();
        } else if (choice == 5) {
            deleteTail();
        } else if (choice == 6) {
            printf("Enter the value after which to delete: ");
            scanf("%d", &oldValue);
            deleteAfter(oldValue);
        } else if (choice == 7) {
            printLinkedList();
        } else if (choice == 8) {
            printf("Exiting program. Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid choice! Please enter a number between 1 and 8.\n");
        }
    }

    return 0;
}
