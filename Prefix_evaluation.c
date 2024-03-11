#include <stdio.h>
#define n 100

char prefix[n];
int stack[n];
int top=-1;

void sum()
{
    int o1,o2,result;

    o1=stack[top];
    top--;
    o2=stack[top];
    top--;
    result=o1+o2;

    top++;
    stack[top]=result;
}

void sub()
{
    int o1,o2,result;

    o1=stack[top];
    top--;
    o2=stack[top];
    top--;
    result=o1-o2;

    top++;
    stack[top]=result;
}

void mul()
{
    int o1,o2,result;

    o1=stack[top];
    top--;
    o2=stack[top];
    top--;
    result=o1*o2;

    top++;
    stack[top]=result;
}

void div()
{
    int o1,o2,result;

    o1=stack[top];
    top--;
    o2=stack[top];
    top--;
    result=o1/o2;

    top++;
    stack[top]=result;
}

void mod()
{
    int o1,o2,result;

    o1=stack[top];
    top--;
    o2=stack[top];
    top--;
    result=o1%o2;

    top++;
    stack[top]=result;
}

void power()
{
    int o1,o2,result;

    o1=stack[top];
    top--;
    o2=stack[top];
    top--;
    result=pow(o1,o2);

    top++;
    stack[top]=result;
}

void main()
{
    printf("Enter your expression : ");
    scanf("%s",&prefix);

    strrev(prefix);

    int i=0;
    char item=prefix[i];

    while(i!=strlen(prefix))
    {
        if(item!=' ')
        {
            switch(item)
            {
                case '+':
                    sum();
                    break;
                case '-':
                    sub();
                    break;
                case '*':
                    mul();
                    break;
                case '/':
                    div();
                    break;
                case '^':
                    power();
                    break;
                case '%':
                    mod();
                    break;
                default:
                    top++;
                    stack[top]=item-48;
            }
        }
        i++;
        item=prefix[i];
    }
    printf("The Result is : %d",stack[top]);
}

