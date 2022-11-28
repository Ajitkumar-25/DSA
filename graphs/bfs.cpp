#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void addEdge(vector<int> arr[], int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
void BFS(vector<int> arr[], int v, int s)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int x : arr[u])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
int main()
{
    int v = 4;
    int s = 0;
    vector<int> arr[v];
    addEdge(arr, 0, 1);
    addEdge(arr, 0, 2);
    addEdge(arr, 1, 2);
    addEdge(arr, 1, 3);
    BFS(arr, v, s);
}