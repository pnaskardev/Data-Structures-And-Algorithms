#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int data;
    Node* next;
};
void push(Node *&first,Node*&last,int x);
void display(Node *&first);
int pop(Node *&first);
int main(void)
{
    Node *first=NULL,*last=NULL;
    push(first,last,20);
    display(first);
}

void push(Node *&first,Node*&last,int x)
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
int pop(Node *&first)
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