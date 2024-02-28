#include <stdio.h>
#define size 5

int stack[size];
int top=-1;


void push(int x)
{
    if(top==size-1)
        printf("\nOverflow");
    else
    {
        top++;
        stack[top]=x;
    }
}


void pop()
{
    if(top==-1)
        printf("\nUnderflow");
    else
    {
        printf("\nThe Poped element is : %d",stack[top]);
        top--;
    }
}


void peek()
{
    if(top==-1)
        printf("\nNo element");
    else
        printf("\nPeek element : %d",stack[top]);
}

void display()
{
    if(top==-1)
        printf("\nNo element");
    else
    {
        for(int i=0;i<=top;i++)
            printf("\n%d",stack[i]);
    }
}

void main()
{

    push(5);
    push(6);
    push(7);
    push(8);
    peek();
    push(9);
    push(10);
    display();
    pop();
    pop();
    peek();
    display();
}
