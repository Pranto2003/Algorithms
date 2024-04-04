#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], int visited[], vector<int> &list)
    {
        visited[node] = 1;
        list.push_back(node);

        // traverse all its neighbours
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited, list);
            }
        }
    }

public:
    vector<int> dfsGraph(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        int start = 0;
        vector<int> list;
        dfs(start, adj, visited, list);
        return list;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<int> adj[V];

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (format: vertex1 vertex2):\n";
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    Solution obj;
    vector<int> result = obj.dfsGraph(V, adj);

    // Print the DFS traversal result
    cout << "DFS Traversal: ";
    for (int node : result)
    {
        cout << node << " ";
    }

    return 0;
}
