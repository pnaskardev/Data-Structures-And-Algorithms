#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    Node *left;
    Node *right;
    Node *parent; 
    int data;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node *insert(Node *root,int val);
void inorder(Node *root);
void preorder(Node *root);
int main(void)
{
    int x;
    Node *root=NULL;
    do
    {
        cout<<"Press 1 to insert into the binary tree"<<endl;
        cin>>x;
        if(x==1)
        {
            int t;
            cout<<"Enter the value:";
            cin>>t;
            root=insert(root,t);
        }
    } while (x!=-1);
    
    cout<<"inorder->";
    inorder(root);
    cout<<endl;
    cout<<"preorder->";
    preorder(root);
    cout<<endl;
}

Node *insert(Node *root,int val)
{
    if(root==NULL)
    {
        root=new Node(val);
        return root;
    }
    if(val<root->data)
    {
        root->left=insert(root->left,val);
        root->left->parent=root;
    }
    else
    {
        root->right=insert(root->right,val);
        root->right->parent=root;
    }
    return root;
}


void inorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}