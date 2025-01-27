#include <iostream>
using namespace std;

// Maximum size of the stacks
const int MAX_SIZE = 1000;

// Stack implementation using arrays
int stackA[MAX_SIZE], stackB[MAX_SIZE], stackC[MAX_SIZE];
int topA = -1, topB = -1, topC = -1;

// Function to check if a stack is empty
bool is_empty(int top) {
    return top == -1;
}

// Function to push an element onto a stack
void push(int stack[], int &top, int value) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack overflow!" << endl;
        return;
    }
    stack[++top] = value;
}

// Function to pop an element from a stack
int pop(int stack[], int &top) {
    if (is_empty(top)) {
        cout << "Stack underflow!" << endl;
        return -1;
    }
    return stack[top--];
}

// Function to display the elements of a stack
void display_stack(int stack[], int top, const string &name) {
    cout << "Condition of stack " << name << ": ";
    if (is_empty(top)) {
        cout << "Empty";
    } else {
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
    }
    cout << endl;
}

// Function to transfer elements from Stack A to Stack C in sorted order (descending)
void transfer_sorted() {
    while (!is_empty(topA)) {
        int temp = pop(stackA, topA); // Pop an element from Stack A

        // Move elements from Stack C to Stack B if they are smaller than temp
        while (!is_empty(topC) && stackC[topC] < temp) {
            push(stackB, topB, pop(stackC, topC));
        }

        // Push temp into Stack C
        push(stackC, topC, temp);

        // Move elements back from Stack B to Stack C
        while (!is_empty(topB)) {
            push(stackC, topC, pop(stackB, topB));
        }
    }
}

int main() {
    int n;
    cin >> n; // Read the number of elements in Stack A

    // Read elements and push them into Stack A
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        push(stackA, topA, value);
    }

    // Transfer elements from Stack A to Stack C in sorted order
    transfer_sorted();

    // Display the final condition of all stacks
    display_stack(stackA, topA, "A");
    display_stack(stackB, topB, "B");
    display_stack(stackC, topC, "C");

    return 0;
}