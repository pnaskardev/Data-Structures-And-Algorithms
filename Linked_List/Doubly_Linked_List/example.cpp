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
void display(Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
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
int main(void)
{
    
}