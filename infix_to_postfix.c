#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    char ch = stack[top];
    top--;
    return ch;
}

char peek()
{
    return stack[top];
}

int isOperand(char ch)
{
    return isalnum((unsigned char)ch);
}

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '/' || ch == '*')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' ||
        ch == '*' || ch == '/' || ch == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infix_to_postfix(char infix[], char postfix[])
{
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if (isalnum((unsigned char)ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j] = pop();
                j++;
            }

            if (top != -1)
            {
                pop();
            }
        }
        else if (isOperator(ch))
        {
            while (top != -1 &&
                   peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch) &&
                    ch != '^')))
            {
                postfix[j] = pop();
                j++;
            }

            push(ch);
        }

        i++;
    }

    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[100];
    char postfix[100];

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression is: %s\n", postfix);

    return 0;
}

