#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void BFS(int u, vector<int> adj[],
         bool visited[])
{

    queue<int> q;

    visited[u] = true;
    q.push(u);

    while (!q.empty())
    {

        u = q.front();
        q.pop();
        cout << u << " ";

        for (int x : adj[u])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void BFSdisconn(vector<int> adj[], int v)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            BFS(i, adj, visited);
}

int main()
{
    int v = 7;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 6, 5);
    BFSdisconn(adj, v);
    return 0;
}