#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// Helper for DFS-based Topo Sort
void topoSort(int u, vector<pair<int, int>> adj[], vector<bool>& visited, stack<int>& s) {
    visited[u] = true;
    for (auto neighbor : adj[u]) {
        if (!visited[neighbor.first]) {
            topoSort(neighbor.first, adj, visited, s);
        }
    }
    s.push(u);
}

void shortestPathDAG(int V, int source, vector<pair<int, int>> adj[]) {
    stack<int> s;
    vector<bool> visited(V, false);

    // 1. Get Topological Sort
    for (int i = 0; i < V; i++) {
        if (!visited[i]) topoSort(i, adj, visited, s);
    }

    // 2. Initialize Distances
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // 3. Relax edges in Topo Order
    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (dist[u] != INT_MAX) { // Only relax if node is reachable
            for (auto neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Print Results
    for (int i = 0; i < V; i++) {
        (dist[i] == INT_MAX) ? cout << "INF " : cout << dist[i] << " ";
    }
}

int main() {
    int V = 6;
    vector<pair<int, int>> adj[6];
    adj[0].push_back({1, 5});
    adj[0].push_back({2, 3});
    adj[1].push_back({3, 6});
    adj[1].push_back({2, 2});
    adj[2].push_back({4, 4});
    adj[2].push_back({5, 2});
    adj[2].push_back({3, 7});
    adj[3].push_back({4, -1}); // Works with negative weights!
    adj[4].push_back({5, -2});

    shortestPathDAG(V, 1, adj);
    return 0;
}