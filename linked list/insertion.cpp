#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
   //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertAtHead(Node* &head,int d)
{
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node* &tail,int d)
{
    Node*temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}

void insertAtPosition(Node* tail,Node* &head,int position,int d)
{  
    //insert at begining
     if(position==1)
{
    insertAtHead(head,d);
    return;
}
    Node* temp= head;
    int count=1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
        }
        //inserting at last position
        if(temp->next=NULL)
        {
            insertAtTail(tail,d);
            return;
        }

        //creating a node for d
  Node* nodeToInsert=new Node(d);
  nodeToInsert->next=temp->next;
  temp->next=nodeToInsert;
  }

  void deleteNode(int position,Node*&head)
{ 
    if(position==NULL) 
{
     Node*temp=head;
     head=head->next;
     delete temp;

}
else{
    //deleting middle and last

}

}
void print(Node* &head){
Node*temp=head;
while(temp!=NULL)
{
    cout<<temp->data<<" ";
    temp=temp->next;
}
cout<<endl;

}

int main()
{
    Node* node1=new Node(10);
   // cout<<node1->data<<endl;
    //cout<<node1->next<<endl;
    Node* head=node1;
    Node*tail=node1;
    print(head);
     insertAtTail(tail,12);
     insertAtTail(tail,15);
     insertAtPosition(tail,head,4,20);
     print(head);
return 0;
}
