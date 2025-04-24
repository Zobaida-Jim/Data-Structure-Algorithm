// Pivot and Partirion Approach

#include<iostream>
using namespace std;

int Partition(int arr[], int si, int ei)
{
    int i = si-1;
    int pivot = arr[ei];

    for(int j=si;j<ei;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i],arr[ei]);
    //pivotIdx = i
    return i;
}

void quickSort(int arr[], int si, int ei)
{
    if(si>=ei) // Base Case
    {
        return;
    }

    int pivotIdx = Partition(arr, si, ei);

    quickSort(arr, si, pivotIdx-1); // Left Half
    quickSort(arr, pivotIdx+1, ei); // Right Half
}

void PrintArray(int arr[], int n)
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

    quickSort(arr,0,n-1);
    PrintArray(arr, n);

    return 0;
}