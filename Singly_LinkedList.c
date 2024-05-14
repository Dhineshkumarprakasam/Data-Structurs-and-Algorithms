#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head,*newnode,*temp,*garbage;

void atBegin(int x)
{
    newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;

    if(head==0)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}

void atEnd(int x)
{
    newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;

    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void atPos(int pos,int x)
{
    newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;

    temp=head;
    for(int i=1;i<pos-1;i++)
        temp=temp->next;

    newnode->next=temp->next;
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
}

void del_begin()
{
    garbage=head;
    head=head->next;
    free(garbage);
}

void del_end()
{
    temp=head;
    while(temp->next->next!=0)
        temp=temp->next;

    garbage=temp->next;
    temp->next=0;
    free(garbage);

}

void del_pos(int pos)
{
    temp=head;
    for(int i=1;i<pos-2;i++)
        temp=temp->next;
    garbage=temp->next;
    temp->next=temp->next->next;
    free(garbage);
}
void main()
{
    atBegin(5);
    atBegin(4);
    atBegin(3);
    atBegin(2);
    atBegin(1);
    atEnd(6);
    atPos(3,100);
    del_begin();
    del_end();
    del_pos(3);
    display();
}
