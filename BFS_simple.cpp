#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> bfs(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        visited[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
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
    vector<int> result = obj.bfs(V, adj);

    // Print the BFS traversal result
    cout << "BFS Traversal: ";
    for (int node : result)
    {
        cout << node << " ";
    }

    return 0;
}
