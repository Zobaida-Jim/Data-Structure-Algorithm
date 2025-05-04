#include<iostream>
#include<list> // for STL
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node* next;
    Node(T val)
    {
        data = val;
        next = NULL;
    }
};

template<class T>
class Stack{
    public:
    // list<T> ll;
    Node<T>* head;
    Stack()
    {
        head = NULL;
    }

    void push(T val)
    {
        // ll.pop_front(val); -> STL
        Node<T>* newNode = new Node<T>(val);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop()
    {
        //ll.pop_front();
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T top()
    {
        //return ll.front(); -> ll.front = head of a LL
        return head->data;
    }

    bool isempty()
    {
        // return ll.size() == 0;
        return head == NULL;
    }
};

int main()
{
    Stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isempty())
    {
        cout<<"| "<<s.top()<<" |"<<endl;
        cout<<"-----\n";
        s.pop();
    }

    return 0;
}