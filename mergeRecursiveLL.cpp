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

// node* merge(node* &head1, node* &head2)
// {
//     node* p1 = head1;
//     node* p2 = head2;
//     node* dummyNode = new node(-1);
//     node* p3 = dummyNode;

//     while(p1 != NULL   && p2 != NULL)
//     {
//         if (p1->data < p2->data)
//         {
//             p3 ->next = p1;
//             p1 = p1 -> next;
//         }

//         else
//         {
//             p3->next = p2;
//             p2 = p2->next;
//         }

//         p3 = p3->next;

//     }


//     while(p1 != NULL)
//     {
//         p3->next =p1;
//         p1 = p1->next;
//         p3 = p3-> next;
//     }

//     while(p2 != NULL)
//     {
//         p3->next =p2;
//         p2 = p2->next;
//         p3 = p3-> next;
//     }
    
//     return dummyNode->next ;
    
// 


//Recurssive way 

node* mergeRecurssive(node* &head1, node* &head2){
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    node* result;
    if(head1-> data  < head2-> data)
    {
       result = head1;
       result-> next = mergeRecurssive(head1-> next, head2);
    }
    

    else{
        result = head2;
        result->next = mergeRecurssive(head1, head2->next);
    }
    
    return result;
    
}


void Display(node* head)
{
    node* temp = head;
    while(head != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp-> next;
    }

    cout<<endl;

    
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    int arr1[] = {1,4,5,7};
    int arr2[] = {2,3,6};

    for(int i = 0; i < 4; i++)
    {
        insertAtTail(head1,arr1[i]);
    }

    for(int i = 0; i < 3; i++)
    {
        insertAtTail(head2,arr1[i]);
    }

    // Display(head1);
    // Display(head2);

    node* newhead = mergeRecurssive(head1,head2);
    Display(newhead);
    
    return 0;
    
}

