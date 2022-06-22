//Q.Implement operations insert at begin, delete at rear and display the linked list.
//Name:Atharva Rajesh Dixit
//PRN:2020BTEIT00051(Batch S4)

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    
}
NODE;
NODE *st=NULL;

NODE* createnode(int d)
{
    NODE a=(NODE)malloc(sizeof(NODE));
    
    a->data=d;
    a->next=NULL;
    return a;    
}

void display()
{
    NODE *a=st;
    if(st==NULL)
       printf("\n empty list");
    else
    {
        printf("\n data");
    
    while(a!=NULL)
    {
        printf("%4d",a->data);
        a=a->next;
    }
     }
}

void addbegin(int d)
{
    NODE *a=st;
    a=createnode(d);
    a->next=st;
    st=a;
}

void delrear()
{
    if(st==NULL)
        printf("list is empty");
    else
    {
        NODE *a=st;
             while(a->next->next!=NULL)
                 a=a->next;
        NODE *temp;
        temp=a->next;
        a->next=NULL;
        free(temp);
                 
        
    }
}

int main()
{
    int opt;
    int d;
    while(1)
    {
        printf("\n menu\n1.Add at begin\n2.display\n3.delete at rear\n4.Exit\n");
        printf("enter option\n");
        scanf("%d",&opt);
        if(opt>3)
           break;
        switch(opt)
        {
		case 1:
                printf("\n add data at begin\n");
                scanf("%d",&d);
                addbegin(d);
		break;
		case 2:
                display();
		break;
		case 3:
                delrear();
		break;
        }
        
    }
return 0;
}