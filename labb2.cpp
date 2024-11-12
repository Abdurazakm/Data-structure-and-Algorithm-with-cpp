#include <iostream>
using namespace std;

class ArrayList
{
private:
    int *listArr;
    int maxsize;
    int list_of_size;

public:
    ArrayList(int capacity_of_arry)
    {
        maxsize = capacity_of_arry;
        listArr = new int[maxsize];
        list_of_size = 0;
    }
    ~ArrayList()
    {
        delete[] listArr;
    }
    void insert_at_end(int insertion_value)
    {
        if (list_of_size == maxsize)
        {
            cout << "List is full, cannot insert." << endl;
            return;
        }
        listArr[list_of_size] = insertion_value;
        list_of_size++;
    }

    void insert_at_the_beg(int insertion_value)
    {
        if (list_of_size == maxsize)
        {
            cout << "List is full, cannot insert." << endl;
            return;
        }
        for (int i = list_of_size; i > 0; i--)
        {
            listArr[i] = listArr[i - 1];
        }
        listArr[0] = insertion_value;
        list_of_size++;
    }
    void insert_somewhere_at_middle(int pos, int insertion_value)
    {
        if (list_of_size == maxsize)
        {
            cout << "List of full, cannot insert." << endl;
            return;
        }
        if (pos < 0 || pos > list_of_size)
        {
            cout << "Invalid position." << endl;
            return;
        }
        for (int i = list_of_size; i > pos; i--)
        {
            listArr[i] = listArr[i - 1];
        }
        listArr[pos] = insertion_value;
        list_of_size++;
    }

    int getSize() const
    {
        return list_of_size;
    }
    // deletion
    void deletion_from_beg()
    {
        if (list_of_size == 0)
        {
            cout << "The list is empty, can not delete." << endl;
            return;
        }
        for (int i = 0; i < list_of_size - 1; i++)
        {
            listArr[i] = listArr[i + 1];
        }
        list_of_size--;
    }

    void deletion_at_end(){
    if (list_of_size == 0)
    {
        cout<<"The list is empty, can not delete."<<endl;
        return;
    }
    list_of_size--;
    
    }
    void deletion_at_somewhere(int pos){
        if (list_of_size == 0)
        {
            cout<<"The list is empty, can not delete."<<endl;
            return;
        }
        if (pos<0 ||pos>=list_of_size)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        for (int i = pos; i < list_of_size-1; i++)
        {
            listArr[i]=listArr[i+1];
        }
        list_of_size--;
        
        
        
    }
    void print_of_arrey() const
    {
        if (list_of_size == 0)
        {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "list of array look like." << endl;
        cout << "[ ";
        for (int i = 0; i < list_of_size; i++)
        {
            cout << listArr[i] << ", ";
        }
        cout << "]";
    }
};
int main()
{
    int capacity_of_arry;
    cout << "Enter the capacity of the list: ";
    cin >> capacity_of_arry;
    ArrayList list(capacity_of_arry);

    int choice;
    while (true)
    {
        cout << "\n----------------------\nChoose an operation:\n--------------------------\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int insertChoice, value, pos;
            cout << "\nChoose where to insert:\n";
            cout << "1. insert at the end\n";
            cout << "2. insert at the beginning\n";
            cout << "3. insert at somewhere in the middle\n";
            cout << "4. Back to main menu\n";
            cout << "Enter your choice: ";
            cin >> insertChoice;

            if (insertChoice == 4)
                continue;

            cout << "Enter the value to insert: ";
            cin >> value;

            switch (insertChoice)
            {
            case 1:
                list.insert_at_end(value);
                break;
            case 2:
                list.insert_at_the_beg(value);
                break;
            case 3:
                cout << "Enter the position to insert (0 to " << list.getSize() << "): ";
                cin >> pos;
                list.insert_somewhere_at_middle(pos, value);
                break;
            default:
                cout << "Invalid choice!" << endl;
            }
            list.print_of_arrey();
        }
        else if (choice == 2) {
            int deleteChoice, pos;
            cout << "\nChoose where to delete:\n";
            cout << "1. Delete From the end\n";
            cout << "2. Delete From the beginning\n";
            cout << "3. Delete From a somewhere in the middle\n";
            cout << "4. Back to main menu\n";
            cout << "Enter your choice: ";
            cin >> deleteChoice;

            if (deleteChoice == 4) continue;  

            switch (deleteChoice) {
                case 1:
                    list.deletion_at_end();
                    break;
                case 2:
                    list.deletion_from_beg();
                    break;
                case 3:
                    cout << "Enter the position to delete (0 to " << list.getSize() - 1 << "): ";
                    cin >> pos;
                    list.deletion_at_somewhere(pos);
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            list.print_of_arrey();

        } else if (choice == 3) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}