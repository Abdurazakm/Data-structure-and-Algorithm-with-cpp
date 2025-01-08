#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    string name; // Name of the person
    int age;     // Age of the person
    Node* next;

    Node(string n, int a) : name(n), age(a), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    ~Queue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Enqueue: Add element to the end of the queue
    void enqueue(string name, int age) {
        Node* newNode = new Node(name, age);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Dequeue: Remove element from the front of the queue
    Node* dequeue() {
        if (head == nullptr) {
            cout << "Queue Underflow!" << endl;
            return nullptr;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        return temp;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Display the elements of the queue
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << "(" << current->name << ", Age: " << current->age << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

// Function to demerge a queue based on age
void demergeQueue(Queue& priorityQueue, Queue& youngQueue, Queue& adultQueue) {
    while (!priorityQueue.isEmpty()) {
        Node* person = priorityQueue.dequeue();
        if (person->age < 18) {
            youngQueue.enqueue(person->name, person->age);
        } else {
            adultQueue.enqueue(person->name, person->age);
        }
        delete person; // Free the node after processing
    }
}

int main() {
    Queue priorityQueue, youngQueue, adultQueue;

    // Add people to the priority queue
    priorityQueue.enqueue("Abebe", 17);
    priorityQueue.enqueue("Alemu", 22);
    priorityQueue.enqueue("Aster", 15);
    priorityQueue.enqueue("Belay", 30);
    priorityQueue.enqueue("Kedir", 16);
    priorityQueue.enqueue("Meron", 20);
    priorityQueue.enqueue("Yonas", 12);

    cout << "Original Priority Queue: ";
    priorityQueue.display();

    // Demerge the priority queue
    demergeQueue(priorityQueue, youngQueue, adultQueue);

    cout << "Young Queue (Age < 18): ";
    youngQueue.display();

    cout << "Adult Queue (Age >= 18): ";
    adultQueue.display();

    return 0;
}
