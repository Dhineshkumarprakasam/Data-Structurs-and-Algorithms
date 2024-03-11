#include <stdio.h>
#include <string.h>

char infix[100],prefix[100],stack[100];
int top=-1;
int pf=-1;

void push(char item)
{
    top++;
    stack[top]=item;
}

char pop()
{
    char x=stack[top];
    top--;
    return x;
}

int isoperator(char symbol)
{
    if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='%' || symbol=='+' || symbol=='-')
        return 1;
    else
        return 0;
}

int pre(char symbol)
{
    if(symbol=='^')
        return 3;
    else if(symbol=='*' || symbol=='/' || symbol=='%')
        return 2;
    else if(symbol=='+' || symbol=='-')
        return 1;
    else
        return 0;
}

void convert()
{
    char x;
    int i=0;
    char item=infix[i];
    while(i!=strlen(infix))
    {
        if(item==')')
            push(item);
        else if(isdigit(item) || isalpha(item))
        {
            pf++;
            prefix[pf]=item;
        }
        else if(isoperator(item)==1)
        {
            x=pop();
            while(isoperator(item)==1 && pre(x)>=pre(item))
            {
                pf++;
                prefix[pf]=x;
                x=pop();
            }
            push(x);
            push(item);
        }
        else if(item=='(')
        {
            x=pop();
            while(x!=')')
            {
                pf++;
                prefix[pf]=x;
                x=pop();
            }
        }

        i++;
        item=infix[i];
    }
}

void main()
{
    printf("Enter your infix expression : ");
    scanf("%s",infix);

    push(')');
    
    strrev(infix);
    strcat(infix,"(");
    convert();
    strrev(prefix);
    
    printf("%s",prefix);
}
