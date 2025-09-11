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

bool validHelper(Node *root, Node *min, Node *max)
{
    if (root == NULL)
    {
        return true;
    }

    if (min != NULL && root->data < min->data)
    {
        return false;
    }

    if (max != NULL && root->data > max->data)
    {
        return false;
    }

    return (validHelper(root->left, min, root) && (validHelper(root->right, root, max)));
}

bool validBST(Node *root)
{
    return validHelper(root, NULL, NULL);
}

int main()
{
    int arr[6] = {5, 1, 3, 4, 2, 7}; // Inorder = 1 2 3 4 5 7
    Node *root = buildBST(arr, 6);

    cout << validBST(root) << endl;

    return 0;
}