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

int sum_of_Nodes(Node *root)
{
    if (root == NULL)
    {
        return 0; // sum of nodes for empty tree
    }
    int leftsum = sum_of_Nodes(root->left);
    int rightsum = sum_of_Nodes(root->right);

    return (leftsum + rightsum + root->data);
}

int main()
{
    vector<int> node = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(node);

    cout << "Sum of Nodes : " << sum_of_Nodes(root) << endl;
}