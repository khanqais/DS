#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;


int isEmpty() {
    return top == -1;
}


int isFull() {
    return top == MAX - 1;
}


void push(char k) {
    if (isFull()) {
        printf("Stack is overflowing\n");
    } else {
        stack[++top] = k;
    }
}


char pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return '\0'; 
    } else {
        return stack[top--];
    }
}


int precedence(char symbol) {
    switch(symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}


void intopost() {
    char symbol, new;
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        switch(symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((new = pop()) != '(') {
                    postfix[j++] = new;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}


void print() {
    printf("Postfix: %s\n", postfix);
}

int main() {
    printf("Enter the infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove trailing newline character
    intopost();
    print();
    return 0;
}
