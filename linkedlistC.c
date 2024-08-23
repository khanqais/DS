#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node* createnode()
{
    struct Node *head;
    struct Node *current;
    struct Node *temp;
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
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
void treverse(struct Node*head)
{
    int count=0;
    struct Node*ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        count++;
        ptr=ptr->link;
    }
    printf("\nCount=%d",count);
} 


int main() {
    struct Node*head;
    head=createnode();
    treverse(head);
    return 0;
}
