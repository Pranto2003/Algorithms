#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj, revAdj;

public:
    Graph(int vertices) : V(vertices), adj(vertices), revAdj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    void dfs(int v, vector<bool>& visited, vector<int>& scc, const vector<vector<int>>& graph) {
        visited[v] = true;
        scc.push_back(v);

        for (int neighbor : graph[v])
            if (!visited[neighbor])
                dfs(neighbor, visited, scc, graph);
    }

    void fillOrder(int v, vector<bool>& visited, stack<int>& stk) {
        visited[v] = true;

        for (int neighbor : adj[v])
            if (!visited[neighbor])
                fillOrder(neighbor, visited, stk);

        stk.push(v);
    }

    vector<vector<int>> stronglyConnectedComponents() {
        vector<bool> visited(V, false);
        stack<int> stk;

        for (int i = 0; i < V; ++i)
            if (!visited[i])
                fillOrder(i, visited, stk);

        fill(visited.begin(), visited.end(), false);

        vector<vector<int>> sccResult;
        while (!stk.empty()) {
            int v = stk.top();
            stk.pop();

            if (!visited[v]) {
                vector<int> scc;
                dfs(v, visited, scc, revAdj);
                sccResult.push_back(scc);
            }
        }

        return sccResult;
    }
};

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    Graph graph(vertices);

    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    vector<vector<int>> sccResult = graph.stronglyConnectedComponents();

    cout << "Strongly Connected Components" << endl;

    for (const vector<int>& scc : sccResult) {
        for (int vertex : scc)
            cout << vertex << " ";
        cout << endl;
    }

    return 0;
}
