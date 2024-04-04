#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // N th relaxation to check negative cycle
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1}; // Negative cycle detected
            }
        }

        return dist;
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3)); // Edges in the format {u, v, wt}

    // Input the edges and their weights
    for (int i = 0; i < E; i++) {
        cout << "Enter edge " << i + 1 << " (u v wt): ";
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    Solution obj;
    vector<int> distances = obj.bellman_ford(V, edges, source);

    if (distances[0] == -1) {
        cout << "Negative cycle detected. No shortest paths exist.\n";
    } else {
        // Print the distances from the source vertex
        cout << "Shortest distances from source vertex " << source << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "To vertex " << i << ": " << distances[i] << "\n";
        }
    }

    return 0;
}
