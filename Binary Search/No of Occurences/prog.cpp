#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int binary(vector<int>arr,int target)
{
    int start=0,end=arr.size()-1,ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]>=target)
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}
int main(void)
{
    vector<int>arr={1,3,5,7,7,7,10};
    int lb=binary(arr,7);
    int up=binary(arr,7+1);
    up=up-1;
    cout<<lb<<endl;
    cout<<up<<endl;
    cout<<up-lb+1<<endl;

}