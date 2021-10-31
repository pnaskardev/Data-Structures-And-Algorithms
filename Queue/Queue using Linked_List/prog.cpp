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
    
}