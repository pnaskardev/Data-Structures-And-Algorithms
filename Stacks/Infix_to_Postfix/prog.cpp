#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    char data;
    Node* next;
};
void push(Node *&first,char x);
void display(Node *&first);
char pop(Node *&first);
int pre(char x);
char top(Node *first);
bool operand(char x);
string infixToPostfix(string s, Node *&first);
int main(void)
{
    Node *first=NULL;
    display(first);
    string s="a+b*c";
    string res=infixToPostfix(s,first);
    cout<<res<<endl;
}
void push(Node *&first,char x)
{
    Node *temp=new Node();
    if(temp==NULL)
    {
        cout<<"Stack is full"<<endl;
    }
    else
    {
        temp->data=x;
        temp->next=first;
        first=temp;
    }
}
void display(Node *&first)
{
    Node *p=first;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}
char pop(Node *&first)
{
    Node *t;
    int x=-1;
    if(first==NULL)
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        t=first;
        first=first->next;
        x=t->data;
        delete t;
    }
    return x;
}
int pre(char x)
{
    if(x=='+'||x=='-')
    {
        return 1;
    }
    else if(x=='*'||x=='/')
    {
        return 2;
    }
    return 2;
}
bool operand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
    {
        return false;
    }
    return true;
}
char top(Node *first)
{
    return first->data;
}
string infixToPostfix(string s, Node *&first)
{
    string res;
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if(operand(c))
        {
            res=res+c;
        }
        else if(c=='(')
        {
            push(first,c);
        }
        else if(c==')')
        {
            while(top(first)!='(')
            {
                res+=top(first);
                pop(first);
            }
            pop(first);
        }
        else
        {
            while(first!=NULL && pre(c)<=pre(top(first)))
            {
                res+=top(first);
                pop(first);
            }
            push(first,c);
        }
    }
    while(first!=NULL)
    {
        res+=top(first);
        pop(first);
    }
    return res;
}