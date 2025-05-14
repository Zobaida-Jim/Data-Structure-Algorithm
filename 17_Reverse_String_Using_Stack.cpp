#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverseString(string str) //TC = O(N) , SC = O(N); where N is the size of string
{
    stack<char> s;
    string ans;
    for(int i=0; i<str.size(); i++)
    {
        s.push(str[i]);
    }

    while(!s.empty())
    {
        char ch = s.top();
        ans += ch;
        s.pop();
    }

    return ans;
}

int main()
{
    string str = "abcde";

    cout<<"Reverse = "<<reverseString(str)<<endl;
    return 0;
}