#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string str)// TC = SC = O(N)
{
    stack <char> s;
    for(int i=0;i<str.size();i++)
    {
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[') // Checking for Openning
        {
            s.push(ch);
        }
        else // Closing
        {
            if(s.empty()) // Insufficient Openning
            {
                return false;
            }

            //Matching
            char top = s.top();
            if((top=='(' && ch==')') || (top=='{' && ch=='}') || (top=='[' && ch==']'))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if(s.empty())
    {
        return true;
    }
    else
    {
        // Insufficient Closing
        return false;
    }
}

int main()
{
    string str1 = "([}])"; //Invalid
    string str2 = "([{}])";// Valid

    cout<<isValid(str1)<<endl;
    cout<<isValid(str2)<<endl;

    return 0;
}