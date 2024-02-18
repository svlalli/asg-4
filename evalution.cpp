#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 100

typedef struct {
    int top;
    double stack[MAX_SIZE];
} Stack;

void push(Stack *s, double item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push item.\n");
        return;
    }
    s->stack[++(s->top)] = item;
}

double pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow! Cannot pop item.\n");
        return -1;
    }
    return s->stack[(s->top)--];
}

double evaluatePostfix(char postfix[]) {
    Stack s;
    s.top = -1;
    int i = 0;
    char symbol;
    double operand1, operand2, result;

    while ((symbol = postfix[i]) != '\0') {
        if (isdigit(symbol)) {
            push(&s, symbol - '0');
        } else {
            operand2 = pop(&s);
            operand1 = pop(&s);

            switch (symbol) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
                default:
                    printf("Invalid operator.\n");
                    exit(1);
            }

            push(&s, result);
        }
        i++;
    }

    return pop(&s);
}

int main() {
    char postfix[MAX_SIZE];
    double result;

    printf("Enter a postfix expression: ");
    gets(postfix);

    result = evaluatePostfix(postfix);

    printf("Result: %.2f\n", result);

    return 0;
}
```
