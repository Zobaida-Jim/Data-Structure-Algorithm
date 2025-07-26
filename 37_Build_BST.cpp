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

    // Search Appropriate position for next Node
    if (val < root->data) // left subtree
    {
        root->left = insert(root->left, val);
    }
    else // right subtree
    {
        root->right = insert(root->right, val);
    }

    return root;
}

Node *buildBST(int arr[], int n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}

// Checking is this the correct BST
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
    int arr[6] = {5, 1, 3, 4, 2, 7}; // Inorder = 1 2 3 4 5 7
    Node *root = buildBST(arr, 6);
    inorder(root);
    cout << endl;

    return 0;
}