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
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
           newNode -> next = head;
           head = newNode;
        }
    }
};

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<< temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* splitAtMid(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next; //+1
        fast = fast->next->next; // +2
    }
    if(prev != NULL)
    {
        prev->next = NULL; //Split
    }
    return slow; //rightHead
}

Node* reverse(Node* head)
{
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev; // prev is head of reverse LL
}

Node* ZigZagLL(Node* head)
{
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail = NULL;

    while(left != NULL && right != NULL)
    {
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;

        tail = right; // For Odd LL

        left = nextLeft;
        right = nextRight;
    }

    if(tail != NULL)
    {
        tail->next = right;
    }

    return head;
}

int main()
{
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    printList(ll.head);
    //1->2->3->4->5->NULL

    ll.head = ZigZagLL(ll.head);
    printList(ll.head);
    return 0;
}