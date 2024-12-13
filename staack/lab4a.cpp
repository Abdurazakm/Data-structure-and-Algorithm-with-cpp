#include <iostream>
using namespace std;

#define MAX_STACK 100 // Maximum size of the stack

// Define the stack
class Stack {
private:
    int items[MAX_STACK];
    int top;

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }

    // Push an element onto the stack
    void push(int newItem) {
        if (top >= MAX_STACK - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            ++top;
            items[top] = newItem;
            cout << "Item " << newItem << " pushed to the stack." << endl;
        }
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1; // Return -1 for underflow condition
        } else {
            int stackTop = items[top];
            --top;
            cout << "Item " << stackTop << " popped from the stack." << endl;
            return stackTop;
        }
    }

    // Peek the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            return items[top];
        }
    }
};

// Main function
int main() {
    Stack myStack; // Create a stack object

    // Demonstrate stack operations
    myStack.push(10); // Push 10
    myStack.push(20); // Push 20
    myStack.push(30); // Push 30

    cout << "Top element is: " << myStack.peek() << endl;

    myStack.pop(); // Pop an element
    cout << "Top element after pop is: " << myStack.peek() << endl;

    // Check if the stack is empty
    if (myStack.isEmpty()) {
        cout << "The stack is empty." << endl;
    } else {
        cout << "The stack is not empty." << endl;
    }

    return 0;
}
