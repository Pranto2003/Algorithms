#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findParent(int node, vector<int> &parent)
    {
        if (parent[node] == -1)
            return node;
        return findParent(parent[node], parent);
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int weight = it[1];
                int node = i;

                edges.push_back({weight, {node, adjNode}});
            }
        }

        sort(edges.begin(), edges.end());
        vector<int> parent(V, -1);
        int mstWeight = 0;

        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            int parentU = findParent(u, parent);
            int parentV = findParent(v, parent);

            if (parentU != parentV)
            {
                mstWeight += wt;
                parent[parentU] = parentV;
            }
        }
        return mstWeight;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj[V];

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges and their weights (format: vertex1 vertex2 weight):\n";
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); // Assuming undirected graph
    }

    Solution obj;
    int result = obj.spanningTree(V, adj);

    cout << "Minimum Spanning Tree Weight: " << result << endl;

    return 0;
}
