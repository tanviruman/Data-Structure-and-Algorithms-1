#include <stdio.h> // Include standard input/output library for printf and scanf

// Global variables for the circular queue implementation
int queue[5]; // Array to represent the queue with a fixed size of 5
int front = -1; // Index for the front of the queue, initialized to -1 (empty queue)
int rear = -1;  // Index for the rear of the queue, initialized to -1 (empty queue)
int size = 5;   // Size of the queue

// Function to add an element to the queue
void enqueue(int value) {
    // Check if the queue is full
    if ((rear + 1 == size && front == 0) || (rear + 1 == front)) {
        printf("Queue Overflow. Cannot enqueue %d.\n", value);
        return;
    }
    // If the queue is initially empty, set front to 0
    if (front == -1) {
        front = 0;
    }
    // Wrap around the rear index if it reaches the end of the array
    if (rear == size - 1) {
        rear = 0;
    } else {
        rear++; // Otherwise, increment the rear index
    }
    queue[rear] = value; // Add the new value to the queue
    printf("Value %d enqueued to the queue.\n", value);
}

// Function to remove and return an element from the queue
int dequeue() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue Underflow. No elements to dequeue.\n");
        return -1; // Return -1 to indicate underflow
    }
    int value = queue[front]; // Get the value at the front of the queue
    // If the queue has only one element, reset front and rear to -1
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == size - 1) { // Wrap around the front index if it reaches the end of the array
        front = 0;
    } else {
        front++; // Otherwise, increment the front index
    }
    printf("Value %d dequeued from the queue.\n", value);
    return value; // Return the dequeued value
}

// Function to print the elements in the queue
void printQueue() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    int i = front; // Start from the front index
    while (1) {
        printf("%d ", queue[i]); // Print the current element
        if (i == rear) { // Stop if the rear index is reached
            break;
        }
        if (i == size - 1) { // Wrap around the index if it reaches the end of the array
            i = 0;
        } else {
            i++; // Otherwise, increment the index
        }
    }
    printf("\n");
}

int main() {
    int choice = 0; // Variable to store the user's menu choice
    int value;      // Variable to store the value for enqueue

    // Loop until the user chooses to exit
    while (choice != 4) {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read the user's choice

        if (choice == 1) {
            printf("Enter the value to enqueue: ");
            scanf("%d", &value); // Read the value to enqueue
            enqueue(value);       // Call enqueue function
        } else if (choice == 2) {
            dequeue(); // Call dequeue function
        } else if (choice == 3) {
            printQueue(); // Call printQueue function
        } else if (choice == 4) {
            printf("Exiting...\n"); // Exit the program
        } else {
            printf("Invalid choice. Please try again.\n"); // Handle invalid input
        }
    }

    return 0; // End of the program
}
