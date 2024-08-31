#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};
// void insertatposi(struct Node*head)
// {
    
//     int n;
//     printf("\nEnter the position:");
//     scanf("%d",&n);
//     int s;
//     printf("Enter the data:");
//     scanf("%d",&s);
//     int cx=0;
//     struct Node*ptr;
//     ptr=head;
//      struct Node*temp=malloc(sizeof(struct Node));
//      temp->data=s; 
//      temp->link=NULL; 
//     while(ptr!=NULL)
//     {
//         cx++;
//         if(cx==n)
//         {
             
//         }
//         ptr=ptr->link;
        

//     }


// }
struct Node* deletehead(struct Node* head)
{
    struct Node* temp = head;
    head = head->link;
    free(temp);
    return head;
}


void insertatbegin(struct Node*head)
{
    int y;
    printf("\nEnter the data for insertion at begin:");
    scanf("%d",&y);
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=y;
    struct Node*ptr=head;
    temp->link=head;
    head=temp;
     struct Node*assis=NULL;
    assis=head;
    printf("The linked list is:");
    while(assis!=NULL)
    {
    printf("%d ",assis->data);
    assis=assis->link;
    }
}
void insertatend(struct Node*head)
{
    int x;
    printf("\nEnter the data for insertion at end:");
    scanf("%d",&x);
    struct Node*temp=malloc(sizeof(struct Node));
    temp->data=x;
    temp->link=NULL;
    struct Node*ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    struct Node*assis=NULL;
    assis=head;
    printf("The linked list is:");
    while(assis!=NULL)
    {
        printf("%d ",assis->data);
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
    printf("The linked list is:");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        count++;
        ptr=ptr->link;
    }
    printf("\nCount=%d",count);
} 
int main() {
    struct Node*head;
    head=createnode();
    treverse(head);
    insertatend(head);
    insertatbegin(head);
    //insertatposi(head);
    head=deletehead(head);
    treverse(head);

    return 0;
}
