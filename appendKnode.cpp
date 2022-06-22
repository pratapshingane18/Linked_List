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

// Append K nodes of a linked list

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
    int arr[6] = {1,2,3,4,5,6};
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head,arr[i]);
    }
    Display(head);
    
    node* newhead = Kappend(head,3);
    Display(newhead);
    return 0;
}

