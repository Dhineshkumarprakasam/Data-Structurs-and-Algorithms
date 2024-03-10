#include <stdio.h>
#include <string.h>

void main()
{

    char exp[100];
    char stack[100];
    int top=-1;

    printf("Enter your exp : ");
    scanf("%s",&exp);

    int len=strlen(exp);

    for(int i=0;i<len;i++)

    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{' || exp[i]=='<')
            {
                top++;
                stack[top]=exp[i];
            }
        else if((exp[i]==')' || exp[i]==']' || exp[i]=='}' || exp[i]=='>') && top==-1)
        {
            top-=1;
            break;
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}' || exp[i]=='>')
        {
            if(stack[top]=='(' && exp[i]==')')
                top-=1;
            else if(stack[top]=='[' && exp[i]==']')
                top-=1;
            else if(stack[top]=='{' && exp[i]=='}')
                top-=1;
            else if(stack[top]=='<' && exp[i]=='>')
                top-=1;

        }
    }

    if(top==-1)
        printf("It is valid\n");
    else
        printf("It is not valid\n");

}
