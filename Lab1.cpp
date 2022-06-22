/*Singly Linked List Problem 
//PRN 2020BTEIT00050
//BATCH 4*/
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

//Insert At Head Singly LL

void insertAthead(node* &head, int val)
{
    node* n = new node(val);

    n-> next = head;
    head = n;
}

// Delete At head::

void deletionAthead(node* &head)
    {
        node* todelete = head;
        head = head-> next;

        delete todelete;
    }

// Delete certain element::

void Deletion(node* &head, int val)
{
    if (head = NULL)
    {
        return;
    }

    if (head-> next = NULL)
    {
        deletionAthead(head);
        return;
    }
    
    
    node* temp = head;
    while (temp-> next-> data != val)                       
    {
        temp = temp-> next;
    }
    
    node* todelete = temp-> next;
    temp-> next = temp-> next -> next;

    delete todelete;
}

//Display Function::

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

    insertAthead(head,5);
    insertAthead(head,4);
    insertAthead(head,3);
    insertAthead(head,2);
    
    Display(head);
    Deletion(head, 4);
    deletionAthead(head);

    Display(head);
    return 0;
}

