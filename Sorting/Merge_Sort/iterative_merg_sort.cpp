#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
void Merge(vector<int>&arr, int low, int mid, int high,vector<int>&b)
{
    int i = low;
    int j = mid+1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k++] = arr[i++];
        } 
        else 
        {
            b[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = arr[i++];
    }
    while (j <= high)
    {
        b[k++] = arr[j++];
    }
}
 
void IterativeMergeSort(vector<int>&arr, int n,vector<int>&b)
{
    int p;
    for (p=2; p<=n; p=p*2)
    {
        for (int i=0; i+p-1<n; i=i+p)
        {
            int low = i;
            int high = i+p-1;
            int mid = (low+high)/2;
            Merge(arr, low, mid, high,b);
        }
    }
    if (p/2 < n)
    {
        Merge(arr, 0, p/2-1, n-1,b);
    }
}
 
int main() 
{
 
    vector<int>arr= {2, 5, 8, 12, 3, 6, 7, 10};
    vector<int>b(arr.size()+1);
    int n =arr.size();
    IterativeMergeSort(arr, n,b);
    for(auto i:b)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}