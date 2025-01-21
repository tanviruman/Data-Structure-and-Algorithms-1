
#include <stdio.h>
#include <string.h>
#define MAX 10 // Maximum number of customers in the queue

char queue[MAX][100]; // Array to store customer names
int front = -1, rear = -1; // Initialize front and rear pointers

// Function to add a customer to the queue
void enqueue(char customer[]) {
    if ((rear + 1) % MAX == front) { // Check if the queue is full
        printf("Sorry, capacity is full!\n");
        return;
    }
    if (front == -1) { // If the queue is empty
        front = 0;
    }
    rear = (rear + 1) % MAX; // Update rear pointer
    strcpy(queue[rear], customer); // Add customer to the queue
    printf("%s is added to the list!\n", customer);
}

// Function to serve a customer and remove them from the queue
void dequeue() {
    if (front == -1) { // Check if the queue is empty
        printf("No customer in the line!\n");
        return;
    }
    printf("Give Biryani to %s\n", queue[front]); // Serve the customer
    if (front == rear) { // If only one customer was in the queue
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX; // Update front pointer
    }
}

// Function to display the total number of customers in the queue
void totalCustomers() {
    if (front == -1) { // Check if the queue is empty
        printf("No customer in the line!\n");
        return;
    }
    int count;
    if (rear >= front) {
        count = rear - front + 1; // Customers are in a contiguous block
    } else {
        count = MAX - front + rear + 1; // Customers are wrapped around
    }
    printf("%d total customers in line.\n", count);
}

int main() {
    int choice;
    char customer[100];

    while (1) {
        // Display the menu
        printf("\nChoose an option:\n");
        printf("1. Add New Customer\n");
        printf("2. Give Biryani to Customer\n");
        printf("3. Total Customers in Line\n");
        printf("4. Close Shop\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a new customer
                printf("Enter Customer Name: ");
                getchar(); // To ignore leftover newline character
                fgets(customer, sizeof(customer), stdin); // Read the customer name
                customer[strcspn(customer, "\n")] = '\0'; // Remove the newline character
                enqueue(customer);
                break;

            case 2:
                // Serve a customer
                dequeue();
                break;

            case 3:
                // Display total customers
                totalCustomers();
                break;

            case 4:
                // Exit the program
                printf("Closing the shop.\n");
                return 0;

            default:
                // Handle invalid choices
                printf("Invalid choice. Please try again.\n");
        }
    }
}
