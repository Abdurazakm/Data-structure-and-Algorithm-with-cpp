#include<iostream>
using namespace std;
int main(){
    int list[] = {7,9,11,3};
    int index;
    int j;
    int mnm;
    for (int i = 0; i < 3; i++)
    {
        mnm = list[i];
        index = i;
        for (j = i+1; j <=3; j++)
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
    for (int i = 0; i < 4; i++)
    {
       cout<<list[i]<<" ";
    } 
  return 0;  
}