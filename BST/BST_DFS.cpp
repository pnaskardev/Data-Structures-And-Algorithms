#include <iostream>

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
        // void dfs();
        void iterative_insert(int key);
        Node* recursive_iterative_insert(Node* p,int key);
        void Inorder(Node* p);
        void Preorder(Node* p);
        void Postorder(Node* p);
        Node* Search(int key);
};

// void BST::dfs()
// {
//     Node *p=root;
//     if(root==nullptr)
//     {
//         cout<<"Root is NULL and tree doesn exist"<<flush;
//     }
//     else
//     {
//         cout<<
//     }
// }

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
    bst.recursive_iterative_insert(bst.getRoot(),10);
    bst.recursive_iterative_insert(bst.getRoot(),5);
    bst.recursive_iterative_insert(bst.getRoot(),20);
    bst.recursive_iterative_insert(bst.getRoot(),8);
    bst.recursive_iterative_insert(bst.getRoot(),30);
    

    if(bst.getRoot()==NULL)
    {
        cout<<"root is null"<<endl;
    }
    if(bst.getRoot()!=NULL)
    {
        cout<<"Inorder->";
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

    // perfoming dfs on trees represented as adjacency list




    return 0;
}