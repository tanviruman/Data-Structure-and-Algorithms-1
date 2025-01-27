#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;       // To store the value of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize the node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* topNode; // Pointer to the top node of the stack
    int count;     // To keep track of the stack size

public:
    // Constructor to initialize the stack
    Stack() {
        topNode = nullptr;
        count = 0;
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = topNode;         // Link the new node to the current top
        topNode = newNode;               // Update the top to the new node
        count++;                         // Increment the stack size
    }

    // Function to pop an element from the stack
    void pop() {
        if (topNode == nullptr) { // If the stack is empty
            cout << "No elements to pop\n";
            return;
        }

        Node* temp = topNode;     // Store the top node in a temporary variable
        topNode = topNode->next;  // Move the top pointer to the next node
        delete temp;              // Delete the old top node
        count--;                  // Decrement the stack size
    }

    // Function to get the top element of the stack
    int top() {
        if (topNode == nullptr) { // If the stack is empty
            return -1;           // Return -1 to indicate an empty stack
        }
        return topNode->data;    // Return the data of the top node
    }

    // Function to get the size of the stack
    int size() {
        return count; // Return the current size of the stack
    }

    // Function to check if the stack is empty
    bool empty() {
        return (topNode == nullptr); // Return true if the stack is empty
    }
};

// Main function
int main() {
    Stack st; // Create a stack object
    int choice, value;

    while (true) {
        // Display menu options
        cout << "\nStack Operations:\n";
        cout << "1. Push (Add element)\n";
        cout << "2. Pop (Remove element)\n";
        cout << "3. Top (View top element)\n";
        cout << "4. Size (View stack size)\n";
        cout << "5. Check if Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            st.push(value);
            break;

        case 2:
            st.pop();
            break;

        case 3:
            value = st.top();
            if (value == -1) {
                cout << "Stack is empty!\n";
            } else {
                cout << "Top element: " << value << endl;
            }
            break;

        case 4:
            cout << "Current size: " << st.size() << endl;
            break;

        case 5:
            if (st.empty()) {
                cout << "Stack is empty!\n";
            } else {
                cout << "Stack is not empty!\n";
            }
            break;

        case 6:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
