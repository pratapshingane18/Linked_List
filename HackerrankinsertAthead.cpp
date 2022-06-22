// #include <bits/stdc++.h>

// using namespace std;

// class SinglyLinkedListNode {
//     public:
//         int data;
//         SinglyLinkedListNode *next;

//         SinglyLinkedListNode(int node_data) {
//             this->data = node_data;
//             this->next = nullptr;
//         }
// };

// class SinglyLinkedList {
//     public:
//         SinglyLinkedListNode *head;
//         SinglyLinkedListNode *tail;

//         SinglyLinkedList() {
//             this->head = nullptr;
//             this->tail = nullptr;
//         }

// };

// void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
//     while (node) {
//         fout << node->data;

//         node = node->next;

//         if (node) {
//             fout << sep;
//         }
//     }
// }

// void free_singly_linked_list(SinglyLinkedListNode* node) {
//     while (node) {
//         SinglyLinkedListNode* temp = node;
//         node = node->next;

//         free(temp);
//     }
// }

// // Complete the insertNodeAtHead function below.

// /*
//  * For your reference:
//  *
//  * SinglyLinkedListNode {
//  *     int data;
//  *     SinglyLinkedListNode* next;
//  * };
//  *
//  */
// SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
// SinglyLinkedListNode* n = new SinglyLinkedListNode(data);

// n-> next = llist;
// llist = n;
// return n;
// }

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     SinglyLinkedList* llist = new SinglyLinkedList();

//     int llist_count;
//     cin >> llist_count;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     for (int i = 0; i < llist_count; i++) {
//         int llist_item;
//         cin >> llist_item;
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
//       	SinglyLinkedListNode* llist_head = insertNodeAtHead(llist->head, llist_item);
//         llist->head = llist_head;
//     }

//     print_singly_linked_list(llist->head, "\n", fout);
//     fout << "\n";

//     free_singly_linked_list(llist->head);

//     fout.close();

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

class Head{
    public:
    int count;
    Node *first;
    Node *last;

    Head(int c, Node* &f, Node* &l){
        this->count = c;
        this->first = Node* f;
        this->last = Node* l;
    }
};

void insertAtHead(Head *head, int data){
    Node *newNode = new Node(data);
    
    if(head->count == 0){
        head->first = newNode;
        head->last = newNode;

        head->first->next = head->last;
        head->last->next = head->first;
    }
    else{
        newNode->next = head->first;
        head->first = newNode;
        head->last->next = head->first;
    }
    head->count++;
}

void insertAtTail(Head *head, int data){
    Node *newNode = new Node(data);
    
    if(head->count == 0){
        head->first = newNode;
        head->last = newNode;

        head->first->next = head->last;
        head->last->next = head->first;
    }
    else{
        head->last->next = newNode;
        head->last = newNode;
        head->last->next = head->first;
    }
    head->count++;
}

void insertAfter(Head *head, int data, int pos){
    Node *newNode = new Node(data);
    Node *temp = head->first;
    Node *prev = head->first;

    if(pos == 1){
        insertAtHead(head, data);
    }
    else if(pos == head->count + 1){
        insertAtTail(head, data);
    }
    else{
        for(int i = 1; i < pos; i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = newNode;
        newNode->next = temp;
        head->count++;
    }
}

void deleteByValue(Head *head, int data){
    Node *temp = head->first;
    Node *prev = head->first;

    if(head->count == 0){
        cout << "List is empty" << endl;
    }
    else if(head->count == 1){
        if(head->first->data == data){
            head->first = NULL;
            head->last = NULL;
            head->count--;
        }
        else{
            cout << "Element not found" << endl;
        }
    }
    else{
        if(head->first->data == data){
            head->first = head->first->next;
            head->last->next = head->first;
            head->count--;
        }
        else{
            while(temp->data != data){
                prev = temp;
                temp = temp->next;
            }
            if(temp->data == data){
                prev->next = temp->next;
                head->count--;
            }
            else{
                cout << "Element not found" << endl;
            }
        }
    }
}

void deleteByPos(Head *head, int pos){
    Node *temp = head->first;
    Node *prev = head->first;

    if(head->count == 0){
        cout << "List is empty" << endl;
    }
    else if(head->count == 1){
        if(pos == 1){
            head->first = NULL;
            head->last = NULL;
            head->count--;
        }
        else{
            cout << "Element not found" << endl;
        }
    }
    else{
        if(pos == 1){
            head->first = head->first->next;
            head->last->next = head->first;
            head->count--;
        }
        else if(pos == head->count){
            while(temp->next != head->first){
                prev = temp;
                temp = temp->next;
            }
            prev->next = head->first;
            head->last = prev;
            head->count--;
        }
        else{
            for(int i = 1; i < pos; i++){
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            head->count--;
        }
    }
}

void displayList(Head *head){
    Node *temp = head->first;

    if(head->count == 0){
        cout << "List is empty" << endl;
    }
    else{
        for(int i=0; i<head->count; i++){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(){
    Head* h = new Head(0, NULL, NULL);

    int opt, data, index;
    char choice;
    while(1){
        cout<<"Enter the choice: \nMENU 1.0\n 1.Add at Beginning\n 2.Add at End\n 3.Add after\n 4.Delete (by Value)\n 5.Delete (by Index))\n 6.Display the List\n 8.Exit\n";
            
            cin>>choice;
            cout<<"\n";
            if(choice>7) break;

            switch(choice){

                case 1:
                    cout<<"Enter data to add: ";
                    cin>>data;
                    cout<<"Adding data...\n";
                    insertAtHead(h, data);
                    cout<<"\n";
                    break;

                case 2:
                    cout<<"Enter data to add: ";
                    cin>>data;
                    cout<<"Adding data...\n";
                    insertAtTail(h, data);
                    cout<<"\n";
                    break;
                
                case 3:
                    cout<<"Enter the index: ";
                    cin>>index;
                    cout<<"Enter data to add: ";
                    cin>>data;
                    cout<<"Adding data...\n";
                    insertAfter(h, data, index);
                    cout<<"\n";
                    break;
                
                case 4:
                    cout<<"Enter data to delete: ";
                    cin>>data;
                    cout<<"Deleting data...\n";
                    deleteByValue(h, data);
                    cout<<"\n";
                    break;

                case 5:
                    cout<<"Enter the index: ";
                    cin>>index;
                    cout<<"Deleting data...\n";
                    deleteByPos(h, index);
                    cout<<"\n";
                    break;
                
                case 6:
                    cout<<"Displaying the LinkedList: ";
                    displayList(h);
                    cout<<"\n";
                    break;
                
                default: 
                    break;

            }
        }

    return 0;
}