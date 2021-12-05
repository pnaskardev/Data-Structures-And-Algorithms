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
};
Node *recursive_insert(Node *root,int val);
Node *iterative_insert(Node *root,int val);
Node *search(Node *root,int val);
void inorder(Node *root);
void preorder(Node *root);
int main(void)
{
    int x;
    Node *root=NULL;
    do
    {
        cout<<"Press 1 to insert into the binary tree"<<endl;
        cout<<"Press 2 to insert iteratively into the binary tree"<<endl;
        cout<<"Press 3 to search into the binary tree"<<endl;
        cout<<"Press 4 to search from the binary tree"<<endl;
        cin>>x;
        if(x==1)
        {
            int t;
            cout<<"Enter the value:";
            cin>>t;
            root=recursive_insert(root,t);
        }
        if(x==2)
        {
            int t;
            cout<<"Enter the value:";
            cin>>t;
            root=iterative_insert(root,t);
        }
        if(x==3)
        {
            int t;
            cout<<"Enter the value you want to insert:";
            cin>>t;
            Node *temp=search(root,t);
            if(temp!=NULL)
            {
                cout<<"The value we were seaeching for is found and the value is"<<temp->data<<endl;
            }
            else
            {
                cout<<"The value is not found"<<endl;
                int p;
                cout<<"If you would like to insert the val into the BST press 1 else press -1:"<<endl;
                cin>>p;
                if(p==1)
                {
                    recursive_insert(root,t);
                }
                else
                {
                    continue;
                }
            }
        }
    } while (x!=-1);
    
    cout<<"inorder->";
    inorder(root);
    cout<<endl;
    cout<<"preorder->";
    preorder(root);
    cout<<endl;
}

Node *recursive_insert(Node *root,int val)
{

    if(root==NULL)
    {
        root=new Node();
        root->data=val;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if(val<root->data)
    {
        root->left=recursive_insert(root->left,val);
        root->left->parent=root;
    }
    else if(val>root->data)
    {
        root->right=recursive_insert(root->right,val);
        root->right->parent=root;
    }
    return root;
}

Node *iterative_insert(Node *root,int val)
{
    Node *t=root;
    Node *r=NULL,*p=NULL;
    if(root==NULL)
    {
        p=new Node();
        p->data=val;
        p->left=NULL;
        p->right=NULL;
        root=p;
        return root;
    }
    while(t!=NULL)
    {
        r=t;
        if(val<t->data)
        {
            t=t->left;
        }
        else if(val>t->data)
        {
            t=t->right;
        }
        else
        {
            return root;
        }
    }
    p=new Node();
    p->data=val;
    if(val<r->data)
    {
        r->left=p;
    }
    else
    {
        r->right=p;
    }
    return root;
}

Node *search(Node *root,int val)
{
    Node *t=root;
    while(t!=NULL)
    {
        if(val==t->data)
        {
            return t;
        }
        else if(val<t->data)
        {
            t=t->left;
        }
        else
        {
            t=t->right;
        }
    }
    return NULL;
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