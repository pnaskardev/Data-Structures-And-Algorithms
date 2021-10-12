#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int min_rot(vector<int>arr)
{
    int start=0,high=arr.size()-1,ans=-1;
    while(start<=high)
    {
        int mid =start+(high-start)/2;
        if(arr[mid]<arr[high])
        {
            ans=mid;
            high=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    return arr[ans];
}
int main(void)
{
    vector<int>arr={7,8,9,1,2,4,5,6};
    cout<<min_rot(arr)<<endl;

}