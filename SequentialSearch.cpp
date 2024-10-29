#include<iostream>
using namespace std;
int linear_search(int list[], int key);

int main(){
    int list[7] = {4,6,2,6,7,9,10};
    cout<<"size of list "<<sizeof(list);

    cout<<"enter the number you want search"<<endl;
    int key;
    cin>>key;
    int i = linear_search(list,key);
    if(i == -1){
        cout<<key<<" is not found in the list"<<endl;
    }
    else
    cout<<key<<" found at index "<<i<<endl;


    return 0;
}
int linear_search(int list[], int key){
    int index=-1;
    for ( int i = 0; i < 7; i++)
    {
        if (list[i] == key)
        {
           index = i;
           break;
        }
        
    }
    return index;

    

}