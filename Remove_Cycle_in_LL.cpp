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
            newNode->next = head;
            head = newNode;
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

void removeCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next; // +1
        fast = fast->next->next;// +2

        if(slow==fast)
        {
            cout<<"Cycle Exist \n";
            isCycle = true;
            break;
        }
    }
    if(!isCycle)
    {
        cout<<"Cycle doesn't Exist\n";
        return;
    }

    //Update slow
    slow = head;
    if(slow == fast)
    {
        // Special Case : tail->next = head
        while(fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL; // Remove Cycle;
    }
    else
    {
        Node* prev;
        while(slow != fast)
        {
            slow = slow->next; // +1
            prev = fast;
            fast = fast->next; //+1
        }
        prev->next = NULL; // Remove Cycle
    }   
}

int main()
{
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next = ll.head; // 1->2->3->4->5->1

    removeCycle(ll.head);
    printList(ll.head);

    return 0;
}