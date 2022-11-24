#include<iostream>
using namespace std;
struct Node{
int data;
Node* left;
Node* right;

Node(int x)
{
    data=x;
    left=right=NULL;
}
};

void inorder(Node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int findSum(Node* root,int arr[],int sum)
{  Node* curr=root;
    int sum=0;
 if(root=NULL)
 return 0;
 while(curr!=NULL)
{
    

}

return sum;
}
int main()
{ int arr[]={10,20,26,30,35};
int sum;
    Node* root=new Node(30);
    root->left=new Node(20);
    root->right=new Node(35);
    root->left->left=new Node(10);
    root->left->right=new Node(25);
    root->right->left=new Node(26);
    root->right->right=new Node(40);
     inorder(root);
findSum(root,arr,sum);
}