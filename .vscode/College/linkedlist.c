#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *link;
};
void deleteEnd(struct Node** head) {
    // If the list has more than one node
    struct Node* ptr = *head;
    struct Node* prev = NULL;

    // Traverse krne ka second last node tak
    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }

    // Now ptr ko last node pe
    prev->link = NULL;
    free(ptr);

    printf("The linked list after deleting the end node is: ");
    ptr = *head;
    while (ptr != NULL) 
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    printf("The Final linked list is: ");
    ptr = *head;
    while (ptr != NULL) 
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

}

void insertatposi(struct Node** head, int pos, int data) 
{
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = NULL;
    if (pos == 1) 
    {
        temp->link = *head;
        *head = temp;
        return;
    }
    struct Node* ptr = *head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++) 
    {
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    ptr->link = temp;
}

void deletehead(struct Node** head) {
    if (*head == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->link;
    free(temp);
    printf("The linked list after deleting the head is: ");
    struct Node* ptr = *head;
    while (ptr != NULL) 
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void insertatbegin(struct Node** head, int data) 
{
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = *head;
    *head = temp;
    printf("The linked list is: ");
    struct Node* ptr = *head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void insertatend(struct Node** head, int data) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = NULL;
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* ptr = *head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;
    printf("The linked list is: ");
    ptr = *head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

struct Node* createnode() {
    struct Node* head = NULL;
    struct Node* current = NULL;
    struct Node* temp = NULL;
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    if (numNodes <= 0) return NULL;
    head = malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->link = NULL;
    current = head;
    for (int i = 2; i <= numNodes; i++) {
        temp = malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &temp->data);
        temp->link = NULL;
        current->link = temp;
        current = temp;
    }
    return head;
}

void treverse(struct Node* head) {
    int count = 0;
    struct Node* ptr = head;
    printf("The linked list is: ");
    while (ptr != NULL) 
    {
        printf("%d ", ptr->data);
        count++;
        ptr = ptr->link;
    }
    printf("\nCount=%d\n", count);
}
int main() 
{
    struct Node* head = createnode();
    treverse(head);
    int pos, data;
    printf("\nEnter the position and data for insertion at position:");
    scanf("%d %d", &pos, &data);
    insertatposi(&head, pos, data);
    printf("\nEnter the data for insertion at end:");
    scanf("%d", &data);
    insertatend(&head, data);
    printf("\nEnter the data for insertion at begin:");
    scanf("%d", &data);
    insertatbegin(&head, data);
    deletehead(&head);
    deleteEnd(&head);
    

    return 0;
}
 