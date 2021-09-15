#include<iostream>
#include<bits/stdc++.h>
#define int long long int
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

}*head=NULL;
int length(Node*p)
{
    int c=0;
    do
    {
        p=p->next;
        c++;
    } while (p!=head);
    return c;
}
void insert(Node*p,int index,int x)
{
    Node *t;
    if(index<0||index>length(p))
    {
        return;
    }
    if(index==0)
    {
        t=new Node;
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next!=head)
            {
                p->next=t;
                t->next=head;
                head=t;
            }
        }
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
void create_circular(vector<int>arr)
{
    Node *last,*t;
    head=new Node;
    head->data=arr[0];
    head->next=head;
    last=head;
    for(int i=1;i<arr.size();i++)
    {
        t=new Node;
        t->data=arr[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void display(Node *h)
{
    do
    {
        cout<<h->data<<" ";
        h=h->next;
    } while (h!=head);
    cout<<endl;
}
int Delete(Node *p,int index)
{
    Node *q;
    int x;
    if(index<0||index>length(p))
    {
        return -1;
    }
    if(index==1)
    {
        while(p->next!=head)
        {
            p=p->next;
        }
        x=head->data;
        if(head==p)
        {
            delete head;
            head=NULL;
        }
        else
        {
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }
    else
    {
        for(int i=0;i<index-2;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}
int32_t main(void)
{
    vector<int>arr={10,20,30,40,50};
    create_circular(arr);
    display(head);
    // insert(head,5,10);
    // display(head);
    Delete(head,5);
    display(head);
}
