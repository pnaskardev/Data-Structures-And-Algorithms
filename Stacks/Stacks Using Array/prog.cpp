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
void create(Stack *st);
void display(Stack st);
void push(Stack *st,int x);
int pop(Stack *st);


int main(void)
{
    Stack st;
    create(&st);
    vector<int>arr={10,20,30,40,50};
    for(auto i:arr)
    {
        push(&st,i);
    }
    cout<<"after push function the result is :-"<<endl;
    display(st);
}



void create(Stack *st)
{
    cout<<"Enter the size of the stack:-"<<endl;
    cin>>st->size;
    st->s=new int[st->size];
    st->top=-1;
}
void display(Stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        cout<<st.s[i]<<" ";
    }
    cout<<endl;
}

void push(Stack *st,int x)
{
    if(st->top==st->size-1)
    {
        cout<<"stack overflow"<<endl;
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
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}