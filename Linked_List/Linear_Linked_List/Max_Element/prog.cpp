#include<iostream>
#include<bits/stdc++.h>
#define int long long int
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

}*first=NULL;
void create(vector<int>&arr)
{
    first=new Node();
    first->data=arr[0];
    first->next=NULL;
    Node *last;
    last=first;
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
int32_t main(void)
{
    vector<int>arr={3,5,7,10,15};
    create(arr);
    Node *temp;
    // display(first);
    cout<<"Maximum element in the linked list is->"<<max_el(first)<<endl;
}
