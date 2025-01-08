#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    string name; // Name of the person
    string gender; // Gender (e.g., "Male" or "Female")
    Node* next;

    Node(string n, string g) : name(n), gender(g), next(nullptr) {}
};

// Priority Queue class
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
    void enqueue(string name, string gender) {
        Node* newNode = new Node(name, gender);
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
            cout << "(" << current->name << ", " << current->gender << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

// Function to demerge a queue
void demergeQueue(Queue& priorityQueue, Queue& femaleQueue, Queue& maleQueue) {
    while (!priorityQueue.isEmpty()) {
        Node* person = priorityQueue.dequeue();
        if (person->gender == "Female") {
            femaleQueue.enqueue(person->name, person->gender);
        } else {
            maleQueue.enqueue(person->name, person->gender);
        }
        delete person; // Free the node after processing
    }
}

int main() {
    Queue priorityQueue, femaleQueue, maleQueue;

    // Add people to the priority queue
    priorityQueue.enqueue("Abebe", "Male");
    priorityQueue.enqueue("Alemu", "Male");
    priorityQueue.enqueue("Aster", "Female");
    priorityQueue.enqueue("Belay", "Male");
    priorityQueue.enqueue("Kedir", "Male");
    priorityQueue.enqueue("Meron", "Female");
    priorityQueue.enqueue("Yonas", "Male");

    cout << "Original Priority Queue: ";
    priorityQueue.display();

    // Demerge the priority queue
    demergeQueue(priorityQueue, femaleQueue, maleQueue);

    cout << "Female Queue: ";
    femaleQueue.display();

    cout << "Male Queue: ";
    maleQueue.display();

    return 0;
}
