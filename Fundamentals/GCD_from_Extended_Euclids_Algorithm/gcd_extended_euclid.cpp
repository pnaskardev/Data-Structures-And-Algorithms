#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// EXTENDED EUCLIDS ALGORITHM
vector<int> extendedGCD(int a,int b)
{
    if(b==0)
    {
        // return the values of x and y
        return {1,0,a};
    }
    vector<int> result=extendedGCD(b,a%b);
    int smallX=result[0];
    int smallY=result[1];
    int gcd=result[2];
    int x=smallY;
    int y=smallX-(a/b)*smallY;


    return {x,y,gcd};
}


int main(void)
{
    int a,b;
    cin>>a>>b;
    // ax+by=gcd(a,b);
    auto res=extendedGCD(a,b);
    cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
}