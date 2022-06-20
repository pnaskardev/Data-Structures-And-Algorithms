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


int modInverse(int a,int m)
{
    vector<int>result=extendedGCD(a,m);
    int x=result[0];
    int gcd=result[2];

    if(gcd!=1)
    {
        cout<<"MMI does not exist"<<endl;
        return -1;
    }

    // just in case the ans is  negetive 
    // we have to return something which is in the range og 1 to m-1
    int ans=(x%m+m)%m;
    return ans;
}
int main(void)
{
    int a,m;
    cin>>a>>m;
    cout<<modInverse(a,m)<<endl; 
}