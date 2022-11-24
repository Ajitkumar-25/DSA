#include <iostream>
using namespace std;
#include<queue>
#include<stack>


struct Node
{
int data;
Node* left;
Node* right;

Node(int x){
  data=x;
  left=right=NULL;
}
};


Node* create(Node* root,int val)
{ 
  if(root==NULL)
  {
  root=new Node(val);
  return root;
  }
 else{
   if(val<root->data)
       root->left=create(root->left,val);
  else if (val>root->data)
       root->right=create(root->right,val);
  return root;
}
  }

int height(Node* root)
{
  if(root==NULL)
    return 0 ;
  else
    return 1+ max(height(root->left),height(root->right));
}


void postorder(Node* root)
{ stack<Node*> s1,s2;
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



void inorder(Node* root)
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



void levelorder(Node* root)
{ 
  if(root==NULL)
  return ;
  queue<Node*> q;
  q.push(root);
  while(q.empty()==false)
    {
      Node* topp=q.front();
      q.pop();
      cout<<topp->data<<" ";
      if(topp->left!=NULL)
        q.push(topp->left);
      if(topp->right!=NULL)
        q.push(topp->right);
    }
}


int main() 
{
int n,val;
Node* root=NULL;
  cout<<"Enter how many nodes : ";
  cin>>n;
  for(int i=0;i<n;i++)
    { cin>>val;
 root =create(root,val);  }
  int h=height(root);
  cout<<"Height of above binary search tree is: "<< h<<endl;
  cout<<"iorder traversal is as : ";
  inorder(root);
  cout<<endl;
  cout<<"preorder traversal is as :";
  preorder(root);
  cout<<endl;
  cout<<"postorder traversal is as ";
  postorder(root);
  cout<<endl;
  cout<<"level order traversal is as : ";
  levelorder(root);
  cout<<endl;
  return 0;
  }