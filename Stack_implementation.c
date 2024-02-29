#include <stdio.h>
#define size 5

int stack[size];
int top=-1;


void push(int x)
{
    if(top==size-1)
        printf("Overflow\n");
    else
    {
        top++;
        stack[top]=x;
    }
}


void pop()
{
    if(top==-1)
        printf("Underflow\n");
    else
    {
        printf("The Poped element is : %d\n",stack[top]);
        top--;
    }
}


void peek()
{
    if(top==-1)
        printf("No element\n");
    else
        printf("Peek element : %d\n",stack[top]);
}

void display()
{
    if(top==-1)
        printf("No element\n");
    else
    {
        for(int i=0;i<=top;i++)
            printf("%d\n",stack[i]);
    }
}
