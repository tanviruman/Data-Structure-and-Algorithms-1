#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int val;                // Stores the value of the node
    struct Node *next;      // Pointer to the next node in the linked list
};

struct Node *head = NULL;   // Global pointer to the head of the linked list

// Insert a node at the beginning
void insertHead(int value) {
    struct Node *newNode = malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->val = value;   // Set the value of the new node
    newNode->next = head;   // Point the new node's `next` to the current head
    head = newNode;         // Update head to point to the new node
}

// Insert a node at the end
void insertTail(int value) {
    struct Node *newNode = malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->val = value;   // Set the value of the new node
    newNode->next = NULL;   // The new node will point to NULL (end of the list)

    if (head == NULL) {     // If the list is empty, the new node becomes the head
        head = newNode;
    } else {
        struct Node *traveller = head;  // Start from the head
        while (traveller->next != NULL) { // Traverse to the last node
            traveller = traveller->next;
        }
        traveller->next = newNode;      // Attach the new node at the end
    }
}

// Insert a node after a specific value
void insertAfter(int oldValue, int newValue) {
    struct Node *traveller = head;      // Start from the head

    while (traveller != NULL) {         // Traverse the list
        if (traveller->val == oldValue) {
            break;                      // Stop when the specified value is found
        }
        traveller = traveller->next;
    }

    if (traveller == NULL) {            // If the value is not found
        printf("The value %d does not exist!\n", oldValue);
    } else {
        struct Node *newNode = malloc(sizeof(struct Node)); // Allocate memory for a new node
        newNode->val = newValue;       // Set the new node's value
        newNode->next = traveller->next; // Connect the new node
        traveller->next = newNode;
    }
}

// Delete the head node
void deleteHead() {
    if (head == NULL) {                 // Check if the list is empty
        printf("The list is empty, nothing to delete!\n");
        return;
    }

    struct Node *temp = head;           // Temporarily store the head node
    head = head->next;                  // Move head to the next node
    free(temp);                         // Free the memory of the old head
}

// Delete the tail node
void deleteTail() {
    if (head == NULL) {                 // Check if the list is empty
        printf("The list is empty, nothing to delete!\n");
        return;
    }

    if (head->next == NULL) {           // If there's only one node
        free(head);                     // Free its memory
        head = NULL;                    // Set head to NULL
        return;
    }

    struct Node *traveller = head;      // Start from the head
    while (traveller->next->next != NULL) { // Traverse to the second last node
        traveller = traveller->next;
    }

    free(traveller->next);              // Free the last node
    traveller->next = NULL;             // Set the second last node's `next` to NULL
}

// Delete a node after a specific value
void deleteAfter(int oldValue) {
    struct Node *traveller = head;      // Start from the head

    while (traveller != NULL && traveller->val != oldValue) {
        traveller = traveller->next;
    }

    if (traveller == NULL || traveller->next == NULL) {
        printf("Cannot delete after %d as it doesn't exist or is the last node!\n", oldValue);
    } else {
        struct Node *temp = traveller->next; // Temporarily store the node to be deleted
        traveller->next = temp->next;       // Connect to the node after the deleted node
        free(temp);                         // Free the memory of the deleted node
    }
}

// Print the linked list
void printLinkedList() {
    printf("Linked list: ");
    struct Node *traveller = head;       // Start from the head
    while (traveller != NULL) {          // Traverse until the end of the list
        printf("%d -> ", traveller->val); // Print the value of the current node
        traveller = traveller->next;     // Move to the next node
    }
    printf("Null\n");                    // Indicate the end of the list
}

// Main function to display menu and take user input
int main() {
    int choice, value, oldValue;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a value\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete after a value\n");
        printf("7. Print the linked list\n");
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
            exit(0);  // Exit the program
        } else {
            printf("Invalid choice! Please enter a number between 1 and 8.\n");
        }
    }

    return 0;
}
