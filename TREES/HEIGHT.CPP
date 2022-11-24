#include<iostream>
using namespace std;

/*      10
    20       30
 40     50          60
     */
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
int heightBinaryTree(Node* root)
{
    if(root==NULL)
    return 0;
    else
    return max(heightBinaryTree(root->left),heightBinaryTree(root->right))+1;
}
int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->right=new Node(60);
   cout<<"height of binary tree is"<<endl;
  cout<<heightBinaryTree(root);
return 0;
}