#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a==0 || b==0)
    {
        return a^b;
    }
    else
    {
        return gcd(b%a,a);
    }
}
int main(void)
{
    cout<<gcd(2,1024)<<endl;
}