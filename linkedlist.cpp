#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this-> data=data;
        this-> next=NULL;
    }

};
void insertathead(Node* &head,int d)
{
    Node* temp=new Node(d);
    temp-> next=head;
    head=temp;

}
void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<< temp->data<<endl;
        temp=temp->next;
    }

}
int main()
{
    Node* Node1=new Node(10);
    cout << "Node data: " << Node1->data << endl;
    cout<< Node1->next<<endl;
    Node* head=Node1;
    insertathead(head,12);
   return 0;  
} 