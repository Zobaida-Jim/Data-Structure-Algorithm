#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};

class doublyList
{
    public:
    Node* head;
    Node* tail;
    doublyList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node* newNode = new Node(val);
        if(head != NULL)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            head = tail = newNode;
        }
    }

    void pop_front()
    {
        Node* temp = head;
        head = head->next;
        if(head != NULL)
        {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        Node* temp = tail;
        tail = tail->prev;
        if(tail != NULL)
        {
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }

    void printList()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<< temp->data<<" <=> ";
            temp = temp->next;
        }
        cout<<" NULL \n";
    }
};

int main()
{
    doublyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);

    dbll.printList();

    dbll.push_back(5);
    dbll.printList();

    dbll.pop_front();
    dbll.printList();

    dbll.pop_back();
    dbll.printList();

    return 0;
}