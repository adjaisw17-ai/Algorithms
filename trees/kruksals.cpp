#include <vector>
#include <algorithm>

using namespace std;

// Disjoint Set Union (DSU) / Union-Find Logic
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

struct Edge {
    int u, v, weight;
    // Sorting logic for Minimum Spanning Tree
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class KruskalsAlgo {
public:
    int minSpanningTree(int n, vector<Edge>& edges) {
        // 1. Sort edges by weight
        sort(edges.begin(), edges.end());

        DSU dsu(n);
        int mstWeight = 0;
        int edgesCount = 0;

        // 2. Iterate through sorted edges
        for (const auto& edge : edges) {
            // 3. If nodes are not in the same component, add edge
            if (dsu.unite(edge.u, edge.v)) {
                mstWeight += edge.weight;
                edgesCount++;
            }
        }

        // Return weight if all nodes connected, else -1
        return (edgesCount == n - 1) ? mstWeight : -1;
    }
};