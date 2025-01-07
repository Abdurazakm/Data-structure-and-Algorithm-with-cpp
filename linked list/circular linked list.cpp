#include <iostream>
#include <cstring>
using namespace std;

// Structure for Circular Singly Linked List
struct CSLLNode {
    char name[20];
    int age;
    char Dept[20];
    CSLLNode *next;
};

// Structure for Circular Doubly Linked List
struct CDLLNode {
    char name[20];
    int age;
    char Dept[20];
    CDLLNode *prev;
    CDLLNode *next;
};

CSLLNode *CSLLstart = NULL; // Head of Circular Singly Linked List
CDLLNode *CDLLstart = NULL; // Head of Circular Doubly Linked List

// Circular Singly Linked List Functions
void CSLL_insert_beg(CSLLNode *p) {
    if (CSLLstart == NULL) {
        CSLLstart = p;
        p->next = p; // Point to itself
    } else {
        CSLLNode *temp = CSLLstart;
        while (temp->next != CSLLstart)
            temp = temp->next;
        temp->next = p;
        p->next = CSLLstart;
        CSLLstart = p;
    }
}

void CSLL_insert_end(CSLLNode *p) {
    if (CSLLstart == NULL) {
        CSLLstart = p;
        p->next = p; // Point to itself
    } else {
        CSLLNode *temp = CSLLstart;
        while (temp->next != CSLLstart)
            temp = temp->next;
        temp->next = p;
        p->next = CSLLstart;
    }
}

void CSLL_display() {
    if (CSLLstart == NULL) {
        cout << "List is empty (CSLL).\n";
        return;
    }
    CSLLNode *temp = CSLLstart;
    cout << "Circular Singly Linked List:\n";
    do {
        cout << "Name: " << temp->name << ", Age: " << temp->age << ", Dept: " << temp->Dept << "\n";
        temp = temp->next;
    } while (temp != CSLLstart);
}

// Circular Doubly Linked List Functions
void CDLL_insert_beg(CDLLNode *p) {
    if (CDLLstart == NULL) {
        CDLLstart = p;
        p->next = p;
        p->prev = p;
    } else {
        CDLLNode *last = CDLLstart->prev;
        p->next = CDLLstart;
        p->prev = last;
        last->next = p;
        CDLLstart->prev = p;
        CDLLstart = p;
    }
}

void CDLL_insert_end(CDLLNode *p) {
    if (CDLLstart == NULL) {
        CDLLstart = p;
        p->next = p;
        p->prev = p;
    } else {
        CDLLNode *last = CDLLstart->prev;
        p->next = CDLLstart;
        p->prev = last;
        last->next = p;
        CDLLstart->prev = p;
    }
}

void CDLL_display_forward() {
    if (CDLLstart == NULL) {
        cout << "List is empty (CDLL).\n";
        return;
    }
    CDLLNode *temp = CDLLstart;
    cout << "Circular Doubly Linked List (Forward):\n";
    do {
        cout << "Name: " << temp->name << ", Age: " << temp->age << ", Dept: " << temp->Dept << "\n";
        temp = temp->next;
    } while (temp != CDLLstart);
}

void CDLL_display_backward() {
    if (CDLLstart == NULL) {
        cout << "List is empty (CDLL).\n";
        return;
    }
    CDLLNode *temp = CDLLstart->prev;
    cout << "Circular Doubly Linked List (Backward):\n";
    do {
        cout << "Name: " << temp->name << ", Age: " << temp->age << ", Dept: " << temp->Dept << "\n";
        temp = temp->prev;
    } while (temp != CDLLstart->prev);
}

// Main Function
int main() {
    int choice;
    do {
        cout << "Choose an option:\n";
        cout << "1. Circular Singly Linked List Operations\n";
        cout << "2. Circular Doubly Linked List Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int sub_choice;
            do {
                cout << "\nCircular Singly Linked List Operations:\n";
                cout << "1. Insert at the beginning\n";
                cout << "2. Insert at the end\n";
                cout << "3. Display list\n";
                cout << "4. Back to main menu\n";
                cout << "Enter your choice: ";
                cin >> sub_choice;

                switch (sub_choice) {
                case 1: {
                    CSLLNode *p = new CSLLNode;
                    cout << "Enter name, age, and department: ";
                    cin >> p->name >> p->age >> p->Dept;
                    p->next = NULL;
                    CSLL_insert_beg(p);
                    break;
                }
                case 2: {
                    CSLLNode *p = new CSLLNode;
                    cout << "Enter name, age, and department: ";
                    cin >> p->name >> p->age >> p->Dept;
                    p->next = NULL;
                    CSLL_insert_end(p);
                    break;
                }
                case 3:
                    CSLL_display();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid choice! Try again.\n";
                }
            } while (sub_choice != 4);
            break;
        }

        case 2: {
            int sub_choice;
            do {
                cout << "\nCircular Doubly Linked List Operations:\n";
                cout << "1. Insert at the beginning\n";
                cout << "2. Insert at the end\n";
                cout << "3. Display forward\n";
                cout << "4. Display backward\n";
                cout << "5. Back to main menu\n";
                cout << "Enter your choice: ";
                cin >> sub_choice;

                switch (sub_choice) {
                case 1: {
                    CDLLNode *p = new CDLLNode;
                    cout << "Enter name, age, and department: ";
                    cin >> p->name >> p->age >> p->Dept;
                    p->next = p->prev = NULL;
                    CDLL_insert_beg(p);
                    break;
                }
                case 2: {
                    CDLLNode *p = new CDLLNode;
                    cout << "Enter name, age, and department: ";
                    cin >> p->name >> p->age >> p->Dept;
                    p->next = p->prev = NULL;
                    CDLL_insert_end(p);
                    break;
                }
                case 3:
                    CDLL_display_forward();
                    break;
                case 4:
                    CDLL_display_backward();
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid choice! Try again.\n";
                }
            } while (sub_choice != 5);
            break;
        }

        case 3:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
