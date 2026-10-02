#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        // Initializing arrays with n+1 to safely handle both 1-based and 0-based graphs
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        // Path compression: assigning the parent to the ultimate parent 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        // If they have the same ultimate parent, they are already in the same component
        if (ulp_u == ulp_v) return;
        
        // Attach the component with the smaller rank to the one with the larger rank
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            // If ranks are equal, attach one to the other and increment the rank of the new parent
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if (ulp_u == ulp_v) return;
        
        // Attach the smaller component to the larger component and update the size
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main() {
    cout << "--- Testing Union By Size ---\n";
    DisjointSet ds1(7);
    
    ds1.unionBySize(1, 2);
    ds1.unionBySize(2, 3);
    ds1.unionBySize(4, 5);
    ds1.unionBySize(6, 7);
    ds1.unionBySize(5, 6);
    
    if (ds1.findUPar(3) == ds1.findUPar(7)) cout << "Same\n";
    else cout << "Not same\n";

    ds1.unionBySize(3, 7);
    
    if (ds1.findUPar(3) == ds1.findUPar(7)) cout << "Same\n";
    else cout << "Not same\n";


    cout << "\n--- Testing Union By Rank ---\n";
    DisjointSet ds2(7); // Creating a fresh instance to demonstrate rank
    
    ds2.unionByRank(1, 2);
    ds2.unionByRank(2, 3);
    ds2.unionByRank(4, 5);
    ds2.unionByRank(6, 7);
    ds2.unionByRank(5, 6);
    
    if (ds2.findUPar(3) == ds2.findUPar(7)) cout << "Same\n";
    else cout << "Not same\n";

    ds2.unionByRank(3, 7);
    
    if (ds2.findUPar(3) == ds2.findUPar(7)) cout << "Same\n";
    else cout << "Not same\n";
    
    return 0;
}
