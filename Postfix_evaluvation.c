#include <stdio.h>

int stack[100];
int tops=-1;

char expression[100];

void sum()
{
    int o1=stack[tops];
    tops--;
    int o2=stack[tops];
    int result=o2+o1;

    tops++;
    stack[tops]=result;
}

void sub()
{
    int o1=stack[tops];
    tops--;
    int o2=stack[tops];
    int result=o2-o1;

    tops++;
    stack[tops]=result;
}

void mul()
{
    int o1=stack[tops];
    tops--;
    int o2=stack[tops];
    int result=o2*o1;

    tops++;
    stack[tops]=result;
}

void div()
{
    int o1=stack[tops];
    tops--;
    int o2=stack[tops];
    int result=o2/o1;

    tops++;
    stack[tops]=result;
}

void mod()
{
    int o1=stack[tops];
    tops--;
    int o2=stack[tops];
    int result=o2%o1;

    tops++;
    stack[tops]=result;
}

void power()
{
    int o1=stack[tops];
    tops--;
    int o2=stack[tops];
    int result=pow(o2,o1);

    tops++;
    stack[tops]=result;
}


void main()
{
    printf("Enter your expression : ");
    scanf("%[^\n]s",expression);

    for(int i=0;expression[i]!='\0';i++)
    {
        if(expression[i]!=' ')
        {
            switch(expression[i])
            {
                case '^':
                    power();
                    break;
                case '*':
                    mul();
                    break;
                case '/':
                    div();
                    break;
                case '+':
                    sum();
                    break;
                case '-':
                    sub();
                    break;
                case '%':
                    mod();
                    break;
                default:
                    tops++;
                    stack[tops]=expression[i]-48;
            }
        }
    }
    printf("The result is : %d ",stack[tops]);
}
