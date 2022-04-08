#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
 
class BST
{
    private:
        Node* root;
    public:
        BST()
        { 
            root = nullptr; 
        }
        Node* getRoot()
        { 
            return root; 
        }
        void iterative_insert(int key);
        Node* recursive_iterative_insert(Node* p,int key);
        void Inorder(Node* p);
        void Preorder(Node* p);
        void Postorder(Node* p);
        vector<vector<int>>levelorder(Node *p);
        Node* Search(int key);
};

Node* BST::recursive_iterative_insert(Node *p, int key) 
{
    Node* t;
    if(p==root && p==nullptr)
    {
        root = new Node;
        root->data = key;
        root->lchild = nullptr;
        root->rchild = nullptr;
        return root;
    }
    if (p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }
 
    if (key < p->data)
    {
        p->lchild = recursive_iterative_insert(p->lchild, key);
    } 
    else if (key > p->data)
    {
        p->rchild = recursive_iterative_insert(p->rchild, key);
    }
    return p;  // key == p->data?
}

void BST::iterative_insert(int key) 
{
 
    Node* t = root;
    Node* p;
    Node* r;
 
    // root is empty
    if (root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }
 
    while(t != nullptr)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        } 
        else if (key > t->data)
        {
            t = t->rchild;
        } 
        else 
        {
            return;
        }
    }
 
    // Now t points at NULL and r points at iterative_insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;
 
    if (key < r->data)
    {
        r->lchild = p;
    } 
    else 
    {
        r->rchild = p;
    }
 
}
 
void BST::Inorder(Node* p) 
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void BST::Preorder(Node *p)
{
    if(p==NULL)
    {
        return;
    }
    cout<<p->data<<", "<<flush;
    Preorder(p->lchild);
    Preorder(p->rchild);
}

void::BST::Postorder(Node *p)
{
    if(p==NULL)
    {
        return;
    }
    Postorder(p->lchild);
    Postorder(p->rchild);
    cout<<p->data<<", "<<flush;
}


vector<vector<int>>BST::levelorder(Node *p)
{
    vector<vector<int>>ans;
    if(p==NULL)
    {
        return ans;
    }
    queue<Node*>q;
    q.push(p);
    while(!q.empty())
    {
        vector<int>level;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* t=q.front();
            q.pop();
            if(t->lchild!=NULL)
            {
                q.push(t->lchild);
            }
            if(t->rchild!=NULL)
            {
                q.push(t->rchild);
            }
            level.push_back(t->data);
        }
        ans.push_back(level);
    }
    return ans;
}

Node* BST::Search(int key) 
{
    Node* t = root;
    while (t != nullptr)
    {
        if(key == t->data)
        {
            return t;
        } 
        else if(key < t->data)
        {
            t = t->lchild;
        } 
        else 
        {
            t = t->rchild;
        }
    }
    return nullptr;
}
 
 
int main() 
{
 
    BST bst;
 
    // iterative_insert
    // bst.iterative_insert(10);
    // bst.iterative_insert(5);
    // bst.iterative_insert(20);
    // bst.iterative_insert(8);
    // bst.iterative_insert(30);

    // recursive insert
    bst.recursive_iterative_insert(bst.getRoot(),50);
    bst.recursive_iterative_insert(bst.getRoot(),70);
    bst.recursive_iterative_insert(bst.getRoot(),1);
    bst.recursive_iterative_insert(bst.getRoot(),30);
    bst.recursive_iterative_insert(bst.getRoot(),35);

    if(bst.getRoot()==NULL)
    {
        cout<<"root is null"<<endl;
    }
    // Inorder traversal
    if(bst.getRoot()!=NULL)
    {
        // Inorder
        bst.Inorder(bst.getRoot());
        cout << endl;

        // Pre order
        cout<<"Pre-order->";
        bst.Preorder(bst.getRoot());
        cout<<endl;
        
        // Postorder
        cout<<"Post-order->";
        bst.Postorder(bst.getRoot());
        cout<<endl;



        // LEVELORDER TRAVERSAL
        cout<<"Levelorder traversal->"<<endl;
        auto res=bst.levelorder(bst.getRoot());
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }




        // Search
        // Node* temp = bst.Search(10);
        // if (temp != nullptr)
        // {
        //     cout << temp->data << endl;
        // } 
        // else 
        // {
        //     cout << "Element not found" << endl;
        // }

    }

    return 0;
}