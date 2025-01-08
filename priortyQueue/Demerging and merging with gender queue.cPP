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
            cout << "(" << current->name << ", Gender: " << current->gender << ") ";
            current = current->next;
        }
        cout << endl;
    }

    // Enqueue with order: Females first, then males
    void genderPriorityEnqueue(string name, string gender) {
        Node* newNode = new Node(name, gender);

        // Case 1: Queue is empty
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        // Case 2: Insert at the front for females
        if (gender == "Female" && head->gender == "Male") {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Case 3: Traverse to find the insertion point
        Node* current = head;
        while (current->next != nullptr && !(current->next->gender == "Male" && gender == "Female")) {
            current = current->next;
        }

        // Insert the new node
        newNode->next = current->next;
        current->next = newNode;

        // Update tail if inserted at the end
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
};

// Function to demerge a priority queue based on gender
void demergeQueue(Queue& priorityQueue, Queue& femaleQueue, Queue& maleQueue) {
    while (!priorityQueue.isEmpty()) {
        Node* person = priorityQueue.dequeue();
        if (person->gender == "Female") {
            femaleQueue.enqueue(person->name, person->gender);
        } else {
            maleQueue.enqueue(person->name, person->gender);
        }
        delete person;
    }
}

// Function to merge two queues into a single gender-prioritized queue
void mergeQueues(Queue& femaleQueue, Queue& maleQueue, Queue& priorityQueue) {
    // Process Female Queue
    while (!femaleQueue.isEmpty()) {
        Node* person = femaleQueue.dequeue();
        priorityQueue.genderPriorityEnqueue(person->name, person->gender);
        delete person;
    }

    // Process Male Queue
    while (!maleQueue.isEmpty()) {
        Node* person = maleQueue.dequeue();
        priorityQueue.genderPriorityEnqueue(person->name, person->gender);
        delete person;
    }
}

// Main function
int main() {
    Queue priorityQueue, femaleQueue, maleQueue, mergedQueue;

    // Add people to the initial priority queue
    priorityQueue.enqueue("Abebe", "Male");
    priorityQueue.enqueue("Alemu", "Male");
    priorityQueue.enqueue("Aster", "Female");
    priorityQueue.enqueue("Belay", "Male");
    priorityQueue.enqueue("Meron", "Female");
    priorityQueue.enqueue("Kedir", "Male");
    priorityQueue.enqueue("Yonas", "Male");

    cout << "Original Priority Queue: ";
    priorityQueue.display();

    // Demerge the priority queue into female and male queues
    demergeQueue(priorityQueue, femaleQueue, maleQueue);

    cout << "Female Queue: ";
    femaleQueue.display();

    cout << "Male Queue: ";
    maleQueue.display();

    // Merge the female and male queues back into a single priority queue
    mergeQueues(femaleQueue, maleQueue, mergedQueue);

    cout << "Merged Priority Queue: ";
    mergedQueue.display();

    return 0;
}
