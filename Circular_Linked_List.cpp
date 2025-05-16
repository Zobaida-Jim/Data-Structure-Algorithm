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

class circular_LL
{
    public:
    Node* head;
    Node* tail;
    circular_LL()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) // Insert element at head
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = tail = newNode;
            newNode->next = newNode;
            return;
        }
        else
        {
            Node* temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) // Insert element at end
    {
        cout<<endl<<"Insert element at end"<<endl;
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            push_front(val);
            return;
        }
        else
        {
            Node* temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

   void push_at_position(int val, int pos)// Insert at position
    {
        cout<<endl<<"Insert"<<" "<<val<<" at "<<pos<<" postion"<<endl;
        if(pos == 0)
        {
            push_front(val);
            return;
        }
        else
        {
            Node* newNode = new  Node(val);
            Node* temp = head;
            for(int i=0;i<pos-1;i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void pop_front() // Delete element from head
    {
        cout<<endl<<"Delete element from head"<<endl;
        if(head == NULL)
        {
            cout<<"Empty Linked List"<<endl;
            return;
        }
        else
        {
            Node* temp = head;
            Node* temp1 = head->next;
            while(temp1->next != head)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp->next;
            head = temp->next;
            delete temp;
        }
    }

    void pop_back()
    {
        cout<<endl<<"Delete element from end"<<endl;
        if(head == NULL)
        {
            cout<<"Empty Linked List"<<endl;
            return;
        }
        else if(head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }
        else
        {
            Node* temp = head;
            while(temp->next->next != head)
            {
                temp = temp->next;
            }
            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
        }
    }

    void delete_element_from_positio(int pos)
    {
        cout<<endl<<"Delete element from "<<pos<<" position"<<endl;
        if(pos == 0)
        {
            cout<<"Invalid Position"<<endl;
            return;
        }
        else
        {
            Node* temp = head;
            for(int i=0;i<pos-1;i++)
            {
                temp = temp->next;
            }
            Node* delNode = temp->next;
            temp->next = delNode->next;
            cout<<"Delete "<<delNode->data<<endl;
            delete delNode;
        }
    }

    void printList()
    {
        Node* temp = head;                  
        do                                   
        {                                      
            cout<<temp->data<<" -> ";      
            temp = temp->next;
        }while(temp != head);
        cout<<"( Back to head )"<<endl;
    }/*while(true) -----> Another way to print List
    {
        cout<<temp->data;
        temp = temp->next;
        if(temp==head) break;
    }*/
};

int main()
{
    circular_LL l;
    cout<<"Insert element at head"<<endl;
    l.push_front(50);
    l.push_front(40);
    l.push_front(30);
    l.push_front(20);
    l.push_front(10);
    l.printList();

    l.push_back(11);
    l.printList();

    l.push_at_position(49,3);
    l.printList();

    l.pop_front();
    l.printList();

    l.pop_back();
    l.printList();

    l.delete_element_from_positio(3);
    l.printList();

    return 0;
}