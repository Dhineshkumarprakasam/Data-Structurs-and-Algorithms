#include <stdio.h>

struct node
{
    struct node *next;
    int data;

};

struct node *head=0,*top,*newnode,*garbage;

void push(int x)
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

void pop()
{
    garbage=head;
    head=head->next;
    printf("poped : %d\n",garbage->data);
    free(garbage);
}

void main()
{
    push(10);
    push(20);
    push(30);
    pop();
    pop();
    pop();
}
