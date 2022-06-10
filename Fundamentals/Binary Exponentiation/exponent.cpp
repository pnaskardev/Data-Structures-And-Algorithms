#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int M=10000009;
long long pw(long long a, long long b) 
{
    if (b == 0)
    {
        return 1;
    }
    long long res = pw(a, b / 2);
    if (b % 2)
    {
        return res * res * a;
    } 
    else
    {
        return res * res;
    }
}

long long binpow(long long a, long long b, long long m) 
{
    if(b==0)
    {
        return a%m;
    }
    if(b%2==0)
    {
        int t=binpow(a,b,m);
        return (t*t%m);
    }
    else
    {
        int t=binpow(a,(b-1)/2,m);
        t=(t*t)%m;
        return(a*t%m);
    }
}

int main(void)
{
    cout<<pw(5,3)<<endl;
}