#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int x){
    struct Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    cout<<"enqueue: "<<newNode->data<<endl;
    

}
void dequeue(){
    if(front == NULL){
        cout<<"Queue is empity."<<endl;
        return;
    }
    struct Node* temp = front;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    cout<<"dequeue: "<<temp->data<<endl;
    delete temp;
    
    

}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    dequeue();
    dequeue();
    dequeue();

    return 0;
}



