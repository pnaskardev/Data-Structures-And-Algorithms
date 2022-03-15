#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int>&arr, int low, int mid, int high,vector<int>&b);
void recursive_merge_sort(vector<int>&a,int l,int h,vector<int>&b);
int main(void)
{
    vector<int>arr= {2, 5, 8, 12, 3, 6, 7, 10};
    vector<int>b(arr.size()+1);
    int n =arr.size();
    recursive_merge_sort(arr,0,arr.size()-1,b);
    for(auto i:b)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

void recursive_merge_sort(vector<int>&a,int l,int h,vector<int>&b)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        recursive_merge_sort(a,l,mid,b);
        recursive_merge_sort(a,mid+1,h,b);
        Merge(a,l,mid,h,b);
    }
}

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

