#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// Create BT
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

static int idx = -1;

Node *buildTree(vector<int> nodes) // Build a tree and return the pointer of Root Node
{
    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }

    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);  // Left subtree
    currNode->right = buildTree(nodes); // Right subtree

    return currNode;
}

/// Largest BST
class Info
{
public:
    bool isBST;
    int min;
    int max;
    int size;

    Info(bool isBST, int min, int max, int size)
    {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

static int maxSize;

Info *largestBST(Node *root)
{
    if (root == NULL)
    {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    // We can use another Base Case
    /* if(root == NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return new Info(true,root->data,root->data,1);
    }
    */
    Info *leftInfo = largestBST(root->left);
    Info *rightInfo = largestBST(root->right);

    int currmin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currmax = max(root->data, max(leftInfo->max, rightInfo->max));
    int currsz = leftInfo->size + rightInfo->size + 1;
    if (leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->max && root->data < rightInfo->min)
    {
        maxSize = max(maxSize, currsz);
        return new Info(true, currmin, currmax, currsz);
    }

    return new Info(false, currmin, currmax, currsz);
}

int main()
{
    vector<int> arr = {50, 30, 5, -1, -1, 20, -1, -1, 60, 45, -1, -1, 70, 65, -1, -1, 80, -1, -1};
    Node *root = buildTree(arr);

    largestBST(root);
    cout << "Max size : " << maxSize << endl;
    return 0;
}