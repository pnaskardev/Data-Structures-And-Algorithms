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
void create(Stack *st)
{
    cout<<"enter size"<<endl;
    cin>>st->size;
    st->top=-1;
    st->s=new int;
}
void display(Stack *st)
{
    for(int i=st->top;i>=0;i--)
    {
        cout<<st->s[i]<<" ";
    }
    cout<<endl;
}
void push(Stack *st,int x)
{
    if(st->top==st->size-1)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        st->top++;
        st->s[st->top]=x;    
    }
}
int pop(Stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        x=st->s[st->top--];
    }
    return x;
}
int peek(Stack st,int index)
{
    int x=-1;
    if(st.top-index+0)
    {
        cout<<"Invalid Index"<<endl;
    }
    else
    {
        x=st.s[st.top-index+1];
    }
    return x;
}
int isEmpty(Stack st)
{
    if(st.top==-1)
    {
        return true;
    }
    return false;
}
int isFull(Stack st)
{
    return st.top==st.size-1;
}
int stakTop(Stack st)
{
    if(!isEmpty(st))
    {
        return st.s[st.top];
    }
    return -1;
}
int main(void)
{
    Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    display(&st);
    cout<<peek(st,3)<<endl;
}