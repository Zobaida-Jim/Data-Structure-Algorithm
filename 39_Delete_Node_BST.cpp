#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (root->data > val) // left subtree
    {
        root->left = insert(root->left, val);
        return root;
    }
    else // right subtree
    {
        root->right = insert(root->right, val);
        return root;
    }
    return root;
}

Node *build_BST(int arr[], int n)
{
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

Node *getInorderSuccessor(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *del_Node(Node *root, int key)
{
    // search the Node
    if (root == NULL) // No node
    {
        return NULL;
    }
    if (key < root->data) // left subtree
    {
        root->left = del_Node(root->left, key);
    }
    else if (key > root->data) // right subtree
    {
        root->right = del_Node(root->right, key);
    }
    else                                               // key = root ->data
    {                                                  // there is 3 case
        if (root->left == NULL && root->right == NULL) // case-01 : 0 child
        {
            delete root;
            return NULL;
        }
        if (root->left == NULL || root->right == NULL) // case-02 : 1 child
        {
            return root->left == NULL ? root->right : root->left;
        }
        // case-03 : 2 child
        Node *IS = getInorderSuccessor(root->right);
        root->data = IS->data; // replace val with IS
        root->right = del_Node(root->right, IS->data);
        return root;
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = build_BST(arr, 9);

    inorder(root);
    cout << endl;

    del_Node(root, 4);
    inorder(root);
    cout << endl;

    return 0;
}