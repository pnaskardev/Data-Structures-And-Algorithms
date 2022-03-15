// for n elements the number of passes will ne n-1
// The number of comparisons will be sum upto n-1
// The number of swaps are sum upto n-1 elements 
// O(n^2)-->time complexity
// Suppose we have a list and we want the greatest element perform the selected number of passes to get the selected greatest element 


// bubble sort is stable

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int>&arr);
// adaptive bubble sort 
void adaptive_bubble_sort(vector<int>&arr);
int main(void)
{
    vector<int>arr={8,5,7,3,2};
    // vector<int>b(arr.size()+1);
    bubble_sort(arr);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void bubble_sort(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

//adaptive bubble_sort
void adaptive_bubble_sort(vector<int>&arr)
{
    int flag;
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}