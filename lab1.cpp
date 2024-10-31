#include <iostream>
#include<algorithm>
using namespace std;
int linear_search(int list[], int key)
{
    int index = -1;
    for (int i = 0; i < 7; i++)
    {
        if (list[i] == key)
        {
            index = i;
            break;
        }
    }
    return index;
}

int binear_search(int list[], int key)
{
    int n = 5;
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

void check(int i, int key)
{
    if (i == -1)
    {
        cout << key << " is not found in the list" << endl;
    }
    else
        cout << key << " found at index " << i << endl;
}

void bubble_sorting(int list[], int size_of_list){
    for (int i = size_of_list-2; i >=0;  i--)
    {
        for (int j = 0; j <=i; j++)
        {
            if (list[j] > list[j+1])

            { 
                swap(list[j],list[j+1]);
                }
        }
        
    }
    
}


void simple_sorting(int list[], int size_of_list){
    for (int i = 0; i < size_of_list - 2; i++)
    {
        for (int j = i + 1; j < size_of_list - 1; j++)
        {
            if(list[i]>list[j])
            swap(list[i],list[j]);
        }
        
    }
}
    

void selection(int list[], int size){
    int index;
    int j;
    int mnm;
    for (int i = 0; i < size-1; i++)
    {
        mnm = list[i];
        index = i;
        for (j = i+1; j <=size-1; j++)
        {
            
            if (list[i] > list[j])
            {
                mnm = list[j];
                index = j;
            }  
        }
        j=index;
        list[j] = list[i];
        list[i] = mnm;
    }
 
}

void insertion_sorting(int list[], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j--)
        {
            if(list[j-1]>list[j]){
                swap(list[j-1],list[j]);
            }
            else
            break;
        }
        
    }
    
}

int main()
{
    int i, size, choice;
    cout << "enter the soze of data" << endl;
    cin >> size;
    int list[size];
    cout << "enter the data" << endl;
    for (i = 0; i < size; i++)
    {
        cout << "enter the first " << i + 1;
        cin >> list[i];
    }

   back_to_home:

    cout << "what do you want" << endl;
    cout << "for search press 1\n for sort press 2" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "by which method do you want" << endl;
        cout << "for sequential press 1\n for simple press 2" << endl;
        int searching_choice;
        cin >> searching_choice;
        switch (searching_choice)
        {
        case 1:

            cout << "enter the number you want search" << endl;
            int key;
            cin >> key;
            int searchIndex = linear_search(list, key);
            check(searchIndex, key);
            // break;
        case 2:
            cout << "enter the number you want search" << endl;
            cin >> key;
            searchIndex = linear_search(list, key);
            check(searchIndex, key);
            break;
        case 3:
            goto back_to_home;
            break;

        default:
            cout<< "invaled input"<<endl;

            
        }
    case 2:

        int sorting_choice;
        cout << "The values before sorting are: \n";
        for(i = 0; i < size; i++)
            cout << list[i] << " ";
        cout<<"by which method do you want sort data \nfor simple press 1 \n bubble press 2\ninsertion press 3\nselection press 4"<<endl;
        cin>>sorting_choice;
        switch (sorting_choice)
        {
        case 1:
            simple_sorting(list, size);
            break;
        case 2:
          bubble_sorting(list, size);
          break;
        case 3:
          insertion_sorting(list, size);
        case 4:
          goto back_to_home;

        default:
            cout<< "invaled input"<<endl;
            break;
        }

    case 3:
      return 0;

        break;

    default:
      cout<< "invaled input"<<endl;
        break;
    }
}