#include <iostream>
#include <cstring>
using namespace std;

struct student {
    char name[20];
    int age;
    char Dept[20];
    student *next;
};

student *start = NULL; // Initialize the start of the linked list to NULL

// Insert at the beginning
void insert_beg(student *p) {
    if (start == NULL) { // If the list is empty
        start = p;
        cout << "Node inserted at the beginning.\n";
    } else {
        p->next = start; // Make new node point to the current first node
        start = p;       // Update start to the new node
        cout << "Node inserted at the beginning.\n";
    }
}

// Insert at the end
void insert_end(student *p) {
    if (start == NULL) { // If the list is empty
        start = p;
        cout << "Node inserted at the end.\n";
    } else {
        student *current = start;
        while (current->next != NULL) { // Traverse to the last node
            current = current->next;
        }
        current->next = p; // Make the last node point to the new node
        cout << "Node inserted at the end.\n";
    }
}

// Insert after a specific position
void insert_after(int position, student *p) {
    student *q = start;
    for (int i = 1; i < position && q != NULL; i++) {
        q = q->next;
    }
    if (q == NULL) {
        cout << "Less than " << position << " nodes in the list!\n";
    } else {
        p->next = q->next; // Point new node to the next node after `q`
        q->next = p;       // Point `q` to the new node
        cout << "Node inserted successfully after position " << position << ".\n";
    }
}

// Display the list
void display() {
    student *current = start;
    if (current == NULL) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Student List:\n";
    while (current != NULL) {
        cout << "Name: " << current->name << ", Age: " << current->age << ", Dept: " << current->Dept << "\n";
        current = current->next;
    }
}

int main() {
    int choice;
    do {
        // Create a new node for the student
        student *p = new student;

        // Input student details
        cout << "Enter the name of the student:\n";
        cin >> p->name;
        cout << "Enter the age of the student:\n";
        cin >> p->age;
        cout << "Enter the department of the student:\n";
        cin >> p->Dept;
        p->next = NULL;

        // Menu to choose the insertion type
        cout << "Choose the insertion type:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert after a specific position\n";
        cout << "Enter your choice (1/2/3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert_beg(p);
                break;
            case 2:
                insert_end(p);
                break;
            case 3:
                int position;
                cout << "Enter the position after which to insert: ";
                cin >> position;
                insert_after(position, p);
                break;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
                delete p; // Clean up the node if no valid insertion
                break;
        }

        cout << "\nCurrent List:\n";
        display();

        // Ask if the user wants to insert another node
        cout << "\nDo you want to add another student? (1 for Yes / 0 for No): ";
        cin >> choice;

    } while (choice == 1);

    return 0;
}
