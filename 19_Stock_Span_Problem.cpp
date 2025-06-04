#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void Stock_Span(vector<int> stock, vector<int> span)
{
    stack<int> s;
    s.push(0);
    span[0] = 1; // For Day 1. There is no Prev_High

    for(int i=1;i<stock.size();i++)
    {
        int curr = stock[i];
        while(!s.empty() && curr >= stock[s.top()])
        {
            s.pop();
        }
        
        if(s.empty())
        {
            span[i] = i+1;
        }
        else
        {
            int prev_high = s.top();
            span[i] = i - prev_high;
        }
    }

    for(int i=0; i<span.size(); i++)
    {
        cout<<span[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 85, 100};
    vector<int> stock(arr, arr + sizeof(arr)/sizeof(arr[0])); // Old version

    vector<int>span (stock.size(),0); // Initialize with 0

    Stock_Span(stock, span);

    return 0;
}