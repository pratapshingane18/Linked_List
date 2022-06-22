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

// Insert At Head Function::

void insertAtHead(node* &head, int val){
    node* n = new node(val);

    if(head == NULL){
        n->next = n;
        head =n;
        return;
    }

    node* temp = head;

    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head =n;
    
}

void insertAtTail(node* &head, int val){

    if(head == NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;

    }



//To deleteNode At Head::

void deleteAtHead(node* &head){

    node* temp = head;

    while(temp -> next != head)
    {
        temp = temp->next;
    }

    node* todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
    
}

// Function to delete Node at certain position ([pos])

void deletion(node* & head, int pos)

{
    if(pos == 1)
    {
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;

    while(count!= (pos -1))
    {
        temp = temp-> next;
        count ++;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
    
    
}
void display(node* head){

    node* temp = head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
} while (temp!= head);
cout<<endl;
    
}


int main()
{
    node* head = NULL;

    int arr1[] = {2,4,6,8,10};
    for (int  i = 0; i < 5; i++)
    {
        insertAtTail(head,arr1[i]);
    }
    
    display(head);
    // insertAtHead(head,12);
    // display(head);

    deletion(head,1);
    display(head);
    return 0;
}

