#include <iostream>
using namespace std;

struct PriorityQueue {
    int value,age;
    PriorityQueue* next;
};

PriorityQueue* front = NULL;
PriorityQueue* rear = NULL;

void enqueue(int value, char age) {
    PriorityQueue* newQueue = new PriorityQueue();
    newQueue->value = value;
    newQueue->age = age;
    newQueue->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newQueue;
    } else {
        rear->next = newQueue;
        rear = newQueue;
    }
    cout << "Enqueued: " << newQueue->value << ", Age: " << newQueue->age << endl;
}

void dequeue(char age) {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }

    PriorityQueue* temp = front;
    PriorityQueue* prev = NULL;

    while (temp != NULL && temp->age != age) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "No element found with age: " << age << endl;
        return;
    }

    cout << "Dequeued: " << temp->value << ", Age: " << temp->age << endl;

    if (temp == front) {
        front = front->next;
    } else {
        prev->next = temp->next;
    }

    if (temp == rear) {
        rear = prev;
    }

    delete temp;
}

int main() {
    enqueue(10, 10);
    enqueue(20, 20);
    enqueue(30, 30);
    dequeue(40);
    enqueue(40, 40);
    dequeue(50);  // Testing case where the age is not found

    return 0;
}
