#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long int 
const int p=5;
const int M=1000000000+7;


int addm(int x,int y)
{
    return (x+y)%p;
}

int subm(int x,int y)
{
    return ((x-y)%p+p)%p; //extra p is added so that the remainder is never negetive 
}

int mulm(int x,int y)
{
    return (x*y)%p;
}



int binpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
        {
            res=mulm(res,x);
        }
        y/=2;
        x=mulm(x,x);
    }
    return res;
}

int divm(int x,int y)
{
    return mulm(x,binpow(y,p-2));
}

int32_t main(void)
{
    cout<<divm(50,2)<<endl;
}