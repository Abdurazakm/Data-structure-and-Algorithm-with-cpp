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

    // Insert into sorted position (used for merging)
    void sortedEnqueue(string name, int age) {
        Node* newNode = new Node(name, age);

        // Case 1: Queue is empty or new node should be at the front
        if (head == nullptr || head->age > age) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
            return;
        }

        // Case 2: Traverse to find the correct position
        Node* current = head;
        while (current->next != nullptr && current->next->age <= age) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
};

// Function to demerge a priority queue into young and adult queues
void demergeQueue(Queue& priorityQueue, Queue& youngQueue, Queue& adultQueue) {
    while (!priorityQueue.isEmpty()) {
        Node* person = priorityQueue.dequeue();
        if (person->age < 18) {
            youngQueue.enqueue(person->name, person->age);
        } else {
            adultQueue.enqueue(person->name, person->age);
        }
        delete person;
    }
}

// Function to merge two queues into a single priority queue
void mergeQueues(Queue& youngQueue, Queue& adultQueue, Queue& priorityQueue) {
    // Process Young Queue
    while (!youngQueue.isEmpty()) {
        Node* person = youngQueue.dequeue();
        priorityQueue.sortedEnqueue(person->name, person->age);
        delete person;
    }

    // Process Adult Queue
    while (!adultQueue.isEmpty()) {
        Node* person = adultQueue.dequeue();
        priorityQueue.sortedEnqueue(person->name, person->age);
        delete person;
    }
}

// Main function
int main() {
    Queue priorityQueue, youngQueue, adultQueue, mergedQueue;

    // Add people to the initial priority queue
    priorityQueue.enqueue("Abebe", 17);
    priorityQueue.enqueue("Alemu", 22);
    priorityQueue.enqueue("Aster", 15);
    priorityQueue.enqueue("Belay", 30);
    priorityQueue.enqueue("Kedir", 16);
    priorityQueue.enqueue("Meron", 20);
    priorityQueue.enqueue("Yonas", 12);

    cout << "Original Priority Queue: ";
    priorityQueue.display();

    // Demerge the priority queue into young and adult queues
    demergeQueue(priorityQueue, youngQueue, adultQueue);

    cout << "Young Queue (Age < 18): ";
    youngQueue.display();

    cout << "Adult Queue (Age >= 18): ";
    adultQueue.display();

    // Merge the young and adult queues back into a single priority queue
    mergeQueues(youngQueue, adultQueue, mergedQueue);

    cout << "Merged Priority Queue: ";
    mergedQueue.display();

    return 0;
}
