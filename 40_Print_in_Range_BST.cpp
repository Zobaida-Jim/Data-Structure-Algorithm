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
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
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

void print_range(Node *root, int start, int end)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data >= start && root->data <= end) // case - 01
    {
        print_range(root->left, start, end); // for sorted range use inorder
        cout << root->data << " ";
        // print_range(root->left,start,end); //for unsorted
        print_range(root->right, start, end);
    }

    else if (root->data < start)
    {
        print_range(root->right, start, end);
    }

    else if (root->data > end)
    {
        print_range(root->left, start, end);
    }
}

int main()
{
    int arr[9] = {8, 5, 10, 3, 6, 11, 1, 4, 14};
    Node *root = build_BST(arr, 9);

    inorder(root);
    cout << endl;

    print_range(root, 5, 12); // 5,6,8,10,11

    return 0;
}