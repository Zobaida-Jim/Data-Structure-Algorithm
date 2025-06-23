#include<iostream>
#include<algorithm>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class queue
{
    public:
    Node* head;
    Node* tail;
    queue()
    {
        head = NULL;
        tail = NULL;
    }

    void push(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = tail = newNode;
            return;
        } 
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop()
    {
        Node* temp = head;
        head = head->next ;
        delete temp;
    }

    int front()
    {
        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}