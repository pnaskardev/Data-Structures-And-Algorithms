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
int32_t main(void)
{
    vector<int>arr={10,20,30,40,50};
    create_circular(arr);
    display(head);
    
}
