#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void NextGreater(vector<int> arr, vector<int>ans) // TC = O(N)
{
    stack<int> s;
    int idx = arr.size();
    ans[idx] =  -1;
    s.push(arr[idx]);

    for(int i=idx-1; i>=0; i--)
    {
        int curr = arr[i];
        while(!s.empty() && curr>=s.top())
        {
            s.pop();
        }
        if(s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(curr);
    }

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int ar[] = {6, 8, 0, 1, 3};
    vector<int> arr(ar, ar + sizeof(ar)/sizeof(ar[0]));
    vector<int>ans (arr.size(), 0);

    NextGreater(arr,ans);

    return 0;
}