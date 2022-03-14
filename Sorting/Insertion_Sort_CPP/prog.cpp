#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int>&arr);
int main(void)
{
    int n;
    cout<<"Enter the size of the array:-"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i<<":->";
        cin>>arr[i];
    }   
    insertion_sort(arr);
    cout<<"Result after sorting the array is:->"<<endl;
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}


void insertion_sort(vector<int>&arr)
{
    for(int j=1;j<arr.size();j++)
    {
        int key=arr[j];
        int i=j-1;
        while(i>=0 and arr[i]>key)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
}