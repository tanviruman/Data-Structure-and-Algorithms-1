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

// Queue class using linked list
class Queue {
private:
    Node* front;    // Pointer to the front node of the queue
    Node* rear;     // Pointer to the rear node of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to add an element to the queue (enqueue)
    void enQueue(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value

        // If the queue is empty, the new node becomes both the front and rear
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        // Otherwise, add the new node to the end of the queue and update the rear pointer
        rear->next = newNode;
        rear = newNode;
    }

    // Function to remove an element from the queue (dequeue)
    int deQueue() {
        // If the queue is empty, return -1
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return -1;
        }

        // Store the value of the front node and move the front pointer to the next node
        int value = front->data;
        Node* temp = front;
        front = front->next;

        // If the queue becomes empty, set the rear pointer to nullptr
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp; // Free the memory of the removed node
        return value;
    }

    // Function to display the elements of the queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Queue q; // Create a queue object
    int choice, value;

    while (true) {
        // Display menu options
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue (Add element)\n";
        cout << "2. Dequeue (Remove element)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            value = q.deQueue();
            if (value != -1) {
                cout << "Dequeued: " << value << endl;
            }
            break;

        case 3:
            cout << "Queue elements: ";
            q.display();
            break;

        case 4:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
