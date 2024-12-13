#include <iostream>
using namespace std;

int binear_search(int list[], int key);

int main()
{
    int key, n = 5;
    int list[n] = {5, 3, 7, 25};
    cout << "enter the number you want to fine or search" << endl;
    cin >> key;
    int i = binear_search(list, key);
    if (i == -1)
    {
        cout << key << " is not found in the list" << endl;
    }
    else
        cout << key << " found at index " << i << endl;

    return 0;
}

int binear_search(int list[], int key)
{
    int n=5;
    int top = n - 1, bottom = 0, found = 0, index = 0, middle;
    do
    {
        middle = (top - bottom) / 2;
        if (key == list[middle])
            found = 1;

        else
        {
            if (key < list[middle])
                top = middle - 1;
            else
                bottom = middle + 1;
        }
    } while (found == 0 && top >= bottom);
    
    if (found == 0)
        index = -1;
    else
        index = middle;
    return index;
}