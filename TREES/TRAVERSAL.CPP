#include<iostream>
#include<stack>
#include<queue>
using namespace std;
   struct Node
   {
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
  };

// inorder traversal iterative using stack

void inorder (Node* root)
{

    stack<Node*> st;
    if(root==NULL)
    return ;
    Node* curr=root;
    while(curr!=NULL ||st.empty()==false)
    {
        while(curr!=NULL)
        {  st.push(curr);
        curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}
//preorder travesal using stack
void preorder(Node* root)
{
    stack<Node*>s;
    if(root==NULL)
    return ;
    s.push(root);
   while(!s.empty())
   {
     Node* curr=s.top();
     cout<<curr->data<<" ";
     s.pop();
     if(curr->left!=NULL)
      s.push(curr->left);
      if(curr->right!=NULL)
      s.push(curr->right);
    }

}

//postorder traversal using two stack;;

void postorder(Node*root)
{
    stack<Node*> s1,s2;
    if(root==NULL)
    return ;
    s1.push(root);
    while(!s1.empty())
    {
      Node* ele=s1.top();
      s1.pop();
      s2.push(ele);
      if(ele->left!=NULL)
      s1.push(ele->left);
      if(ele->right!=NULL)
      s1.push(ele->right);
      
    }
    while(!s2.empty())
    {
      Node* index =s2.top();
      s2.pop();
      cout<<index->data<<" ";

    }
     
}

//level order travesal using queue

void levelorder(Node* root)
{
  if(root==NULL)
  return ;
  queue<Node*>q;
  q.push(root);
  while(!q.empty())
  {
    Node*curr=q.front();
    q.pop();
    cout<<curr->data<<" ";
     if(curr->left!=NULL)
      q.push(curr->left);
      if(curr->right!=NULL)
      q.push(curr->right);

  }
}
//height of binary tree
int height(Node* root)
{
  if(root==NULL)
  return 0;
  return 1+max(height(root->left),height(root->right));
}

//size of binary tree
int getsize(Node* root)
{
  if (root==NULL)
  return 0;
  return 1+getsize(root->left)+getsize(root->right);
}
  int main()
  {
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);
    root->right->right=new Node(70);
    cout<<"Inorder traversal is as follows : ";
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal is as follows : ";
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal is as follows : ";
    postorder(root);
    cout<<endl;
     cout<<"levelorder traversal is as follows : ";
    levelorder(root);
    cout<<endl;
    cout<<"Height of binary tree is ";
    int h=height(root);
    cout<<h<<endl;
    cout<<"size of binary tree is ";
    int t=getsize(root);
    cout<<t<<endl;

    return 0;
  }