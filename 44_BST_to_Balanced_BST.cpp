#include <iostream>
#include <vector>
#include <algorithm>
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

    if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        root->left = insert(root->left, val);
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

// Convert BST to Balanced BST
Node *build_balanced_BST(vector<int> arr, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    Node *curr = new Node(arr[mid]);
    curr->left = build_balanced_BST(arr, start, mid - 1);
    curr->right = build_balanced_BST(arr, mid + 1, end);

    return curr;
}
void getInorder(Node *root, vector<int> &nodes)
{
    if (root == NULL)
    {
        return;
    }
    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}
Node *balanced_BST_FromVec(Node *root)
{
    // Get inorder sequence
    vector<int> nodes;
    getInorder(root, nodes);

    // Build balanced BST
    root = build_balanced_BST(nodes, 0, nodes.size() - 1);
    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int arr[7] = {6, 5, 7, 4, 8, 3, 9};
    Node *root = build_BST(arr, 7);

    cout << endl
         << "Given BST Preorder sequence : ";
    preOrder(root);
    cout << endl
         << endl;

    root = balanced_BST_FromVec(root);
    cout << "Balanced BST preorder : ";
    preOrder(root);
    cout << endl
         << endl;

    return 0;
}