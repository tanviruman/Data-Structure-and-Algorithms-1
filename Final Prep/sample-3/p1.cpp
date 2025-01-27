//Question 1: Special Stack (Enchanted Stack)
#include <iostream>
#include <stack>
using namespace std;

class EnchantedStack {
private:
    stack<int> st;

public:
    // Push an element onto the stack
    void push(int val) {
        st.push(val);
    }

    // Remove and return the last element from the stack
    int popEnd() {
        if (st.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int lastElement = st.top();
        st.pop();
        return lastElement;
    }

    // Remove elements until the top element is odd, then return the second removed even element
    int popMagic() {
        stack<int> temp;
        int secondEven = -1;
        int count = 0;

        while (!st.empty() && st.top() % 2 == 0) {
            if (count == 1) {
                secondEven = st.top(); // Store the second even element
            }
            temp.push(st.top());
            st.pop();
            count++;
        }

        // If we found at least two even elements, return the second one
        if (count >= 2) {
            return secondEven;
        } else {
            return -1; // No second even element found
        }
    }

    // Display the stack (for debugging purposes)
    void display() {
        stack<int> temp = st;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    EnchantedStack es;

    // Push elements into the stack
    es.push(10);
    es.push(20);
    es.push(33);
    es.push(40);
    es.push(50);
    es.push(60);

    // Test popMagic()
    cout << "Second even element removed: " << es.popMagic() << endl; // Should return 50
    es.display(); // Display the stack after popMagic()

    // Test popEnd()
    cout << "Last element removed: " << es.popEnd() << endl; // Should return 33
    es.display(); // Display the stack after popEnd()

    return 0;
}