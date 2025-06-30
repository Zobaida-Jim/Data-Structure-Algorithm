#include <iostream>
#include <vector>
#include <queue>
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

static int idx = -1;
Node *buildTree(vector<int> node)
{
    idx++;
    if (node[idx] == -1)
    {
        return NULL;
    }

    Node *currNode = new Node(node[idx]);
    currNode->left = buildTree(node);
    currNode->right = buildTree(node);

    return currNode;
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0; // Height of null tree
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int currHt = max(leftHt, rightHt) + 1;

    return currHt;
}

int main()
{
    vector<int> node = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    Node *root = buildTree(node);

    cout << "Height : " << height(root) << endl;
}