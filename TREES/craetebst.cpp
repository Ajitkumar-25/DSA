#include <bits/stdc++.h>
using namespace std;
 

struct Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
    
    }
};
 

void insert(Node*& root, int key)
{
    Node* node = new Node(key);
    if (!root) {
        root = node;
        return;
    }
    Node* prev = NULL;
    Node* temp = root;
    while (temp) {
        if (temp->data > key) {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->data< key) {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->data > key)
        prev->left = node;
    else
        prev->right = node;
}
 

void inorder(Node* root)
{
    Node* temp = root;
    stack<Node*> st;
    while (temp != NULL || !st.empty()) {
        if (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        else {
            temp = st.top();
            st.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}
 
int main()
{    int n,x;
    cout<<"enter how many nodes: ";
    cin>>n;
    Node* root = NULL;
    for(int i=0;i<n;i++)
    {  cout<<"enter data :";
        cin>>x;
      insert(root, x);
    }
 cout<<"inorder traversal is as fillows : ";   
 inorder(root);
 
    return 0;
}