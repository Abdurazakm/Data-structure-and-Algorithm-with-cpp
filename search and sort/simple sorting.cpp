#include<iostream>
using namespace std;
void simple_sorting(int list[], int size_of_list){
    for (int i = 0; i < size_of_list - 2; i++)
    {
        for (int j = i + 1; j < size_of_list - 1; j++)
        {
            if(list[i]>list[j])
            swap(list[i],list[j])
        }
        
    }
    

}

void bubble_sorting(int list[], int size_of_list){
    for (int i = size_of_list-2; i >=0;  i--)
    {
        for (int j = 0; j <=i; j++)
        {
            if (list[j] > list[j+1])
            swap(list[j],list[j+1])
        }
        
    }
    
}
int main(){
    int n = 9
    int list[n] = {6,2,9,4,1,12,43,76,98};
    cout << "The values before sorting are: \n";
    for(int i = 0; i < n; i++)
    cout << list[i] << " ";
    cout<<"by which method do you want sort data for simple press 1\nbubble press 2"<<endl;
    cin>>int choice;
    if (choice == 1)
    {
        simple_sorting(list, n);
    }
    els
    
    
    

    cout << endl;
    cout << "The values after sorting are: \n";
    for(int i = 0; i < n; i++)
    cout << list[i] << " ";

    
    return 0;
}