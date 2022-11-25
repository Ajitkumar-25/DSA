#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    int height;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->height = 1;
        this->right = this->left = NULL;
    }
};
int height(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}
int getBalance(Node *root)
{
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}
Node *rightRotation(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = fmax(height(y->left), height(y->right)) + 1;
    x->height = fmax(height(x->left), height(x->right)) + 1;
    return x;
}
Node *leftRotation(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = fmax(height(x->left), height(x->right)) + 1;
    y->height = fmax(height(y->left), height(y->right)) + 1;
    return y;
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (!temp)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
Node *insertion(Node *root, int key)
{
    if (!root)
    {
        root = new Node(key);
        return root;
    }
    if (root->data > key)
    {
        root->left = insertion(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = insertion(root->right, key);
    }
    else
    { // equal keys not allowed in BST
        return root;
    }
    root->height = fmax(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    if (balance < -1 && key < root->right->data)
    {
        root = rightRotation(root->right);
        return leftRotation(root);
    }
    if (balance < -1 && key > root->right->data)
    {
        return leftRotation(root);
    }
    if (balance > 1 && key > root->left->data)
    {
        root = leftRotation(root->left);
        return rightRotation(root);
    }

    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root);
    }
    return root;
}
Node *minValueNode(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
Node *deleteNode(Node *root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {

        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {

            Node *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right,
                                     temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotation(root);

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotation(root);
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    root = insertion(root, 18);
    root = insertion(root, 15);
    root = insertion(root, 24);
    root = insertion(root, 8);
    root = insertion(root, 17);
    root = insertion(root, 22);
    root = insertion(root, 28);
    root = insertion(root, 31);

    cout << "level order traversal: " << endl;
    levelOrderTraversal(root);
    root = deleteNode(root, 24);
    cout << "level order traversal: delete: 24" << endl;
    levelOrderTraversal(root);
    root = deleteNode(root, 15);
    cout << "level order traversal: delete: 15" << endl;
    levelOrderTraversal(root);
    root = deleteNode(root, 18);
    cout << "level order traversal: delete: 18 " << endl;
    levelOrderTraversal(root);
    root = deleteNode(root, 22);
    cout << "level order traversal: delete: 22 " << endl;
    levelOrderTraversal(root);
    root = deleteNode(root, 17);
    cout << "level order traversal: delete: 17 " << endl;
    levelOrderTraversal(root);
    return 0;
}