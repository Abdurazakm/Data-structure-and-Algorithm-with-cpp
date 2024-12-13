#include<iostream>
using namespace std;
struct student
{
    char name[20];
    int age;
    char dept[20];
    student *next;
};
student *start=NULL;




void insert_beg(student *p){
    if (start==NULL)
    {
        start=p;
    }else{
        p->next=start;
        start=p;

    }
    cout<<"The node inserted at the beginning.\n";
    
}





void insert_end(student *p){
    if (start==NULL)
    {
        start=p;
    }
    else{
        student *temp=start;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
        

    }
}





    void insert_after_node(int position, student *p){
        student *temp=start;
        for (int i = 0; i < position&&temp!=NULL; i++)
        {
            temp=temp->next;
        }
        if (temp==NULL)
        {
            cout<<"the node you want insert at "<<position<<" is less than node in the list\n";
        }
        p->next=temp->next;
        temp->next=p;
        cout << "Node inserted successfully after position " << position << " (SLL).\n";
        
        
        



    }


void SLL_display() {
     student *current = start;
     if (current == NULL) {
        cout << "List is empty (SLL).\n";
    } else {
        cout << "Singly Linked List:\n";
        while (current != NULL) {
            cout << "Name: " << current->name << ", Age: " << current->age << ", Dept: " << current->dept << "\n";
            current = current->next;
        }
    }
}


    

int main(){
    student *p=new student;
    cout<<"Enter the name, age and department:";
    cin>>p->name>>p->age>>p->dept;
    p->next=NULL;
    insert_beg(p);
    SLL_display();
    insert_end(p);
    SLL_display();
    // insert_after_node(1,p);
    return 0;
}
