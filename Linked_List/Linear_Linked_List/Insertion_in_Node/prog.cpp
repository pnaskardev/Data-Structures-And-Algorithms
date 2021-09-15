#include<iostream>
#include<bits/stdc++.h>
#define int long long int
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

}*first=NULL,*rear=NULL;
void create(vector<int>&arr)
{
    first=new Node();
    first->data=arr[0];
    first->next=NULL;
    rear=first;
    Node *temp=NULL;
    for(int i=1;i<arr.size();i++)
    {
        temp=new Node();
        temp->data=arr[i];
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
}
int max_el(Node*p)
{
    int m=INT_MIN;
    while(p!=NULL)
    {
        if(p->data>m)
        {
            m=p->data;
            p=p->next;
        }
    }
    return m;
}
void display(Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
   
}
Node* search(Node*p,int key)
{
    Node *q;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            return p;
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
    return NULL;
}
int count(Node *first)
{
    Node *p=first;
    int c=0;
    while(p!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
} 
void insert(Node *p,int pos,int d)
{
    Node* temp;
    if(pos<0 || pos>count(p))
    {
        return;
    }
    else
    {
        temp=new Node();
        temp->data=d;
        if(pos==0)
        {
            temp->next=first;
            first=temp;
        }
        else
        {
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            temp->next=p->next;
            p->next=temp;
        }
    }
}
int32_t main(void)
{
    vector<int>arr={3,5,7,10,15};
    create(arr);
    int key=10;
    display(first);
    cout<<rear->data<<endl;
    // insert(first,4,9);
    // display(first);
}
