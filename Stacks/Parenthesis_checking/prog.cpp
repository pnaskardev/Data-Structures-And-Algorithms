#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isBalance(string s);
int main(void)
{
    string s="((a+b)*(c+d))";
    // cin>>s;
    cout<<isBalance(s)<<endl;
}

//this program does not check for the parenthesis is done properly or not 
// it wont work for ((a+)b*(c+d))
bool isBalance(string s)
{
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.empty()?true:false;
}