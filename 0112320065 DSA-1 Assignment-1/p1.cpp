#include <iostream>       // Include the input-output stream library
#include <cstring>        // Include the C-string library for string manipulation
#include <cstdlib>        // Include the C standard library (not used in this code)
#define MAX 200           // Define a constant for the maximum stack size

using namespace std;      // Use the standard namespace to simplify code

// Global variables for stack implementation
int arr[MAX];             // Array to store the stack elements
int top = -1;             // Variable to track the top of the stack

// Function to push a value onto the stack
void push(int value) {
    if (top >= MAX - 1) {                     // Check if the stack is full
        cout << "Stack Overflow\n";          // Print overflow message
        return;
    }
    arr[++top] = value;                       // Increment top and store the value
}

// Function to pop a value from the stack
int pop() {
    if (top < 0) {                            // Check if the stack is empty
        cout << "Stack Underflow\n";          // Print underflow message
        return -1;                            // Return -1 to indicate an error
    }
    return arr[top--];                        // Return the top value and decrement top
}

// Function to check if a character is an operator
bool isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/'; // Return true if the symbol is a valid operator
}

// Function to evaluate a postfix expression
int evaluate(const char* expression) {
    int i = 0;                                // Initialize index for traversing the expression
    int operand1, operand2, result;           // Variables to store operands and result

    while (expression[i] != '\0') {           // Loop through the expression until the null terminator
        char symbol = expression[i];          // Get the current character

        if (symbol >= '0' && symbol <= '9') { // Check if the character is a digit
            push(symbol - '0');               // Convert character to integer and push onto the stack
        } else if (isOperator(symbol)) {      // Check if the character is an operator
            if (top < 1) {                    // Ensure there are at least two operands on the stack
                cout << "Invalid Expression: Not enough operands\n";
                return -1;                    // Return error code
            }
            operand2 = pop();                 // Pop the second operand
            operand1 = pop();                 // Pop the first operand

            // Perform the operation based on the operator
            switch (symbol) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0) {       // Check for division by zero
                        cout << "Division by zero error\n";
                        return -1;            // Return error code
                    }
                    result = operand1 / operand2; break;
            }

            push(result);                     // Push the result back onto the stack
        } else if (symbol != ' ') {           // Ignore spaces, but check for invalid characters
            cout << "Invalid Character in Expression\n";
            return -1;                        // Return error code
        }

        i++;                                  // Move to the next character
    }

    // Ensure there is exactly one result on the stack
    if (top != 0) {                           // If the stack doesn't have exactly one value, the expression is invalid
        cout << "Invalid Expression\n";
        return -1;                            // Return error code
    }

    return pop();                             // Return the final result
}

int main() {
    char expression[MAX];                     // Declare an array to hold the input expression
    cout << "Enter a postfix expression (use spaces between tokens): ";
    cin.getline(expression, MAX);            // Read the entire line of input

    int result = evaluate(expression);       // Call the evaluate function with the input expression
    if (result != -1) {                      // Check if evaluation was successful
        cout << "Result = " << result << "\n"; // Print the result
    }

    return 0;                                // Exit the program
}
