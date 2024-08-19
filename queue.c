#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

int queue[MAX];
int front = -1;
int rear = -1;
int size = 0;


int isEmpty() {
    return size == 0;
}


int isFull() {
    return size == MAX;
}


void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = item;
    size++;
}


int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1; 
    }
    int item = queue[front];
    front = (front + 1)% MAX;
    size--;
    return item;
}


int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1; 
    }
    
    return queue[front];
}


void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", queue[(front + i) % MAX]);
    }
    printf("\n");
}



// Example usage
int main() {
    int choice, value;
    
    while (1) {
    printf("Queue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Print Queue\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                if (isFull()) {
                    printf("Queue is full, cannot enqueue.\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(value);
                    printf("Enqueued %d\n", value);
                }
                break;
            
            case 2: 
                if (isEmpty()) {
                    printf("Queue is empty, cannot dequeue.\n");
                } else {
                    value = dequeue();
                    printf("Dequeued %d\n", value);
                }
                break;
            
            case 3:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    value = peek();
                    printf("Front element is %d\n", value);
                }
                break;
            
            case 4: 
                printf("Current queue: ");
                printQueue();
                break;
            
            case 5: 
                printf("Exiting...\n");
                exit(0);
                break;
            
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}