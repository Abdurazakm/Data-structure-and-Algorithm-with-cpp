#include <iostream>
using namespace std;

const int SIZE_OF_DEQUE = 5;
int FRONT = -1, REAR = -1;

bool isFull() {
    if ((FRONT == 0 && REAR == SIZE_OF_DEQUE - 1) || (FRONT == REAR + 1)) {
        return true;
    }
    return false;
}

bool isEmpity() {
    if (FRONT == -1 && REAR == -1) {
        return true;
    }
    return false;
}

void enqueue_front(int deque[], int value) {
    if (isFull()) {
        cout << "The Deque is Full!" << endl;
        return;
    } else if (isEmpity()) {
        FRONT = REAR = 0;
        deque[FRONT] = value;
    } else if (FRONT == 0) {
        FRONT = SIZE_OF_DEQUE - 1;
        deque[FRONT] = value;
    } else {
        FRONT--;
        deque[FRONT] = value;
    }
    cout << "Enqueued front: " << deque[FRONT] << endl;
}

void enqueue_rear(int deque[], int value) {
    if (isFull()) {
        cout << "The Deque is Full!" << endl;
        return;
    } else if (isEmpity()) {
        FRONT = REAR = 0;
        deque[REAR] = value;
    } else if (REAR == SIZE_OF_DEQUE - 1) {
        REAR = 0;
        deque[REAR] = value;
    } else {
        REAR++;
        deque[REAR] = value;
    }
    cout << "Enqueued rear: " << deque[REAR] << endl;
}

void dequeue_front(int deque[]) {
    if (isEmpity()) {
        cout << "The Deque is Empty!" << endl;
    } else if (FRONT == REAR) { // Only one element
        cout << "Dequeued: " << deque[FRONT] << endl;
        FRONT = REAR = -1; // Reset
    } else {
        cout << "Dequeued: " << deque[FRONT] << endl;
        FRONT = (FRONT + 1) % SIZE_OF_DEQUE; // Circular increment
    }
}

void dequeue_rear(int deque[]) {
    if (isEmpity()) {
        cout << "The Deque is Empty!" << endl;
    } else if (FRONT == REAR) { // Only one element
        cout << "Dequeued: " << deque[REAR] << endl;
        FRONT = REAR = -1; // Reset
    } else {
        cout << "Dequeued: " << deque[REAR] << endl;
        REAR = (REAR - 1 + SIZE_OF_DEQUE) % SIZE_OF_DEQUE; // Circular decrement
    }
}

void display(int deque[]) {
    if (isEmpity()) {
        cout << "The Deque is Empty!" << endl;
        return;
    }
    int i = FRONT;
    cout << "[";
    while (i != REAR) {
        cout << deque[i] << ", ";
        i = (i + 1) % SIZE_OF_DEQUE; // Circular increment
    }
    cout << deque[REAR] << "]" << endl;
}

int main() {
    int value, deque[SIZE_OF_DEQUE];
    while (true) {
        cout << "\nWhat do you want: " << endl;
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "1. Enqueue front\n2. Enqueue rear" << endl;
            cin >> choice;
            if (choice == 1) {
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue_front(deque, value);
            } else if (choice == 2) {
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue_rear(deque, value);
            } else {
                cout << "Invalid choice" << endl;
            }
        } else if (choice == 2) {
            cout << "1. Dequeue front\n2. Dequeue rear" << endl;
            cin >> choice;
            if (choice == 1) {
                dequeue_front(deque);
            } else if (choice == 2) {
                dequeue_rear(deque);
            } else {
                cout << "Invalid choice" << endl;
            }
        } else if (choice == 3) {
            display(deque);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
