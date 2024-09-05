#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

void delete(struct Node** head) {
    int k;
    printf("Enter the position to delete: ");
    scanf("%d", &k);

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (k == 1) {
        if (temp->link == *head) {
            free(temp);
            *head = NULL;
            printf("The linked list is empty after deletion.\n");
            return;
        }
        
        struct Node* last = *head;
        while (last->link != *head) {
            last = last->link;
        }

        struct Node* toDelete = *head;
        *head = (*head)->link;
        last->link = *head;
        free(toDelete);
    } else {
        for (int i = 1; i < k - 1; i++) {
            prev = temp;
            temp = temp->link;
            if (temp == *head) {
                printf("Position out of range.\n");
                return;
            }
        }

        prev = temp;
        temp = temp->link;
        if (temp == *head) {
            printf("Position out of range.\n");
            return;
        }

        prev->link = temp->link;
        free(temp);
    }

    struct Node* tr = *head;
    printf("The linked list after deleting: ");
    if (*head != NULL) {
        do {
            printf("%d ", tr->data);
            tr = tr->link;
        } while (tr != *head);
    }
    printf("\n");
}

void insertAthead(struct Node** head, int data) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = *head;

    if (*head == NULL) {
        *head = temp;
        (*head)->link = *head;
        return;
    }

    struct Node* last = *head;
    while (last->link != *head) {
        last = last->link;
    }
    last->link = temp;
    *head = temp;
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node* pt = head;
    int count = 0;

    printf("The linked list is: ");
    do {
        printf("%d ", pt->data);
        count++;
        pt = pt->link;
    } while (pt != head);

    printf("\nCount=%d\n", count);
}

struct Node* circularSingly() {
    int n, x;

    printf("Enter the number of nodes to be added: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return NULL;
    }

    struct Node* head = malloc(sizeof(struct Node));
    printf("Enter the data for node 1: ");
    scanf("%d", &head->data);
    head->link = head;

    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        struct Node* nn = malloc(sizeof(struct Node));
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &x);
        nn->data = x;
        nn->link = head;
        current->link = nn;
        current = nn;
    }

    return head;
}

int main() {
    int no;
    struct Node* head = circularSingly();
    traverse(head);

    printf("\nEnter the data for insertion at head: ");
    scanf("%d", &no);
    insertAthead(&head, no);
    traverse(head);

    delete(&head);
    traverse(head);

    return 0;
}
