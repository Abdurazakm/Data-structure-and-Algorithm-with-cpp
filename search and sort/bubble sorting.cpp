#include <iostream>
#include <algorithm>
using namespace std;
void bubble_sorting(int list[], int size)
{
    for (int i = size - 2; i >= 0; i--)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                swap(list[j], list[j + 1]);
            }
        }
    }

    cout << "]";
    for (int j = 0; j < size - 1; j++)
    {
        cout << list[j] << ", ";
    }
    cout << "]";
}
int main()
{
    int size;
    cout << "enter the size of list: ";
    cin >> size;
    int list[size];
    cout << "Enter the data: ";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter nth" << i + 1 << ": ";
        cin >> list[i];
    }
    bubble_sorting(list, size);

    return 0;
}