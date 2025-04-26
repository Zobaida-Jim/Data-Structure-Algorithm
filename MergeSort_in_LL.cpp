#include<iostream>
#include<list>
#include<iterator>
using namespace std;

class Node /// Class for individual Node
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
    void push_front (int val)
    {
        Node* newNode = new Node(val); //Dynamic
        // Node* newNode(val); Static
        
        // Checking is the LL empty or not
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

    void push_back(int val)
    {
        Node* newNode = new Node(val);
        if(head==NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

void printList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
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
        slow = slow->next; // +1
        fast = fast->next->next; // +2
    }

    if(prev != NULL)
    {
        prev->next = NULL; // Split at amiddle
    }

    return slow; // slow = rightHead
}

Node* merge(Node* left, Node* right) //left = leftHead & right = rightHead
{
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL)
    {
        if(i->data <= j->data)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        else
        {
            ans.push_back(j->data);
            j = j->next;
        }
    }
    while(i != NULL)
    {
        ans.push_back(i->data);
        i = i->next;
    }
    while(j != NULL)
    {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}

Node* mergeSort(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* rightHead = splitAtMid(head); // returns the head of right half LL

    Node* left = mergeSort(head); // Left half LL
    Node* right = mergeSort(rightHead); //right half LL

    return merge(left, right); // return head of sorted LL
}
int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    //ll.push_front(5);
    printList(ll.head);

    ll.head = mergeSort(ll.head);// that will override the head of original LL of ll
    printList(ll.head);
}