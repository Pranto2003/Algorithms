#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<pair<int, int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> visited(V, 0);

        //{weight,node}
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int weight = it.first;

            if (visited[node] == 1)
            {
                continue;
            }
            else
            {
                visited[node] = 1;
                sum += weight;
                for (auto neighbor : adj[node])
                {
                    int adjNode = neighbor.first;
                    int edgeWeight = neighbor.second;
                    if (!visited[adjNode])
                    {
                        pq.push({edgeWeight, adjNode});
                    }
                }
            }
        }
        return sum;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<pair<int, int>> adj[V];

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
