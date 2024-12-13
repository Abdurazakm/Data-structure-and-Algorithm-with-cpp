#include <iostream>
using namespace std;

// Node structure for stack
struct Node {
    int data;    // Data of the node
    Node* next;  // Pointer to the next node
};

// Define the stack class
class Stack {
private:
    Node* top; // Pointer to the top node of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr; // Initially, the stack is empty
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top == nullptr);
    }

    // Push an element onto the stack
    void push(int newItem) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = newItem;    // Set the data of the node
        newNode->next = top;        // Point the new node to the current top
        top = newNode;              // Update the top pointer
        cout << "Item " << newItem << " pushed to the stack." << endl;
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1; // Indicate failure to pop
        } else {
            Node* temp = top;       // Store the current top node
            int stackTop = temp->data; // Retrieve the data of the top node
            top = top->next;        // Move the top pointer to the next node
            delete temp;            // Free memory of the old top node
            cout << "Item " << stackTop << " popped from the stack." << endl;
            return stackTop;        // Return the popped value
        }
    }

    // Peek the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            return top->data; // Return the data of the top node
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
