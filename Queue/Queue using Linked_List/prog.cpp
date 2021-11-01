#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int data;
    Node *next;
};
void enqueue(int x);
int dequeue(Node *&first,Node *&last);
void display(Node *first);
int main(void)
{
    Node *first=NULL,*last=NULL;

}
void enqueue(int x,Node *&first, Node *&last)
{
    Node *t=new Node();
    if(t==NULL)
    {
        cout<<"queue is full"<<endl;
    }
    else
    {
        t->data=x;
        t->next=NULL;
        if(first==NULL)
        {
            first=t;
            last=t;
        }
        else
        {
            last->next=t;
            last=t;
        }
    }
}
int dequeue(Node *&first,Node *&last)
{
    int x=-1;
    Node *t ;
    if(first==NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        x=first->data;
        t=first;
        first=first->next;
        delete(t);
    }
}
void display(Node *first)
{
    Node *p=first;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}