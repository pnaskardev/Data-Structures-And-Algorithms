#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int data;
    Node* next;
};
void push(int x, Node *&top);
int pop(Node *&top);
int peek(int pos);
void display(Node *&top);
int main(void)
{
    Node *top=NULL;
    push(10,top);
    push(20,top);
    push(30,top);
    push(40,top);
    push(50,top);
    display(top);
    cout<<"result after popping->"<<pop(top)<<endl;
    display(top);

}
void push(int x, Node *&top)
{
    Node *t=new Node();
    if(t==NULL)
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
int pop(Node *&top)
{
    int x=-1;
    Node *p=new Node();
    if(top==NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        p=top;
        top=top->next;
        x=p->data;
        delete(p);
    }
    return x;
}

int peek(int pos,Node *&top)
{
    int x=-1;
    Node *p=top;
    for(int i=0;p!=NULL && i<pos-1;i++)
    {
        p=p->next;
    }
    if(p!=NULL)
    {
        x=p->data;
        return x;
    }
    return x;
}
void display(Node *&top)
{
    Node *p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}