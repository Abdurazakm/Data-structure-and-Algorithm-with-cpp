#include <iostream>
using namespace std;

class ArrayList {
private:
    int* arr;
    int capacity;
    int size;

public:
    ArrayList(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    ~ArrayList() {
        delete[] arr;
    }

    void insertAtEnd(int value) {
        if (isFull()) {
            cout << "List is full, cannot insert." << endl;
            return;
        }
        arr[size] = value;
        size++;
    }

    void insertAtBeginning(int value) {
        if (isFull()) {
            cout << "List is full, cannot insert." << endl;
            return;
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    void insertAtPosition(int pos, int value) {
        if (isFull()) {
            cout << "List is full, cannot insert." << endl;
            return;
        }
        if (pos < 0 || pos > size) {
            cout << "Invalid position." << endl;
            return;
        }
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = value;
        size++;
    }

    void deleteFromEnd() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }
        size--;
    }

    void deleteFromBeginning() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void deleteAtPosition(int pos) {
        if (isEmpty()) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }
        if (pos < 0 || pos >= size) {
            cout << "Invalid position." << endl;
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    bool isFull() const {
        return size == capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void printList() const {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the list: ";
    cin >> capacity;
    ArrayList list(capacity);

    int choice;
    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int insertChoice, value, pos;
            cout << "\nChoose where to insert:\n";
            cout << "1. At the end\n";
            cout << "2. At the beginning\n";
            cout << "3. At a specific position\n";
            cout << "4. Back to main menu\n";
            cout << "Enter your choice: ";
            cin >> insertChoice;

            if (insertChoice == 4) continue;  // Go back to main menu

            cout << "Enter the value to insert: ";
            cin >> value;

            switch (insertChoice) {
                case 1:
                    list.insertAtEnd(value);
                    break;
                case 2:
                    list.insertAtBeginning(value);
                    break;
                case 3:
                    cout << "Enter the position to insert (0 to " << list.getSize() << "): ";
                    cin >> pos;
                    list.insertAtPosition(pos, value);
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            list.printList();

        } else if (choice == 2) {
            int deleteChoice, pos;
            cout << "\nChoose where to delete:\n";
            cout << "1. From the end\n";
            cout << "2. From the beginning\n";
            cout << "3. From a specific position\n";
            cout << "4. Back to main menu\n";
            cout << "Enter your choice: ";
            cin >> deleteChoice;

            if (deleteChoice == 4) continue;  // Go back to main menu

            switch (deleteChoice) {
                case 1:
                    list.deleteFromEnd();
                    break;
                case 2:
                    list.deleteFromBeginning();
                    break;
                case 3:
                    cout << "Enter the position to delete (0 to " << list.getSize() - 1 << "): ";
                    cin >> pos;
                    list.deleteAtPosition(pos);
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            list.printList();

        } else if (choice == 3) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
