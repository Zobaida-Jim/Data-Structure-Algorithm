#include <iostream>
#include <vector>
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

void printPath(vector<int> path)
{
    cout << "Path : ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

void PathHelper(Node *root, vector<int> path)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    if (root->left == NULL && root->right == NULL) // leaf
    {
        printPath(path);
        path.pop_back();
        return;
    }
    PathHelper(root->left, path);
    PathHelper(root->right, path);

    path.pop_back();
}

void root_to_leaf_path(Node *root)
{
    vector<int> path;
    PathHelper(root, path);
}

int main()
{
    int arr[9] = {8, 5, 10, 3, 6, 11, 1, 4, 14};
    Node *root = buildBST(arr, 9);

    root_to_leaf_path(root);

    return 0;
}