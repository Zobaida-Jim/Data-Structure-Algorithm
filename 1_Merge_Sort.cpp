// Divide & Conquer

#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei)
{
    vector<int>temp;

    int i = si;
    int j = mid+1;

    while(i<=mid && j<=ei)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]); // Updated at a time
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid) // The rest of the elements will be copied directly
    {
        temp.push_back(arr[i++]);
    }

    while(j<=ei)
    {
        temp.push_back(arr[j++]);
    }

    // Vctor -> Original array
    for(int idx=si, x=0; idx<=ei ;idx++) // Original Array
    {
        arr[idx] = temp[x++];
    }
}

void mergeSort(int arr[],int si, int ei) // first step = Divide
{
    if(si>=ei) // Base Case
    {
        return ;
    }

    int mid = si + (ei-si)/2;

    mergeSort(arr, si, mid); // Left Half
    mergeSort(arr, mid+1, ei); // Right Half

    merge(arr, si, mid, ei); // Conquer
}

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[6] = {6,3,7,5,2,4};
    int n = 6;

    mergeSort(arr,0,n-1);
    printArray(arr,n);

    return 0;
}