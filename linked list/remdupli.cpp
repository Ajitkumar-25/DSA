//removing repeatefd element


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



//swapping nodes 

#include <bits/stdc++.h>
using namespace std;
 

class Node {
public:
    int data;
    Node* next;
};
 

void swapNodes(Node** head_ref, int x, int y)
{
   
    if (x == y)
        return;
 
    
    Node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }
 
    
    Node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }
 
    
    if (currX == NULL || currY == NULL)
        return;
 
   
    if (prevX != NULL)
        prevX->next = currY;
    else
        *head_ref = currY;
 
  
    if (prevY != NULL)
        prevY->next = currX;
    else 
        *head_ref = currX;
 
    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}
 

void push(Node** head_ref, int new_data)
{
    
    Node* new_node = new Node();
 
    
    new_node->data = new_data;
 
    
    new_node->next = (*head_ref);
 
   
    (*head_ref) = new_node;
}
 

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 

int main()
{
    Node* start = NULL;
 
    
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    cout << "Linked list before calling swapNodes() ";
    printList(start);
 
    swapNodes(&start, 4, 3);
 
    cout << "\nLinked list after calling swapNodes() ";
    printList(start);
 
    return 0;
}





//pairwisw swap
void pairwise(Node* head)
{
    Node* temp=head;
    while(temp!=NULL&&temp->next!=NULL)
    {
        swap(temp->data,temp->next->data);
        temp=temp->next->next;
    }
}

//move to front

void movetofront(Node* &head)
{
    if(head==NULL||head->next==NULL)
    return;
     
     Node*last=head;
     Node* seclast=NULL;
     while(last->next!=NULL)
     {   seclast=last;
         last=last->next;
     }
     seclast->next=NULL;
     last->next=head;
     head=last;
}
//CRAETION OF DOUBLY


#include <iostream>
using namespace std;
 
 
class node{
    public:
    node* prev;
    int data;
    node* next;
     
     
    node(int value){  
        prev=NULL;      
        data=value;   
        next=NULL;    
    }
};
 
 
void insert_at_head(node* &head, int value){
     
    node* n = new node(value);
    n->next=head;
 
    if(head!=NULL){
        head->prev=n;
    }
     
    head=n;
}
 
 
void insert_at_tail(node* &head, int value){
     
    if(head==NULL){
        insert_at_head(head, value);
        return;
    }
     
    node* n = new node(value);
    node* temp=head;
         
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
 
 
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" --> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
 
 
int main()
{
    node* head=NULL;      
   
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
     
      cout<<"After insertion at tail: ";
    display(head);
     
      cout<<"After insertion at head: ";
    insert_at_head(head,0);
     
    display(head);
      return 0;
}











//CIRCULAR LINKED LIST 
#include <bits/stdc++.h>
using namespace std;
 

class Node {
public:
    int data;
    Node* next;
};
 

void push(Node** head_ref, int data)
{
 
    
    Node* ptr1 = new Node();
    ptr1->data = data;
    ptr1->next = *head_ref;
 
    
    if (*head_ref != NULL) {
 
        
        Node* temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
 
       
        ptr1->next = ptr1;
 
    *head_ref = ptr1;
}
 

void printList(Node* head)
{
    Node* temp = head;
    if (head != NULL) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
 
    cout << endl;
}
 

void deleteNode(Node** head, int key)
{
 
    
    if (*head == NULL)
        return;
 
   
    if ((*head)->data == key && (*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
 
    Node *last = *head, *d;
 
    
    if ((*head)->data == key) {
 
        
        while (last->next != *head)
            last = last->next;
 
        
        last->next = (*head)->next;
        free(*head);
        *head = last->next;
        return;
    }
 
   
    while (last->next != *head && last->next->data != key) {
        last = last->next;
    }
 
    
    if (last->next->data == key) {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    else
        cout << "no such keyfound";
}
 

int main()
{
    
    Node* head = NULL;
 
   
    push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);
 
    cout << "List Before Deletion: ";
    printList(head);
 
    deleteNode(&head, 7);
 
    cout << "List After Deletion: ";
    printList(head);
 
    return 0;
}

//CIRCULAR LINKED LIST TRAVERSAL
#include<stdio.h>
#include<stdlib.h>
  

struct Node
{
    int data;
    struct Node *next;
};
  

void push(struct Node **head_ref, int data)
{
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;
  
   
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; 
  
    *head_ref = ptr1;
}
  

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
}
  

int main()
{
   
    struct Node *head = NULL;
  
   
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
  
    printf("Contents of Circular Linked List\n ");
    printList(head);
  
    return 0;
}