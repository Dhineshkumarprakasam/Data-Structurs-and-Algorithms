
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head=0,*newnode,*temp,*tail;

void atEnd(int x)
{
    newnode=malloc(sizeof(struct node));

    newnode->data=x;
    newnode->prev=0;
    newnode->next=0;

    if(head==0)
    {
        head=newnode;
        tail=newnode;
    }

    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void atBegin(int x)
{
    newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void atPos(int x,int pos)
{
    newnode=malloc(sizeof(struct node));
    newnode->data=x;

    temp=head;
    for(int i=0;i<pos-1;i++)
        temp=temp->next;

    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
}

void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    atEnd(10);
    atEnd(20);
    atEnd(30);
    atBegin(5);
    atPos(6,2);
    display();
}
