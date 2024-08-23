#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};
void treverse(struct Node*head)
{
    int count=0;
    struct Node*ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    printf("Count=%d",count);
} 

int main() {
    int numNodes, i;
    struct Node *head;
    struct Node *current;
    struct Node *temp;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    head = malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &head->data);
    head->link = NULL;
    current = head;
    for (i = 2; i <= numNodes; i++) {
        temp = malloc(sizeof(struct Node));

        
        printf("Enter data for node %d: ", i);
        scanf("%d", &temp->data);
        temp->link = NULL;

        
        current->link = temp;
        current = temp;
    }
    printf("The linked list is: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
    treverse(head);
    return 0;
}