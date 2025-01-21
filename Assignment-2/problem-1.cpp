#include <iostream>
#include <cstring>
#define MAX 200

using namespace std;

int arr[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    arr[++top] = value;
}

int pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return arr[top--];
}

bool isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int evaluate(const char* expression) {
    int i = 0;
    int operand1, operand2, result;

    while (expression[i] != '\0') {
        char symbol = expression[i];

        if (symbol >= '0' && symbol <= '9') {
            // Convert character to integer and push onto the stack
            push(symbol - '0');
        } else if (isOperator(symbol)) {
            if (top < 1) {
                cout << "Invalid Expression: Not enough operands\n";
                return -1;
            }
            operand2 = pop();
            operand1 = pop();

            // Perform the operation based on the operator
            switch (symbol) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0) {
                        cout << "Division by zero error\n";
                        return -1;
                    }
                    result = operand1 / operand2; break;
            }

            // Push the result back onto the stack
            push(result);
        } else if (symbol != ' ') {
            // Invalid character in the expression
            cout << "Invalid Character in Expression\n";
            return -1;
        }

        i++;
    }

    // Ensure there is exactly one result on the stack
    if (top != 0) {
        cout << "Invalid Expression\n";
        return -1;
    }

    return pop();
}

int main() {
    char expression[MAX];
    cout << "Enter a postfix expression (use spaces between tokens): ";
    cin.getline(expression, MAX);

    int result = evaluate(expression);
    if (result != -1) {
        cout << "Result = " << result << "\n";
    }

    return 0;
}
