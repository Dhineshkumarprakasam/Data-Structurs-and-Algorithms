#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=0,*rear=0,*newnode,*garbage,*temp;

void enqueue(int x)
{
    newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;

    if(front==0 && rear==0)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue()
{
    garbage=front;
    front=front->next;
    printf("Dequeued : %d\n",garbage->data);
    free(garbage);
}

void display()
{
    temp=front;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    display();
}
