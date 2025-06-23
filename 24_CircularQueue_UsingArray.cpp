#include<iostream>
using namespace std;

class queue{
    int* arr;// Dynamic Array
    int capacity;
    int currSize;
    int f,r;

    public:
    queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int data)
    {
        if(currSize == capacity)
        {
            cout<<"Queue is FULL"<<endl;
            return;
        }
        r = (r+1) % capacity;
        arr[r] = data;
        currSize++;
    }

    void pop()
    {
        if(empty())
        {
            cout<<"Queue is EMPTY"<<endl;
            return;
        }
        f = (f+1) % capacity;
        currSize--;
    }

    int front()
    {
        if(empty())
        {
            cout<<"Queue is EMPTY"<<endl;
            return -1;
        }
        return arr[f];
    }

    bool empty()
    {
        return currSize == 0;
    }
};

int main()
{
    queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.push(6);
    cout<<q.front()<<endl;
}