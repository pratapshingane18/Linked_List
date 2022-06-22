/*

if we have linked list like 

1-2-3-4-5-6

we have to make it 

2-1-4-3-6-5

*/

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

void deletionAthead(node* &head)
    {
        node* todelete = head;
        head = head-> next;

        delete todelete;
    }

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

// node* reverse(node* &head)

// {
//     node* prevptr = NULL;
//     node* currptr = head;
//     node* nextptr;

//     while (currptr!= NULL)
//     {
//         nextptr = currptr->next;
//         currptr->next = prevptr;

//         prevptr = currptr;
//         currptr = nextptr;
//     }

//     return prevptr;
    

// }


//Recursive way

// node* reverseRecurssive(node* &head)
// {
//     if ((head = NULL) || (head->next = NULL))
//     {
//         return head;
//     }
    
//     node* newhead = reverseRecurssive(head->next);
//     head->next->next = head;
//     head-> next = NULL;


//     return newhead;
// }


// Reverse K nodes

node* reverseKnodes(node* &head, int k)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count = 0;

    while ((currptr != NULL) && (count < k))    
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;

        count ++;

    }

    if(nextptr != NULL)
    {
        head->next = reverseKnodes(nextptr,k);
    }

    return prevptr;
    
}

void Display(node* head)
{
    node* temp = head;
    while (head != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp-> next;
    }

    cout<<endl;

    
}



int main()
{
    node * head= NULL;

    insertAthead(head ,1);
    insertAthead(head, 2);

    insertAthead(head, 3);
    insertAthead(head, 4);
    insertAthead(head, 5);
    insertAthead(head, 6);
    // insertAthead(head, 7);
    // insertAthead(head, 8);

    // Deletion(head, 4);
    // deletionAthead(head);

    //Display(head);
    int k = 2;
    node* Newhead = reverseKnodes(head, k);

    
    //Display(head);
    Display(Newhead);
    return 0;
}


