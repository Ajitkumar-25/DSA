#include<iostream>
using namespace std;
struct Node
{
    int key;
    Node* left;
    Node * right;
    Node(int k)
    {
        key= k;
        left=right=NULL;

    }

};

int inorder(Node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);

    }
}

int preorder(Node*root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);

    }
}

int postorder(Node*root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";

    }
}
int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->right=new Node(60);
    cout<<"Inorder traversal is as follows"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal is as follows"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal is as follows"<<endl;
    postorder(root);
return 0;
}