#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push item.\n");
        return;
    }
    stack[++top] = item;
    printf("Pushed %d onto the stack.\n", item);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop item.\n");
        return -1;
    }
    int item = stack[top--];
    printf("Popped %d from the stack.\n", item);
    return item;
}

int peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == MAX_SIZE - 1);
}

int main() {
    push(10);
    push(20);
    push(30);
    
    printf("Top element: %d\n", peek());
    
    pop();
    pop();
    pop();
    
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }
    
    return 0;
}
```
