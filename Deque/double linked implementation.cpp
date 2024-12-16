#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// Deque class
class Deque {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Insert at the front
    void enqueue_front(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "Enqueued at front: " << value << endl;
    }

    // Insert at the rear
    void enqueue_rear(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued at rear: " << value << endl;
    }

    // Delete from the front
    void dequeue_front() {
        if (isEmpty()) {
            cout << "The deque is empty. Cannot dequeue from front." << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued from front: " << front->data << endl;
        if (front == rear) {
            front = rear = nullptr; // Deque becomes empty
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
    }

    // Delete from the rear
    void dequeue_rear() {
        if (isEmpty()) {
            cout << "The deque is empty. Cannot dequeue from rear." << endl;
            return;
        }
        Node* temp = rear;
        cout << "Dequeued from rear: " << rear->data << endl;
        if (front == rear) {
            front = rear = nullptr; // Deque becomes empty
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
    }

    // Display the deque
    void display() {
        if (isEmpty()) {
            cout << "The deque is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Deque elements: [";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << ", ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }
};

int main() {
    Deque deque;
    int choice, value;

    while (true) {
        cout << "\n1. Enqueue Front\n2. Enqueue Rear\n";
        cout << "3. Dequeue Front\n4. Dequeue Rear\n";
        cout << "5. Display Deque\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue at front: ";
            cin >> value;
            deque.enqueue_front(value);
            break;
        case 2:
            cout << "Enter value to enqueue at rear: ";
            cin >> value;
            deque.enqueue_rear(value);
            break;
        case 3:
            deque.dequeue_front();
            break;
        case 4:
            deque.dequeue_rear();
            break;
        case 5:
            deque.display();
            break;
        case 6:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
