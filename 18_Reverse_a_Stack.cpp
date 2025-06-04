#include<iostream>
#include<stack>
#include<list>
using namespace std;

void pushAtBottom(stack<int> &s , int val) //O(n)
{
    if(s.empty()) //Base Case
    {
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s,val);
    s.push(temp);
}

void reverseStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s, temp);
}

void printStack(stack<int> s) // if we here pass the stack as reference then it will pop all the elements
{
    while(!s.empty())
    {
        cout<<"| "<<s.top()<<" |"<<endl;
        cout<<"-----\n";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);

    cout<<"\n\nAfter Reverse\n";
    reverseStack(s);
    printStack(s);

    return 0;
}