Here’s the entire code rewritten with detailed comments explaining each line:

```c
#include <stdio.h> // Include standard input/output library for printf() and scanf()

#define MAX 10 // Define a constant MAX to set the maximum size of the queue

// Declare a 2D array to store customer names. Each name can be up to 9 characters (plus the null terminator).
char queue[MAX][10];

// Variables to track the front and rear of the queue. Initialized to -1 to indicate the queue is empty.
int Front = -1;
int Rear = -1;

// Function to add a new customer to the queue
void enqueue(char customer[]) {
    // Check if the queue is full
    if ((Rear + 1) % MAX == Front) {
        printf("Capacity is full!\n"); // Print message if the queue is full
        return; // Exit the function
    }

    // If the queue is empty, initialize Front to 0
    if (Front == -1) {
        Front = 0;
    }

    // Move the Rear pointer to the next position in a circular manner
    Rear = (Rear + 1) % MAX;

    // Copy the customer's name into the queue at the Rear position
    for (int i = 0; customer[i] != '\0'; i++) {
        queue[Rear][i] = customer[i]; // Copy each character
        queue[Rear][i + 1] = '\0';   // Ensure the string is null-terminated
    }

    // Print a confirmation message
    printf("%s is added in the list!\n", customer);
}

// Function to serve the customer at the front of the queue
void dequeue() {
    // Check if the queue is empty
    if (Front == -1) {
        printf("No customer in the line!\n"); // Print message if no customers are in the queue
        return; // Exit the function
    }

    // Print the name of the customer being served
    printf("Give Biryani to %s\n", queue[Front]);

    // If only one customer is in the queue, reset Front and Rear to -1
    if (Front == Rear) {
        Front = -1;
        Rear = -1;
    } else {
        // Move the Front pointer to the next position in a circular manner
        Front = (Front + 1) % MAX;
    }
}

// Function to calculate and print the total number of customers in the queue
void Total_Customer() {
    // Check if the queue is empty
    if (Front == -1) {
        printf("No customer in the line!\n"); // Print message if no customers are in the queue
        return; // Exit the function
    }

    int Count; // Variable to store the total number of customers

    // If the Rear pointer is ahead of or equal to the Front pointer
    if (Rear >= Front) {
        Count = Rear - Front + 1; // Directly subtract Front from Rear and add 1
    } else {
        // For circular queues, calculate the total by wrapping around
        Count = MAX - Front + Rear + 1;
    }

    // Print the total number of customers
    printf("Total %d customers in line.\n", Count);
}

// Main function where program execution begins
int main() {
    int choice; // Variable to store the user's menu choice
    char customer[10]; // Array to store the customer's name

    // Infinite loop to display the menu and process user input
    while (1) {
        printf("\n"); // Print a blank line for readability
        printf("1. Add New Customer\n"); // Option to add a new customer
        printf("2. Give Biryani to Customer\n"); // Option to serve the next customer
        printf("3. Total Customers in Line\n"); // Option to view the total number of customers
        printf("4. Close Shop\n"); // Option to exit the program
        printf("Enter your choice: "); // Prompt the user to enter a choice
        scanf("%d", &choice); // Read the user's choice

        // Switch statement to handle the user's choice
        switch (choice) {
            case 1: // If the user chooses to add a new customer
                printf("Enter Customer Name: "); // Prompt for the customer's name
                getchar(); // Clear the newline character left by scanf()
                fgets(customer, sizeof(customer), stdin); // Read the customer's name (including spaces)

                // Remove the newline character at the end of the input string
                for (int i = 0; customer[i] != '\0'; i++) {
                    if (customer[i] == '\n') {
                        customer[i] = '\0'; // Replace the newline character with a null terminator
                        break; // Exit the loop
                    }
                }

                enqueue(customer); // Call the enqueue function to add the customer
                break;

            case 2: // If the user chooses to serve a customer
                dequeue(); // Call the dequeue function to serve the next customer
                break;

            case 3: // If the user chooses to view the total number of customers
                Total_Customer(); // Call the Total_Customer function
                break;

            case 4: // If the user chooses to close the shop
                printf("Closing the shop.\n"); // Print a closing message
                return 0; // Exit the program

            default: // If the user enters an invalid choice
                printf("Invalid choice..\n"); // Print an error message
        }
    }
}
```

### Key Points:
1. **Queue Implementation**: This code uses a circular queue to efficiently manage customer names.
2. **Menu-Driven**: The program provides an interactive menu for the user to add customers, serve them, view total customers, or close the shop.
3. **Boundary Conditions**: Handles cases where the queue is full or empty to avoid errors.
4. **Circular Queue**: Uses the modulo operator `%` to manage the `Front` and `Rear` pointers in a circular manner.