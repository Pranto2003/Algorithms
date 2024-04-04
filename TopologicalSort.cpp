#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(int node, int visited[], stack<int> &st, vector<int> adj[])
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, visited, st, adj);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int visited[V] = {0};
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    // Create an adjacency list
    vector<int> adj[V];
    cout << "Enter the edges (format: u v):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution s;
    vector<int> result = s.topoSort(V, adj);

    cout << "Topological Sort: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
