#include<iostream>
using namespace std;

int Search(int arr[], int si, int ei, int tar)
{
    int mid = si + (ei-si)/2;
    
    if(arr[mid]==tar)
    {
        return mid;
    }

    else
    {
        if(arr[si] <= arr[mid]) // L1
        {
            if(arr[si] <= tar && tar <= arr[mid])
            {
                // Left Half
                return Search(arr, si, mid-1, tar);
            }
            else
            {
                // Right Half
                return Search(arr, mid+1, ei, tar);
            }
        }
        else // L2
        {
            if(arr[mid] <= tar && arr[ei])
            {
                // Right Half
                return Search(arr, mid+1, ei, tar);
            }
            else
            {
                // Left Half
                return Search(arr, si, mid-1, tar);
            }
        }
    }
}

int main()
{
    int arr[7] = {4,5,6,7,0,1,2};
    int n = 7;

    cout<<"Idx : "<<Search(arr,0,n-1,0)<<endl; // Output : 4
    return 0;
}