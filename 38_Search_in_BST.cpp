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

bool Search(Node *root, int key) // TC => O(Height), AVG = O(logn)
{
    if (root == NULL) // BC -> empty tree
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }

    if (root->data < key)
    {
        return Search(root->right, key);
    }
    else
    {
        return Search(root->left, key);
    }
}

int main()
{
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node *root = buildBST(arr, 9);
    bool flag = Search(root, 4);
    if (flag)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}