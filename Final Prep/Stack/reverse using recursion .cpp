#include <iostream> // For input and output operations
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the simulated stack
int stack[MAX_SIZE];      // Array to simulate the stack
int top = -1;             // Top pointer initialized to -1 (empty stack)

// Function to push an element onto the stack
void push(int value) {
    if (top >= MAX_SIZE - 1) { // Check for stack overflow
        cout << "Stack Overflow. Cannot push " << value << "." << endl;
        return;
    }
    stack[++top] = value; // Increment the top pointer and add the value
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) { // Check for stack underflow
        cout << "Stack Underflow." << endl;
        return -1; // Return -1 if the stack is empty
    }
    return stack[top--]; // Return the top element and decrement the top pointer
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Recursive function to insert an element at the bottom of the stack
void insertAtBottom(int value) {
    if (isEmpty()) { // If the stack is empty, push the value directly
        push(value);
    } else {
        int temp = pop();         // Pop the top element and store it temporarily
        insertAtBottom(value);    // Recursive call to insert at the bottom
        push(temp);               // Push the temporarily stored value back onto the stack
    }
}

// Recursive function to reverse the stack
void reverseStack() {
    if (!isEmpty()) {             // If the stack is not empty
        int temp = pop();         // Pop the top element and store it temporarily
        reverseStack();           // Recursive call to reverse the remaining stack
        insertAtBottom(temp);     // Insert the popped element at the bottom
    }
}

int main() {
    int n, element;

    // Input the number of elements in the stack
    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    // Input elements into the stack
    cout << "Enter the elements of the stack:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> element;
        push(element);
    }

    // Display the original stack
    cout << "Original Stack:" << endl;
    for (int i = top; i >= 0; i--) { // Print elements from top to bottom
        cout << stack[i] << " ";
    }
    cout << endl;

    // Reverse the stack
    reverseStack();

    // Display the reversed stack
    cout << "Reversed Stack:" << endl;
    for (int i = top; i >= 0; i--) { // Print elements from top to bottom
        cout << stack[i] << " ";
    }
    cout << endl;

    return 0;
}
