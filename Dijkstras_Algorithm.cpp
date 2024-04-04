#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX); // Initialize distances to infinity
        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];
                if (dis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main()
{
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj[V]; // Adjacency list

    // Input the edges and their weights
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cout << "Enter edge (u v w): ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Assuming an undirected graph
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    Solution obj;
    vector<int> distances = obj.dijkstra(V, adj, source);

    // Print the distances from the source vertex
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "To vertex " << i << ": " << distances[i] << "\n";
    }

    return 0;
}
