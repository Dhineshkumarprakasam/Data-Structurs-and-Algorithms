#include <stdio.h>
#define size 10

int queue[size];
int front=-1;
int rear=-1;

int enqueue(int x)
{
    if(front==-1 && rear==-1)
    {
        rear++;
        front++;
        queue[rear]=x;
    }
    else if((rear+1)%size==front)
        printf("\nThe Queue is full");
    else
    {
        rear=(rear+1)%size;
        queue[rear]=x;
    }
}
int dequeue()
{
    if(front==-1 && rear==-1)
        printf("\nThe Queue is empty");
    else
    {
        printf("\nThe dequeued element is : %d",queue[front]);
        front=(front+1)%size;
    }

}

int display()
{
    printf("\n");
    int i=front;
    while(i!=rear)
    {
        printf("%d ",queue[i]);
        i=(i+1)%size;
    }
    printf("%d",queue[rear]);
}

