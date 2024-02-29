#include <stdio.h>
#define size 5

int queue[size];
int front=-1;
int rear=-1;

void enqueue(int x)
{
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        queue[rear]=x;
    }

    else if(rear==size-1)
        printf("Overflow\n");

    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
        printf("Underflow\n");
    else if(front==rear)
    {
        printf("Dequeued : %d\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("Dequeued : %d\n",queue[front]);
        front++;
    }
}

void peek()
{
    if(front==-1 && rear==-1)
        printf("Underflow\n");
    else
        printf("Peek : %d\n",queue[front]);
}

void display()
{
    if(front==-1 && rear==-1)
        printf("Underflow\n");
    else
    {
        for(int i=front;i<rear;i++)
            printf("%d\n",queue[i]);
        printf("%d\n",queue[rear]);
    }
}
