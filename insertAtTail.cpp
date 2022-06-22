#include<iostream>

using namespace std;

class node
{

public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }

};

void insertAthead(node* &head, int val)
{
    node* n = new node(val);

    n-> next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    node* temp = head;

    if (head == NULL)
    {
        head = n ;
        return;
    }
    
    while(temp-> next != NULL)
    {
        temp = temp-> next;

    }

    temp->next = n;
}


void Display(node* head)
{
    node* temp = head;
    while (head != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp-> next;
    }

    cout<<endl;

    
}

int main()
{
    node * head= NULL;

    insertAtTail(head ,2);
    
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    Display(head);
    return 0;
}

