#include<iostream>
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

/// LL is the collection of Nodes, so we need to creat a class to collect nodes

class List
{
    Node* head;
    Node* tail;

    public:
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

    void printList()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout<< temp->data<<" -> ";
            temp = temp->next;
        }

        cout<<"NULL"<<endl;
    }

    void insert(int val, int pos)
    {
        Node* newNode = new Node(val);
        Node* temp = head;

        for(int i=0; i<pos-1; i++) // find pos-1 (temp)
        {
            if(temp==NULL) //if Given position is out of LL
            {
                cout<<" Invalid Position"<<endl;
            }
            temp = temp->next; // Update temp
        }

        // temp is now at pos-1 i.e. left/prev
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front()
    {
        if(head==NULL)
        {
            cout<<"LL is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        Node* temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL; // temp = tail's previoes node
        delete tail;
        tail = temp;
    }

    int searchItr(int key)
    {
        Node* temp = head;
        int idx = 0;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    int helper(Node* temp, int key) // temp = local head, which will update
    {
        if(temp == NULL)
        {
            return -1;
        }
        if(temp->data == key)
        {
            return 0;
        }
        int idx = helper(temp->next, key);

        if(idx == -1)
        {
            return -1;
        }
        return idx + 1;
    }
    int searchRec(int key)
    {
        return helper(head,key);
    }

    void reverse()
    {
        Node* curr = head;
        Node* prev = NULL;

        while(curr != NULL)
        {
            Node* next = curr->next;
            curr->next = prev;
            // Updations for next itr
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int getSize()
    {
        Node* temp = head;
        int sz = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            sz++;
        }
        return sz;
    }
    void removeNth(int n)
    {
        int size = getSize();
        Node* prev = head;
        for(int i=1; i<(size-n); i++)
        {
            prev = prev->next;
        }
        Node* toDel = prev->next;
        cout<<"Going to be delet : "<<toDel->data<<endl;
        prev->next = prev->next->next;
    }
};

int main()
{
    List ll; // In this LL there is no value, so its called empty LL

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    //ll.printList(); //1 -> 2 -> 3 -> NULL

    ll.push_back(4);
    ll.push_back(5);
    ll.printList(); // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    //ll.insert(100,2);
    //ll.printList(); // 1 -> 2 -> 100 -> 3 -> 4 -> 5 -> NULL

    //ll.pop_front();
    //ll.printList(); // 2 -> 100 -> 3 -> 4 -> 5 -> NULL

    //ll.pop_back();
    //ll.printList(); // 2 -> 100 -> 3 -> 4 -> NULL

    //cout<< ll.searchItr(4)<<endl;

    //cout<< ll.searchRec(3)<<endl;

    //ll.reverse();
    //ll.printList();
    
    ll. removeNth(3);
    ll.printList();

    return 0;
}