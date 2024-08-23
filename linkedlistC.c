#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};
void insertatend(struct Node*head)
{
    struct Node*temp;
    temp = malloc(sizeof(struct Node));
    printf("\nEnter the data:");
    scanf("%d\n",&temp->data);
    temp->link=NULL;
    struct Node*ptr=head;
    
    
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    struct Node*assis=NULL;
    assis=head;
    while(assis!=NULL)
    {
        printf("%d",assis->data);
        
        assis=assis->link;
    }
    


}

struct Node* createnode()
{
    struct Node *head=NULL;
    struct Node *current=NULL;
    struct Node *temp=NULL;
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
        printf("%d ",ptr->data);
        count++;
        ptr=ptr->link;
    }
    printf("\nCount=%d",count);
} 
int main() {
    struct Node*head=NULL;
    head=createnode();
    treverse(head);
    insertatend(head);

    return 0;
}   
