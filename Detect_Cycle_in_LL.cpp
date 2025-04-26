#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    public:
    Node* head;
    Node* tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val)
    {
        Node* newNode = new Node(val);
        if(head==NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
};

bool isCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next; //+1
        fast = fast->next->next; //+2

        /* Here check the condition after updation because slow and fast are initialized by
        so at the start of loop slow = fast , and loop will be stop */
        if(slow == fast)
        {
            cout<<"Cycle Exist\n";
            return true;
        }
    }
    cout<<"Cycle does not exisxt\n";
    return false;
}

int main()
{
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.tail->next = ll.head; // For cycle (1->2->3->4->5->1)

    isCycle(ll.head);
}