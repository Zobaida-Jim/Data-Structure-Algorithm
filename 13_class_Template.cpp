#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<class T> // T can be int/char/float any other types. and its a template class
class Stack{
    vector<T>vec;
    public:
    bool isempty()
    {
        return vec.empty();
    }
    void push(T val) // O(1)
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
    T top() // O(1)
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
    Stack<char> s; // Now we can change the type of stack from here no need to changes in Stack class
    s.push('d');
    s.push('c');
    s.push('b');
    s.push('a');

    while(!s.isempty())
    {
        cout<<"| "<<s.top()<<" |"<<endl;
        cout<<"-----\n";
        s.pop();
    }

    return 0;
}