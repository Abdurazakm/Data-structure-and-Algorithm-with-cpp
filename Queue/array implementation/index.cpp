#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

bool isFull(int rear, int front) {
    return ((rear + 1) % MAX_SIZE == front);  // Full condition in circular queue
}

bool isEmpity(int front) {
    return (front == -1);  // Queue is empty if front is -1
}

void display(int Queue[], int front, int rear) {
    if (isEmpity(front)) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    int i = front;
    while (i != rear) {
        cout << Queue[i] << ", ";
        i = (i + 1) % MAX_SIZE;  // Circular increment of i
    }
    cout << Queue[rear] << "]" << endl;  // Print the last element
}

void dequeue(int &front, int &rear, int Queue[]) {
    if (isEmpity(front)) {
        cout << "Queue is underflow\n";
    } else {
        cout << "Dequeued: " << Queue[front] << endl;
        if (front == rear) {  // Only one element left in the queue
            front = rear = -1;  // Reset the queue
        } else {
            front = (front + 1) % MAX_SIZE;  // Circular increment of front
        }
        display(Queue, front, rear);
    }
}

void enqueue(int num, int &rear, int &front, int Queue[]) {
    if (isFull(rear, front)) {
        cout << "Queue overflow\n";
    } else {
        if (front == -1) {  // Initialize front if the queue was empty
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;  // Circular increment of rear
        Queue[rear] = num;
        cout << "Enqueued: " << num << endl;
        display(Queue, front, rear);
    }
}

void circular_enqueue(int num, int &rear, int &front, int Queue[]) {
    if (isFull(rear, front)) {  // Check if the queue is full
        cout << "Queue is full\n";
    } else {
        if (front == -1) {  // Initialize front if the queue was empty
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;  // Circular increment of rear
        Queue[rear] = num;
        cout << "Enqueued: " << num << endl;
    }
    display(Queue, front, rear);
}

void circular_dequeue(int &front, int &rear, int Queue[]) {
    if (isEmpity(front)) {  // Check if the queue is empty
        cout << "Queue is underflow\n";
    } else {
        cout << "Dequeued: " << Queue[front] << endl;
        if (front == rear) {  // If there is only one element left, reset the queue
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;  // Circular increment of front
        }
    }
    display(Queue, front, rear);
}

int main() {
    int Queue[MAX_SIZE];
    int rear = -1, front = -1;
    int choice;

    cout << "Select Queue Implementation:\n";
    cout << "1. Simple Array-Based Queue\n";
    cout << "2. Circular Queue\n";
    cin >> choice;

    if (choice == 1) {
        int operation;
        do {
            cout << "\nSelect Operation:\n";
            cout << "1. Enqueue\n";
            cout << "2. Dequeue\n";
            cout << "3. Exit\n";
            cin >> operation;

            if (operation == 1) {
                int value;
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value, rear, front, Queue);
            } else if (operation == 2) {
                dequeue(front, rear, Queue);
            }
        } while (operation != 3);

    } else if (choice == 2) {
        int operation;
        do {
            cout << "\nSelect Operation:\n";
            cout << "1. Enqueue\n";
            cout << "2. Dequeue\n";
            cout << "3. Exit\n";
            cin >> operation;

            if (operation == 1) {
                int value;
                cout << "Enter value to enqueue: ";
                cin >> value;
                circular_enqueue(value, rear, front, Queue);
            } else if (operation == 2) {
                circular_dequeue(front, rear, Queue);
            }
        } while (operation != 3);
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}
