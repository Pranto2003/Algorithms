#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <climits>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimeMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    // let's start the algo
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // find the min node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min node as true;
        mst[u] = true;

        // check its adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }
    return result;
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<pair<pair<int, int>, int>> edgeList;
    cout << "Enter the edges and weights (format: u v w):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(make_pair(make_pair(u, v), w));
    }

    vector<pair<pair<int, int>, int>> result = calculatePrimeMST(nodes, edges, edgeList);

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const auto &edge : result)
    {
        cout << "(" << edge.first.first << ", " << edge.first.second << ") Weight: " << edge.second << endl;
    }

    return 0;
}
