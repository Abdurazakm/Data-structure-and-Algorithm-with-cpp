#include <iostream>
#include <algorithm>
using namespace std;
// linear or squential search
int linear_search(int list[], int key, int size) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (list[i] == key) {
            index = i;
            break;
        }
    }
    return index;
}
// binary search
int binary_search(int list[], int key, int size) {
    int bottom = 0, top = size - 1, middle;
    while (bottom <= top) {
        middle = bottom + (top - bottom) / 2;
        if (list[middle] == key) {
            return middle;
        } else if (list[middle] < key) {
            bottom = middle + 1;
        } else {
            top = middle - 1;
        }
    }
    return -1;
}
// check if the search index found or not in the list
void check(int i, int key) {
    if (i == -1) {
        cout << key << " is not found in the list" << endl;
    } else {
        cout << key << " found at index " << i << endl;
    }
}
// sorting type 
// bubble sorting algorithm
void bubble_sorting(int list[], int size_of_list) {
    for (int i = size_of_list - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1]);
            }
        }
    }
}
// simple sorting 
void simple_sorting(int list[], int size_of_list) {
    for (int i = 0; i < size_of_list - 1; i++) {
        for (int j = i + 1; j < size_of_list; j++) {
            if (list[i] > list[j]) {
                swap(list[i], list[j]);
            }
        }
    }
}
// selection sorting
void selection_sort(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (list[j] < list[minIndex]) {
                minIndex = j;
            }
        }
        swap(list[i], list[minIndex]);
    }
}
// insertion sorting
void insertion_sort(int list[], int size) {
    for (int i = 1; i < size; i++) {
        int key = list[i];
        int j = i - 1;
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

// Function for Binary Insertion Sort
void binary_insertion_sort(int list[], int size) {
    for (int i = 1; i < size; i++) {
        int key = list[i];
        int bottom = 0, top = i - 1;

        // Binary search to find the position for insertion
        while (bottom <= top) {
            int mid = bottom + (top - bottom) / 2;
            if (list[mid] <= key) {
                bottom = mid + 1;
            } else {
                top = mid - 1;
            }
        }

        // Shift elements to make space for key
        for (int j = i; j > bottom; j--) {
            list[j] = list[j - 1];
        }
        list[bottom] = key;
    }
}

// main function
int main() {
    int i, size, choice;
    cout << "Enter the size of the data: ";
    cin >> size;
    int list[size];
    cout << "Enter the data elements: " << endl;
    for (i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> list[i];
    }

back_to_home:
cout<<"-----------------------"<<endl;
cout<<"what do you want:"<<endl;
cout<<"1 search"<<endl;
cout<<"2 sort"<<endl;
cout<<"3 Exit"<<endl;
cout<<"-----------------------"<<endl;
cin>>choice;


    
    switch (choice) {
    case 1: {
        cout << "Choose search method:\n1. Linear Search\n2. Binary Search" << endl;
        int searching_choice, key;
        cin >> searching_choice;
        
        cout << "Enter the number you want to search: ";
        cin >> key;
        
        int searchIndex;
        if (searching_choice == 1) {
            searchIndex = linear_search(list, key, size);
        } else if (searching_choice == 2) {
            searchIndex = binary_search(list, key, size);
        } else {
            cout << "Invalid input" << endl;
            goto back_to_home;
        }
        
        check(searchIndex, key);
        break;
    }
    case 2: {
        int sorting_choice;
        cout << "The values before sorting are: ";
        for (i = 0; i < size; i++) cout << list[i] << " ";
        cout << "\nChoose sorting method:\n1. Simple Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Selection Sort\n5. Binary Insertion Sort" << endl;
        cin >> sorting_choice;
        
        switch (sorting_choice) {
        case 1:
            simple_sorting(list, size);
            break;
        case 2:
            bubble_sorting(list, size);
            break;
        case 3:
            insertion_sort(list, size);
            break;
        case 4:
            selection_sort(list, size);
            break;
        case 5:
            binary_insertion_sort(list, size);
            break;
        default:
            cout << "Invalid input" << endl;
            goto back_to_home;
        }
        
        cout << "The values after sorting are: ";
        for (i = 0; i < size; i++) cout << list[i] << " ";
        cout << endl;
        break;
    }
    case 3:
        return 0;
    default:
        cout << "Invalid input" << endl;
        break;
    }

    goto back_to_home;
}
