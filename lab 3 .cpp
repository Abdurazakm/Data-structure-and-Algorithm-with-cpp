#include <iostream>
#include <cstring>
using namespace std;

// Structure for singly linked list
struct SLLNode {
    char name[20];
    int age;
    char Dept[20];
    SLLNode *next;
};

// Structure for doubly linked list
struct DLLNode {
    char name[20];
    int age;
    char Dept[20];
    DLLNode *prev;
    DLLNode *next;
};

SLLNode *SLLstart = NULL; // Head of singly linked list
DLLNode *DLLstart = NULL; // Head of doubly linked list

// Singly Linked List Functions
void SLL_insert_beg(SLLNode *p) {
    if (SLLstart == NULL) {
        SLLstart = p;
    } else {
        p->next = SLLstart;
        SLLstart = p;
    }
    cout << "Node inserted at the beginning (SLL).\n";
}

void SLL_insert_end(SLLNode *p) {
    if (SLLstart == NULL) {
        SLLstart = p;
    } else {
        SLLNode *current = SLLstart;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = p;
    }
    cout << "Node inserted at the end (SLL).\n";
}

void SLL_insert_after(int position, SLLNode *p) {
    SLLNode *q = SLLstart;
    for (int i = 1; i < position && q != NULL; i++) {
        q = q->next;
    }
    if (q == NULL) {
        cout << "Less than " << position << " nodes in the list!\n";
    } else {
        p->next = q->next;
        q->next = p;
        cout << "Node inserted successfully after position " << position << " (SLL).\n";
    }
}

void SLL_delete_beg() {
    if (SLLstart == NULL) {
        cout << "List is empty (SLL).\n";
    } else {
        SLLNode *temp = SLLstart;
        SLLstart = SLLstart->next;
        delete temp;
        cout << "Node deleted from the beginning (SLL).\n";
    }
}

void SLL_delete_end() {
    if (SLLstart == NULL) {
        cout << "List is empty (SLL).\n";
    } else if (SLLstart->next == NULL) {
        delete SLLstart;
        SLLstart = NULL;
        cout << "Node deleted from the end (SLL).\n";
    } else {
        SLLNode *current = SLLstart;
        while (current->next->next != NULL) {
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
        cout << "Node deleted from the end (SLL).\n";
    }
}

void SLL_display() {
    SLLNode *current = SLLstart;
    if (current == NULL) {
        cout << "List is empty (SLL).\n";
    } else {
        cout << "Singly Linked List:\n";
        while (current != NULL) {
            cout << "Name: " << current->name << ", Age: " << current->age << ", Dept: " << current->Dept << "\n";
            current = current->next;
        }
    }
}

// Doubly Linked List Functions
void DLL_insert_beg(DLLNode *p) {
    if (DLLstart == NULL) {
        DLLstart = p;
    } else {
        p->next = DLLstart;
        DLLstart->prev = p;
        DLLstart = p;
    }
    cout << "Node inserted at the beginning (DLL).\n";
}

void DLL_insert_end(DLLNode *p) {
    if (DLLstart == NULL) {
        DLLstart = p;
    } else {
        DLLNode *current = DLLstart;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = p;
        p->prev = current;
    }
    cout << "Node inserted at the end (DLL).\n";
}

void DLL_display_forward() {
    DLLNode *current = DLLstart;
    if (current == NULL) {
        cout << "List is empty (DLL).\n";
    } else {
        cout << "Doubly Linked List (Forward):\n";
        while (current != NULL) {
            cout << "Name: " << current->name << ", Age: " << current->age << ", Dept: " << current->Dept << "\n";
            current = current->next;
        }
    }
}

void DLL_display_backward() {
    DLLNode *current = DLLstart;
    if (current == NULL) {
        cout << "List is empty (DLL).\n";
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    cout << "Doubly Linked List (Backward):\n";
    while (current != NULL) {
        cout << "Name: " << current->name << ", Age: " << current->age << ", Dept: " << current->Dept << "\n";
        current = current->prev;
    }
}

// Main Function
int main() {
    int choice;
    do {
        cout << "Choose an option:\n";
        cout << "1. Singly Linked List Operations\n";
        cout << "2. Doubly Linked List Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int sub_choice;
                do {
                    cout << "\nSingly Linked List Operations:\n";
                    cout << "1. Insert at the beginning\n";
                    cout << "2. Insert at the end\n";
                    cout << "3. Insert after a position\n";
                    cout << "4. Delete from the beginning\n";
                    cout << "5. Delete from the end\n";
                    cout << "6. Display list\n";
                    cout << "7. Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> sub_choice;

                    switch (sub_choice) {
                        case 1: {
                            SLLNode *p = new SLLNode;
                            cout << "Enter name, age, and department: ";
                            cin >> p->name >> p->age >> p->Dept;
                            p->next = NULL;
                            SLL_insert_beg(p);
                            break;
                        }
                        case 2: {
                            SLLNode *p = new SLLNode;
                            cout << "Enter name, age, and department: ";
                            cin >> p->name >> p->age >> p->Dept;
                            p->next = NULL;
                            SLL_insert_end(p);
                            break;
                        }
                        case 3: {
                            SLLNode *p = new SLLNode;
                            cout << "Enter name, age, and department: ";
                            cin >> p->name >> p->age >> p->Dept;
                            p->next = NULL;
                            int position;
                            cout << "Enter position: ";
                            cin >> position;
                            SLL_insert_after(position, p);
                            break;
                        }
                        case 4:
                            SLL_delete_beg();
                            break;
                        case 5:
                            SLL_delete_end();
                            break;
                        case 6:
                            SLL_display();
                            break;
                        case 7:
                            break;
                        default:
                            cout << "Invalid choice! Try again.\n";
                    }
                } while (sub_choice != 7);
                break;
            }

            case 2: {
                int sub_choice;
                do {
                    cout << "\nDoubly Linked List Operations:\n";
                    cout << "1. Insert at the beginning\n";
                    cout << "2. Insert at the end\n";
                    cout << "3. Display forward\n";
                    cout << "4. Display backward\n";
                    cout << "5. Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> sub_choice;

                    switch (sub_choice) {
                        case 1: {
                            DLLNode *p = new DLLNode;
                            cout << "Enter name, age, and department: ";
                            cin >> p->name >> p->age >> p->Dept;
                            p->prev = p->next = NULL;
                            DLL_insert_beg(p);
                            break;
                        }
                        case 2: {
                            DLLNode *p = new DLLNode;
                            cout << "Enter name, age, and department: ";
                            cin >> p->name >> p->age >> p->Dept;
                            p->prev = p->next = NULL;
                            DLL_insert_end(p);
                            break;
                        }
                        case 3:
                            DLL_display_forward();
                            break;
                        case 4:
                            DLL_display_backward();
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

