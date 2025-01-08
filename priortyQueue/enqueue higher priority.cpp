#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    string name; // Data (name of the person)
    int priority; // Priority (higher value -> higher priority)
    Node* next; // Pointer to the next node

    // Constructor for initialization
    Node(string n, int p) : name(n), priority(p), next(nullptr) {}
};

// Priority Queue class
class PriorityQueue {
private:
    Node* head; // Pointer to the head of the linked list

public:
    // Constructor
    PriorityQueue() : head(nullptr) {}

    // Destructor to free memory
    ~PriorityQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Enqueue: Insert an element into the priority queue
    void enqueue(string name, int priority) {
        Node* newNode = new Node(name, priority);

        // If the queue is empty or the new node has the highest priority
        if (head == nullptr || head->priority < priority) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Traverse the list to find the correct position
        Node* current = head;
        while (current->next != nullptr && current->next->priority >= priority) {
            current = current->next;
        }

        // Insert the new node in the correct position
        newNode->next = current->next;
        current->next = newNode;
    }

    // Dequeue: Remove and return the element with the highest priority
    string dequeue() {
        if (head == nullptr) {
            cout << "Queue Underflow: No elements in the queue!" << endl;
            return "";
        }

        Node* temp = head;
        string highestPriorityElement = head->name;
        head = head->next; // Move head to the next node
        delete temp; // Free memory
        return highestPriorityElement;
    }

    // Display the elements of the priority queue
    void display() {
        if (head == nullptr) {
            cout << "The queue is empty!" << endl;
            return;
        }

        cout << "Priority Queue: [ ";
        Node* current = head;
        while (current != nullptr) {
            cout << "(" << current->name << ", Priority: " << current->priority << ") ";
            current = current->next;
        }
        cout << "]" << endl;
    }
};

int main() {
    PriorityQueue pq;

    // Adding elements to the priority queue
    pq.enqueue("Abebe", 1);
    pq.enqueue("Aster", 2);
    pq.enqueue("Meron", 2);
    pq.enqueue("Alemu", 1);
    pq.enqueue("Belay", 1);

    // Display the queue
    pq.display();

    // Removing elements based on priority
    cout << "Dequeued: " << pq.dequeue() << endl;
    pq.display();

    cout << "Dequeued: " << pq.dequeue() << endl;
    pq.display();

    cout << "Dequeued: " << pq.dequeue() << endl;
    pq.display();

    return 0;
}
