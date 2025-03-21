#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) class with path compression and union by rank
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;

        // Union by rank
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

// Kruskal's algorithm implementation
int Kruskal(vector<vector<int>> &vec, int V) {
    DSU dsu(V);
    int sum = 0;

    for (auto &temp : vec) {
        int u = temp[0];
        int v = temp[1];
        int wt = temp[2];

        int parent_u = dsu.find(u);
        int parent_v = dsu.find(v);

        if (parent_u != parent_v) {
            dsu.Union(u, v);
            sum += wt;
        }
    }
    return sum;
}

// Function to convert adjacency list to edge list and apply Kruskal
int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<vector<int>> vec;

    for (int u = 0; u < V; u++) {
        for (auto &temp : adj[u]) {
            int v = temp[0];
            int wt = temp[1];

            vec.push_back({u, v, wt});
        }
    }

    // Sort edges by weight
    auto comparator = [&](vector<int> &vec1, vector<int> &vec2) {
        return vec1[2] < vec2[2];
    };

    sort(begin(vec), end(vec), comparator);

    return Kruskal(vec, V);
}
