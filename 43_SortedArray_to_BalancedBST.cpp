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

Node *buildBST_from_Sorted_Arr(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    Node *curr = new Node(arr[mid]);
    curr->left = buildBST_from_Sorted_Arr(arr, start, mid - 1);
    curr->right = buildBST_from_Sorted_Arr(arr, mid + 1, end);

    return curr;
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
    int arr[7] = {3, 4, 5, 6, 7, 8, 9};
    Node *root = buildBST_from_Sorted_Arr(arr, 0, 6);

    preOrder(root);
    cout << endl;

    return 0;
}