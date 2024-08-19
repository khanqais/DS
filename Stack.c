#include <stdio.h>
#define maxsize 5

int top = -1;
int stack[maxsize];

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d\n", stack[i]);
    }
}

int isFull() {
    return top == maxsize - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int k) {
    if (isFull()) {
        printf("Stack is overflowing\n");
    } else {
        stack[++top] = k;
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack is under-flowing\n");
        return -1;
    } else {
        return stack[top--];
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Peek value = %d\n", stack[top]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter 1 for Push\n");
        printf("Enter 2 for Pop\n");
        printf("Enter 3 for Peek\n");
        printf("Enter 4 for Display\n");
        printf("Enter 5 for Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;
                printf("Enter number of elements to be pushed: ");
                scanf("%d", &n);
                printf("Enter values to be pushed:\n");
                for (int i = 0; i < n; i++) {
                    int value;
                    scanf("%d", &value);
                    push(value);
                }
                display();
                break;
            }
            case 2: {
                int m;
                printf("Enter number of elements to be popped: ");
                scanf("%d", &m);
                for (int i = 0; i < m; i++) {
                    int poppedValue = pop();
                    if (poppedValue != -1) {
                        printf("Popped: %d\n", poppedValue);
                    } else {
                        break;
                    }
                }
                display();
                break;
            }
            case 3: {
                peek();
                break;
            }
            case 4: {
                display();
                break;
            }
            case 5: {
                printf("Operation exited!\n");
                return 0;
            }
            default: {
                printf("Invalid choice!!\n");
            }
        }
    }
    return 0;
}