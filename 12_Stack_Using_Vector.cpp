#include<iostream>
#include<vector>
using namespace std;

class Stack{
    vector<int>vec;
    public:
    bool isempty()
    {
        return vec.empty();
    }
    void push(int val) // O(1)
    {
        vec.push_back(val);
    }
    void pop() // O(1)
    {
        if(!isempty())
        {
            vec.pop_back();
        }
        else
        {
            cout<<"Empty Stack\n";
        }
    }
    int top() // O(1)
    {
        if(isempty())
        {
            cout<<"Empty Stack\n";
            return -1;
        }
        return vec.back();
    }
};

int main()
{
    Stack s;
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