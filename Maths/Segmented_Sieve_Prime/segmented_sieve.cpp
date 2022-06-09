#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Sieve of erastothenes
// tab-trigger sieve
const int N=1000000;
vector<bool> sieve(N+1, true);
void create_sieve()
{
    int n=N;
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; i++) 
    {
        if (sieve[i]==true) 
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }   
}
vector<int>generatePrimes(int n)
{

    // HERE N IS THE SQRT(R)
    vector<int>ds;
    for(int i=2;i<=n;i++)
    {
        if(sieve[i]==true)
        {
            ds.push_back(i);
        }
    }
    return ds;
}



int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;

        // STEP-1 GENERATE ALL PRIMES TILL SQRT(R)
        vector<int>primes=generatePrimes(sqrt(r));


        // STEP-2 
        // CREATE A DUMMY ARRAY OF SIZE R-L+1 AND MAKE EACH AND EVERY ELEMENT AS 1
        vector<int>dummy((r-l+1),1);


        // STEP-3 
        // MARK ITS ALL THE MULTIPLES AS FALSE 
        for(auto pr:primes)
        {
            int firstMultiple=(l/pr)*pr;
            if(firstMultiple<l)
            {
                firstMultiple+=pr;
            }
            // MAX BECAUSE WE NEED TO START MARKING FROM THE L AND INSIDE THE RANGE 
            // NOT OUTSIDE THE RANGE 
            // THE SQUARE OF THE PRIME MAY OR MAY NOT LIE IN THE RANGE 
            for(int j=max((pr*pr),firstMultiple);j<=r;j+=pr)
            {
                dummy[j-l]=0;
            }
        } 

        // PRINT THE PRIMES
        for(int i=l;i<=r;i++)
        {
            if(dummy[l-i]==1)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}