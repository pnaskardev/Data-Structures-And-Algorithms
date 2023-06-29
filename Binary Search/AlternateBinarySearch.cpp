#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<int> arr = {1,1,1,1,2,2,2,3,3,3};

    int target=2;

    auto pred=[&](int i)
    {
        return arr[i]<target;
    };

    int l=-1, r=arr.size();
    while(r-l>1)
    {
        int m=(l+r)/2; 
        if(pred(m))
            l=m;
        else
            r=m;
    }
}