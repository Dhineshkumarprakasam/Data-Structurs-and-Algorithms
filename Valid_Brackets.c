#include <stdio.h>
#include <string.h>

int main()
{
    char exp[100];
    char stack[100];
    int top = -1;

    printf("Enter your expression: ");
    scanf("%s",&exp);

    int len = strlen(exp);

    for (int i = 0; i < len; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{' || exp[i] == '<')
        {
            top++;
            stack[top] = exp[i];
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}' || exp[i] == '>')
        {
            if (top == -1)
            {
                top = -2;
                break;
            }
            else if ((exp[i] == ')' && stack[top] == '('))
                top--;
            else if((exp[i] == ']' && stack[top] == '['))
                top--;
            else if((exp[i] == '}' && stack[top] == '{'))
                top--;
            else if((exp[i] == '>' && stack[top] == '<'))
                top--;

            else
            {
                top = -2;
                break;
            }
        }
    }

    if (top == -1)
        printf("It is valid\n");
    else
        printf("It is not valid\n");

    return 0;
}
