#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Stack
{
    public:
    int size;
    int top;
    int *s;
};
int main(void)
{
    Stack st;
    cout<<"Enter the size of the stack:-"<<endl;
    cin>>st.size;
    st.s=new int[st.size];
    st.top=-1;
    
}