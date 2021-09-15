#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *prev;
    Node *next;
}*first=NULL;
void create(vector<int>arr)
{
    Node *t,*last;
    first=new Node;
    first->data=arr[0];
    first->prev=first->next=NULL;
    last=first;
    for(int i=1;i<arr.size();i++)
    {
        t=new Node;
        t->data=arr[i];
        t->prev=last;
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
int len(Node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}
void insert(Node *p, int index,int x)
{
    Node *t;
    if(index<0||index>len(p))
    {
        return ;
    }
    if(index==0)
    {
        t=new Node;
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t=new Node;
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)
        {
            p->next->prev=t;
        }
        p->next=t;
    }
}
int Delete(Node* p,int index)
{
    int x=-1;
    if(index<0||index>len(p))
    {
        return x;
    }
    if(index==1)
    {
        first=first->next;
        x=p->data;
        delete p;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        x=p->data;
        p->prev->next=p->next;
        if(p->next!=NULL)
        {
            p->next->prev=p->prev;
        }
        delete p;
    }
    return x;
}
void display(Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main(void)
{
    vector<int>arr={10,20,30,40,50,60};
    create(arr);
    display(first);
    cout<<endl;
    cout<<"Result after deleting"<<endl;
    cout<<Delete(first,5)<<endl;
    
}