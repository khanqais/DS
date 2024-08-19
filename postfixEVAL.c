#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100 
int stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push(int val) {
    if (isFull()) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        
    }
    return stack[top--];
}

int calc(int a, int b, char ch) {
    int result;
    switch (ch) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;
           
        default: 
            printf("Bruh");
            
    }
    return result;
}

void eval(char postfix[]) {
    
     for(int i = 0;postfix[i] != '\0';i++) 
    {
        
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - 48);
        }
         else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            int op2 = pop();
            int op1 = pop();
            int res = calc(op1, op2, postfix[i]);
            push(res);
        }
        
    }
    printf("Result = %d\n", pop());
}

int main() {
    char postfix[MAX];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    eval(postfix);
    return 0;
}