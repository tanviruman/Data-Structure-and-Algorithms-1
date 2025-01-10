#include <iostream>
using namespace std;

struct Node
 {
    int data;
    Node* next;

    Node(int data)
     {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
 {
private:
    Node* head;
    Node* tail;

public:
    SinglyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void PrintList()
    {
        if (!head)

            {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        while (current)

            {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    int ListLength()

    {
        int count = 0;
        Node* current = head;

        while (current)

            {
            count++;
            current = current->next;
        }

        return count;
    }

    void Insert(int value)
     {
        Node* newNode = new Node(value);

        if (!head)

            {
            head = tail = newNode;
        }
        else
        {

            tail->next = newNode;
            tail = newNode;
        }
    }

    void InsertSorted(int value)

    {
        Node* newNode = new Node(value);

        if (!head || head->data >= value)

            {
            newNode->next = head;
            head = newNode;

            if (!tail) {
                tail = newNode;
            }
        }

        else {
            Node* current = head;

            while (current->next && current->next->data < value)


                {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;

            if (!newNode->next) tail = newNode;
        }
    }

    void DeleteMin()


     {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (!head) {
            tail = nullptr;
        }

        delete temp;
    }

    void ClearList()
    {
        while (head)

            {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Insert Sorted\n";
        cout << "3. Delete Minimum Value\n";
        cout << "4. Print List\n";
        cout << "5. Length\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.Insert(value);
                break;

            case 2:
                cout << "Enter value to insert (sorted): ";
                cin >> value;
                list.InsertSorted(value);
                break;

            case 3:
                list.DeleteMin();
                cout << "Deleted the minimum value." << endl;
                break;

            case 4:
                list.PrintList();
                break;

            case 5:
                cout << "List Length: " << list.ListLength() << endl;
                break;

            case 6:
                cout << "Cleaning up and exiting." << endl;
                list.ClearList();
                cout << "Ta Ta bye!" << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }
}
