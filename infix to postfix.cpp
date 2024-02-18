#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top == MAX_SIZE - 1)
     {
        printf("Stack Overflow! Cannot push item.\n");
        return;
    }
    stack[++top] = item;
}

char pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow! Cannot pop item.\n");
        return -1;
    }
    return stack[top--];
}

int isOperator(char symbol)
 {
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
        return 1;
    else
        return 0;
}

int precedence(char symbol) 
{
    if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[])
 {
    int i, j;
    char item, x;

    push('(');
    strcat(infix,")");

    i = 0;
    j = 0;
    item = infix[i];

    while (item != '\0') 
    {
        if (item == '(') 
        {
            push(item);
        } else if (isdigit(item) || isalpha(item))
         {
            postfix[j] = item;
            j++;
        } else if (isOperator(item))
        
         {
            x = pop();
            while (isOperator(x) && precedence(x) >= precedence(item))
             {
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        } else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix[j] = x;
                j++;
                x = pop();
            }
        } else {
            printf("Invalid infix expression.\n");
            exit(1);
        }
        i++;
        item = infix[i];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s");
}
