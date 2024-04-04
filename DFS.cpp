#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    // recursive for each connected node
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{

    // prepare adjList

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<vector<int>> edgeList;
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        edgeList.push_back({u, v});
    }

    vector<vector<int>> result = depthFirstSearch(vertices, edges, edgeList);

    cout << "Connected Components:" << endl;
    for (const auto &component : result)
    {
        for (int node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}