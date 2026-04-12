#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);
    vector<int> topoOrder;
    queue<int> q;

    // 1. Compute in-degrees for all vertices
    for (int i = 0; i < V; i++) {
        for (auto neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    // 2. Push all vertices with in-degree 0 into the queue
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // 3. Process the queue
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        topoOrder.push_back(curr);

        // Decrease in-degree of neighbors
        for (auto neighbor : adj[curr]) {
            inDegree[neighbor]--;
            
            // If in-degree becomes 0, add to queue
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // 4. Check for cycles
    if (topoOrder.size() != V) {
        return {}; // Returns empty vector if a cycle exists
    }

    return topoOrder;
}

int main() {
    int V = 6;
    vector<int> adj[6];

    // Example edges
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topologicalSort(V, adj);

    if (result.empty()) {
        cout << "Cycle detected! Topological sort not possible.";
    } else {
        for (int node : result) cout << node << " ";
    }

    return 0;
}