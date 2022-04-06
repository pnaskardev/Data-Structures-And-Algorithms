#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int u, int A[][8], int n)
{
    int visited[8] {0};
    stack<int> stk;
    stk.emplace(u);
    while (!stk.empty())
    {
        u = stk.top();
        stk.pop();
 
        if (visited[u] != 1)
        {
            cout << u << ", " << flush;
            visited[u] = 1;
            for (int v=n-1; v>=0; v--)
            {
                if (A[u][v] == 1 && visited[v] == 0)
                {
                    stk.emplace(v);
                }
            }
        }
    }
}

void BFS(int vtx, int A[][8], int n)
{
    queue<int> Q;
    int visited[8] {0};
 
    // Initially starting the BFS by starting from any element 
    cout << vtx << ", " << flush;  // Visit vertex
    visited[vtx] = 1;
    Q.emplace(vtx);
 
    // Explore
    while (!Q.empty())
    {
        int u = Q.front();  // Vertex u for exploring
        Q.pop();
        for (int v=1; v<=n; v++)
        {  
            // Adjacent vertices of vertex u
            if (A[u][v] == 1 && visited[v] == 0)
            {  // Adjacent vertex and not visited
                cout << v << ", " << flush;  // Visit vertex
                visited[v] = 1;
                Q.emplace(v);
            }
        }
    }
    cout << endl;
}
 
int main ()
{
 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);
 
    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8);
 
 
    return 0;
}