#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int M=100005;
vector<vector<int>> adj(M,vector<int>());
long long int vis[M];
void add_edge(int x,int y);
void print_tree(int nodes);
void DFS(int node,int parent);
void BFS();
int main(void)
{
    int n,x,y;
    cin>>n;
    // if we have n nodes we have n-1 edges in normal TREE
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        add_edge(x,y);
    }  
    print_tree(n);
    DFS(1,-1);
    BFS();
    cout<<endl;
}


void add_edge(int x,int y)
{
    // x--;
    // y--;
    adj[x].emplace_back(y);
    adj[y].emplace_back(x);
}

void BFS()
{
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        vis[x]=1;
        for(auto next:adj[x])
        {
            if(!vis[next])
            {
                q.push(next);
            }
        }
    }
}

void DFS(int node,int parent)
{
    cout<<node<<endl;
    if(adj[node].size()==1)
    {
        return;
    }
    for(auto nextnode:adj[node])
    {
        if(parent!=nextnode)
        {
            DFS(nextnode,node);
        }
    }
    return;
}

void print_tree(int nodes)
{
    for(int i=1;i<nodes+1;i++)
    {
        cout<<i<<"->";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}