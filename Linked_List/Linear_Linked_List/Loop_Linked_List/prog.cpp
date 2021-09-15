#include<iostream>
#include<bits/stdc++.h>
#define int long long int
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

}*first=NULL,*second=NULL,*third=NULL;
void create(vector<int>&arr,Node *&p)
{
    p=new Node();
    p->data=arr[0];
    p->next=NULL;
    Node *last;
    last=p;
    Node *temp=NULL;
    for(int i=1;i<arr.size();i++)
    {
        temp=new Node();
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
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
void insert_in_a_sorted_arr(Node* p,int x)
{
    Node *t,*q=NULL;
    t=new Node();
    t->data=x;
    t->next=NULL;
    if(p==NULL)
    {
        first=t;
    }
    else
    {
        while(p!=NULL && p->data<x)
        {
            q=p;
            p=p->next; 
        }
        if(p==first)
        {
            cout<<"p==first"<<endl;
            t->next=first;
            first=t;
        }
        else
        {
            cout<<"else"<<endl;
            t->next=q->next;
            q->next=t;
        }
    }
}
void deletNode(int n)
{
    Node *p=first;
    Node *q=NULL;
    if(n<1||n>count(p))
    {
        return;
    }
    else
    {
        if(n==1)
        {
            q=first;
            first=first->next;
            delete q;
        }  
        else
        {
            for(int i=0;i<=n-1;i++)
            {
                q=p;
                p=p->next;
            }
            q->next=p->next;
            delete p;
        } 
    }
    
}
bool check_sort(Node *p)
{
    int x=INT_MIN;
    while (p!=NULL)
    {
        if(p->data<x)
        {
            return false;
        }
        else
        {
            x=p->data;
            p=p->next;
        }
    }
    return true;
    
}
void remove_duplicate(Node *p)
{
    Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
    first=q;
}
void reverse2(Node* p) //sliding pinters method
{
    Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void merge (Node *p,Node *q) //Two sorted LinkedLists
{
    Node *last;
    if(p->data<q->data)
    {
        third=p;
        last=p;
        p=p->next;
        third->next=NULL;

    }
    else
    {
        third=q;
        last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL)
    {
        last->next=p;
    }
    if(q!=NULL)
    {
        last->next=q;
    }
}
int isLoop(Node *f)
{
    Node*p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;      
    } while (p&&q && p!=q);
    if(p==q)
    {
        return 1;
    }
    return 0;
}
int32_t main(void)
{
    vector<int>arr={10,20,30,40,50};
    vector<int>arr2={5,15,25,35,45};
    create(arr,first);
    display(first);
    Node* t1,*t2;
    t1=first;
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    if(isLoop(first))
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    
}
