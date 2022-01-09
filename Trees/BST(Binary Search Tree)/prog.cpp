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
Node* deleteNode(Node* root, int key);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
int main(void)
{
    int x;
    Node *root=NULL;
    root = recursive_insert(root, 50);
    root = recursive_insert(root, 30);
    root = recursive_insert(root, 20);
    root = recursive_insert(root, 40);
    root = recursive_insert(root, 70);
    root = recursive_insert(root, 60);
    root = recursive_insert(root, 80);
    cout<<"inorder->";
    inorder(root);
    cout<<endl;
    // root=deleteNode(root,20);
    // do
    // {
    //     cout<<"Press 1 to insert into the binary tree:-"<<endl;
    //     cout<<"Press 2 to insert iteratively into the binary tree:-"<<endl;
    //     cout<<"Press 3 to search into the binary tree:-"<<endl;
    //     cout<<"Press 4 to delete from the binary tree:-"<<endl;
    //     cout<<"Press -1 to stop"<<endl;
    //     cin>>x;
    //     if(x==1)
    //     {
    //         int t;
    //         cout<<"Enter the value:";
    //         cin>>t;
    //         root=recursive_insert(root,t);
    //     }
    //     if(x==2)
    //     {
    //         int t;
    //         cout<<"Enter the value:";
    //         cin>>t;
    //         root=iterative_insert(root,t);
    //     }
    //     if(x==3)
    //     {
    //         int t;
    //         cout<<"Enter the value you want to insert:";
    //         cin>>t;
    //         Node *temp=search(root,t);
    //         if(temp!=NULL)
    //         {
    //             cout<<"The value we were searching for is found and the value is"<<temp->data<<endl;
    //         }
    //         else
    //         {
    //             cout<<"The value is not found"<<endl;
    //             int p;
    //             cout<<"If you would like to insert the val into the BST press 1 else press any numeric key:"<<endl;
    //             cin>>p;
    //             if(p==1)
    //             {
    //                 recursive_insert(root,t);
    //             }
    //             else
    //             {
    //                 continue;
    //             }
    //         }
    //     }
    //     if(x==4)
    //     {
    //         int t;
    //         cout<<"enter the value you want to delete:";
    //         cin>>t;
    //         root=deleteNode(root,t);
    //     }
    // } while (x!=-1);
    
    cout<<"inorder->";
    inorder(root);
    cout<<endl;
    cout<<"preorder->";
    preorder(root);
    cout<<endl;
    cout<<"postorder->";
    postorder(root);
    cout<<endl;
}
Node* minValueNode(Node* node)
{
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
         root->right = deleteNode(root->right, key);
    }
    else 
    {
        if (root->left==NULL and root->right==NULL)
        {
            return NULL;
        }
        else if (root->left == NULL) 
        {
            Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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

void postorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}