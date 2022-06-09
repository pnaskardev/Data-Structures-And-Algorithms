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


// checking for prime
// tab-trigger primality
bool prime(int n)
{
    // sum variable is keeping sum of factors 
    int counter=0,sum=0;

    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            sum+=i;
            counter++;
            if((n/i)!=i)
            {
                counter++;
                sum+=(n/i);
            }
        }
    }
    if(counter==2)
    {
        return true;
    }
    return false; 
}


// Number of divisors till any specified 'n'
// tab-trigger divisors
// O(nlogn)
void divisors(int n)
{
    vector<int>div(n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            div[j]++;
        }
    }
    for(auto i:div)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}


// PRIME FACTORISATION whem a single number is given as input 
// tab-trigger prime-factors
// brute-force
void factors(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
        }
    }
    if(n>1)
    {
        cout<<n<<" ";
    }
    cout<<endl;
}

// PRIME FACTORISATION WITH QUERIES
// tan-trigger prime-factors
void factorise(int n)
{
    // does the work in O(log(log n))
    // making the smallest prime sieve
    // this sieve stores the smalles prime factor a number can have
    vector<int>spf(N+1);
    for(int i=1;i<=N;i++)
    {
        spf[i]=i;
    }
    for(int i=2;i*i<=N;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<=N;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }


    // printing prime factors
    // does the work in O(n)
    while(n!=1)
    {
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
    cout<<endl;
}

int main(void)
{
    factorise(100);
}

