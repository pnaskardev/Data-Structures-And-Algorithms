#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};

void create(Node *&first, Node *&rear, vector<int>arr);
void display(Node *&first, Node *&rear);
int main(void)
{
    Node *first=NULL,*rear=NULL;
    vector<int>arr={10,20,30,40,50,60};
    create(first,rear,arr);
    display(first,rear);
}
void create(Node *&first,Node*&rear,vector<int>arr)
{
    first=new Node();
    first->data=arr[0];
    first->next=NULL;
    rear=first;
    Node *temp;
    for(int i=1;i<arr.size();i++)
    {
        temp=new Node();
        temp->data=arr[i];
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
}
void display(Node *&first, Node *&rear)
{
    Node *p;
    p=first;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}