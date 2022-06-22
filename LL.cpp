// ***Linked List (Data Structure)*** //

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


// Insert At Tail Singly LL::


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


//Reverse Singly LL

node* reverse(node* &head)

{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while (currptr!= NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
    

}


//Recursive way

node* reverseRecurssive(node* &head)
{
    if ((head = NULL) || (head->next = NULL))
    {
        return head;
    }
    
    node* newhead = reverseRecurssive(head->next);
    head->next->next = head;
    head-> next = NULL;


    return newhead;
}

// Append K nodes of a linked list
// To find the length of LL
int length(node* head){

    int l = 0;
    node* temp =head;

    while (temp!= NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
    
}


// appenend K nodes 

node* Kappend(node* &head, int k)
{
node* newHead;
node* newTail;
node* tail = head;

int l = length(head);
int count = 1;

while (tail-> next != NULL)
{
    if (count == l -k)
    {
        newTail = tail;     
    }
    
    if (count == l - (k+1))
    {
        newHead = tail;
    }

    tail = tail->next;
    count ++;
    
}

newTail-> next = NULL;
tail->next = head;

return newHead;


}

//Function to form a cycle at certain given position:

void makeCycle(node* &head , int pos)

{
    node* temp = head;
    node* startnode;

    int count = 1;

    while(temp-> next != NULL)
    {
        if(count == pos)
        {
            startnode = temp;
        }

        temp = temp-> next;
        count++;
    }

    temp->next = startnode;
}

// Function for detection of cycle in linked list:

bool detectcycle(node* &head)
{
    node* slow = head;
    node* fast = head;

    while(fast!= NULL  && fast->next != NULL)
    {
        slow= slow->next;
        fast = fast->next->next;


    if (fast == slow)
    {
        return true;
    }
    
    }

    return false;
}

// Remove Cycle

void RemoveCycle(node* &head)
{
    node* fast = head;
    node* slow = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
} while(slow!= fast);
    

    fast = head;
    while((fast->next) != (slow-> next))  
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
    
    
}


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

// Function to merge 2 singly LL 

node* merge(node* &head1, node* &head2)
{
    node* p1 = head1;
    node* p2 = head2;
    node* dummyNode = new node(-1);
    node* p3 = dummyNode;

    while(p1 != NULL   && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3 ->next = p1;
            p1 = p1 -> next;
        }

        else
        {
            p3->next = p2;
            p2 = p2->next;
        }

        p3 = p3->next;

    }


    while(p1 != NULL)
    {
        p3->next =p1;
        p1 = p1->next;
        p3 = p3-> next;
    }

    while(p2 != NULL)
    {
        p3->next =p2;
        p2 = p2->next;
        p3 = p3-> next;
    }
    
    return dummyNode->next ;
}



// Even Element After ODD element

void evenAfterOdd(node* &head)
{
    node* odd = head;
    node* even = head-> next;

    node* evenstart = even;

    while (odd-> next != NULL  &&  even-> next != NULL)
    {
        odd->next = even->next;
        odd= odd->next;

        even-> next = odd-> next;
        even = even->next;
    }

    odd->next = evenstart;

    if (odd->next!=NULL)
    {
        even->next = NULL;
    }
    
    
}




// Function to merge 2 LL (Recurssive way) 

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

// Function to intersect 2 LL::

void intersect(node* &head1, node* &head2, int pos)
{

    node* temp1 = head1;
    pos--;

    while (pos--)
    {
        temp1 = temp1->next;
    }

    node* temp2 = head2;
    while (temp2 -> next != NULL)
    {
        temp2 = temp2->next;
    }
    
    temp2->next = temp1;
}


// Function to find intersection point of 2 LL:::

int intersection(node* head1 , node* head2)
{
int l1 = length(head1);
int l2 = length(head2);

int d = 0;

node* ptr1;
node* ptr2;
if (l1 > l2)
{
    d = l1 -l2;

    ptr1 = head1;
    ptr2 = head2;
}

else
{
    d = l2 -l1;

    ptr1 = head2;
    ptr2 = head1;
}

while(d)
{
    ptr1 = ptr1->next;
    
    if(ptr1 == NULL)
    {
        return -1;

    }
    d--;
}

while(ptr1 != NULL && ptr2 != NULL)
{
    if (ptr1 == ptr2)
    {
        return ptr1-> data;
    }

    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
    
}

return -1;



}





//Main Function Edit accoudingly..

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



// // Doubly linked list:::

// #include<iostream>
// using namespace std;


// class node{
//     public:

//     int data;
//     node* next;
//     node* prev;

//     node(int val){
//         data = val;
//         next = NULL;
//         prev = NULL;


//     }
// };


// void insertAthead(node* &head , int val)
// {

//     node* n = new node(val);
//     n->next = head;
//     if (head !=NULL)
//     {
//         head->prev = n;
//     }

//     head = n;
    
// }


// void insertAtTail(node* &head, int val)
// {
//     if(head == NULL)
//     {
//         insertAthead(head,val);
//         return;
//     }
//         node* n = new node(val);
//         node* temp = head;

//         while (temp->next != NULL) 
//         {
//             temp = temp-> next;
//         }

//         temp->next = n;
//         n->prev = temp;
        
// }


// void display(node* head)
// {
//     node* temp = head;
//     while (temp != NULL)
//     {
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout<<endl;
    
// }


// int main()
// {
//     node* head = NULL;
//     insertAtTail(head,1);
//     insertAtTail(head,2);
//     insertAtTail(head,3);
//     insertAtTail(head,4);
//     insertAtTail(head,5);
//     insertAthead(head,6);
//     display(head);
//     return 0;
// }



// #include<iostream>

// using namespace std;

// class node
// {

// public:
//     int data;
//     node* next;

//     node(int val)
//     {
//         data = val;
//         next = NULL;
//     }

// };

// // Insert At Head Function::

// void insertAtHead(node* &head, int val){
//     node* n = new node(val);

//     if(head == NULL){
//         n->next = n;
//         head =n;
//         return;
//     }

//     node* temp = head;

//     while(temp->next != head)
//     {
//         temp = temp->next;
//     }

//     temp->next = n;
//     n->next = head;
//     head =n;
    
// }

// void insertAtTail(node* &head, int val){

//     if(head == NULL)
//     {
//         insertAtHead(head,val);
//         return;
//     }
//     node* n = new node(val);
//     node* temp = head;

//     while(temp->next != head){
//         temp = temp->next;
//     }

//     temp->next = n;
//     n->next = head;

//     }



// //To deleteNode At Head::

// void deleteAtHead(node* &head){

//     node* temp = head;

//     while(temp -> next != head)
//     {
//         temp = temp->next;
//     }

//     node* todelete = head;
//     temp->next = head->next;
//     head = head->next;

//     delete todelete;
    
// }

// // Function to delete Node at certain position ([pos])

// void deletion(node* & head, int pos)

// {
//     if(pos == 1)
//     {
//         deleteAtHead(head);
//         return;
//     }

//     node* temp = head;
//     int count = 1;

//     while(count!= (pos -1))
//     {
//         temp = temp-> next;
//         count ++;
//     }

//     node* todelete = temp->next;
//     temp->next = temp->next->next;

//     delete todelete;
    
    
// }
// void display(node* head){

//     node* temp = head;
//     do
//     {
//         cout<<temp->data<<" ";
//         temp = temp->next;
// } while (temp!= head);
// cout<<endl;
    
// }


// // int main()
// // {
// //     node* head = NULL;

// //     int arr1[] = {2,4,6,8,10};
// //     for (int  i = 0; i < 5; i++)
// //     {
// //         insertAtTail(head,arr1[i]);
// //     }
    
// //     display(head);
// //     // insertAtHead(head,12);
// //     // display(head);

// //     deletion(head,1);
// //     display(head);
// //     return 0;
// // }

