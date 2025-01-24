#include <stdio.h>   // Include the standard input/output library
#define MAX 10        // Define the maximum number of customers in the queue

char queue[MAX][100]; // Declare a queue to store customer names, each with a maximum length of 100 characters
int front = -1, rear = -1; // Initialize the front and rear pointers for the queue to -1 (indicating an empty queue)

// Function to add a customer to the queue
void enqueue(char customer[]) {
    if ((rear + 1) % MAX == front) { // Check if the queue is full (circular queue condition)
        printf("Sorry, capacity is full!\n");
        return; // Exit the function if the queue is full
    }
    if (front == -1) { // If the queue is empty, initialize the front pointer
        front = 0;
    }
    rear = (rear + 1) % MAX; // Update the rear pointer (using modulo for circular behavior)

    // Copy the customer's name into the queue manually
    for (int i = 0; customer[i] != '\0'; i++) {
        queue[rear][i] = customer[i]; // Copy each character
        queue[rear][i + 1] = '\0';   // Null-terminate the string
    }

    printf("%s is added to the list!\n", customer); // Confirm addition to the queue
}

// Function to serve a customer and remove them from the queue
void dequeue() {
    if (front == -1) { // Check if the queue is empty
        printf("No customer in the line!\n");
        return; // Exit the function if the queue is empty
    }

    // Print the name of the customer being served
    printf("Give Biryani to %s\n", queue[front]);

    if (front == rear) { // If there was only one customer in the queue
        front = -1; // Reset the queue to empty state
        rear = -1;
    } else {
        front = (front + 1) % MAX; // Move the front pointer to the next customer
    }
}

// Function to display the total number of customers in the queue
void totalCustomers() {
    if (front == -1) { // Check if the queue is empty
        printf("No customer in the line!\n");
        return; // Exit the function if the queue is empty
    }

    int count; // Variable to store the count of customers
    if (rear >= front) { // If the queue is not wrapped
        count = rear - front + 1; // Calculate the number of customers
    } else { // If the queue is wrapped around
        count = MAX - front + rear + 1; // Calculate the count accordingly
    }

    printf("%d total customers in line.\n", count); // Print the total number of customers
}

int main() {
    int choice; // Variable to store the user's choice
    char customer[100]; // Buffer to store the customer's name

    while (1) { // Infinite loop to display the menu until the user exits
        // Display the menu
        printf("\nChoose an option:\n");
        printf("1. Add New Customer\n");
        printf("2. Give Biryani to Customer\n");
        printf("3. Total Customers in Line\n");
        printf("4. Close Shop\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read the user's choice

        switch (choice) { // Handle the user's choice using a switch-case block
            case 1:
                // Add a new customer
                printf("Enter Customer Name: ");
                getchar(); // Consume any leftover newline character in the input buffer
                fgets(customer, sizeof(customer), stdin); // Read the customer's name
                customer[strcspn(customer, "\n")] = '\0'; // Remove the newline character from the input
                enqueue(customer); // Add the customer to the queue
                break;

            case 2:
                // Serve a customer
                dequeue(); // Call the dequeue function
                break;

            case 3:
                // Display the total number of customers
                totalCustomers(); // Call the totalCustomers function
                break;

            case 4:
                // Exit the program
                printf("Closing the shop.\n");
                return 0; // Exit the program with a success status

            default:
                // Handle invalid input
                printf("Invalid choice. Please try again.\n");
        }
    }
}
