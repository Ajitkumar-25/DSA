#include<iostream>
using namespace std;
 class Node{
     public:
     int data;
     Node* next;

 };



 void removeduplicates(Node* head)
 {
        Node*current=head;
        Node* next_next;
        if(current==NULL)
        return;
        while(current->next!=NULL)
        {
            if(current->data==current->next->data)
            {
                next_next=current->next->next;
                free(current->next);
                current->next=next_next;

              }
                else
              {
                current=current->next;
               }
         }
}

void insert(Node* &head,int data)
{
    Node* node1=new Node();
    node1->data=data;
    node1->next=head;
    head=node1;
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<" "<<head->data;
        head=head->next;
    }
}

int main()
{
    Node* head=NULL;
    insert(head,20);
    insert(head,13);
    insert(head,13);
    insert(head,11);
    insert(head,11);
    insert(head,11);
    print(head);
    removeduplicates(head);
    print(head);
    return 0;
}