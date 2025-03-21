#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS to visit all reachable vertices from vertex 'u'
    void dfs(vector<int> adj[], int u, vector<bool> &visited) {
        visited[u] = true;

        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            int neighbour = *it;
            if (visited[neighbour] == false) {
                dfs(adj, neighbour, visited);
            }
        }
    }

    // Check if all non-zero degree vertices are connected
    bool isConnected(int V, vector<int> adj[]) {
        // Pick the first vertex with a non-zero degree
        int nonZeroVertex = -1;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() != 0) {
                nonZeroVertex = i;
                break;
            }
        }

        // If there are no edges in the graph
        if (nonZeroVertex == -1)
            return true;

        // Run DFS from a vertex with non-zero degree
        vector<bool> visited(V, false);
        dfs(adj, nonZeroVertex, visited);

        // After DFS, check if all non-zero degree vertices were visited
        for (int i = 0; i < V; i++) {
            if (visited[i] == false && adj[i].size() > 0) {
                return false;
            }
        }

        return true;
    }

    // Main function to check for Euler Path or Circuit
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Check if all non-zero degree vertices are connected
        if (isConnected(V, adj) == false) {
            return 0;
        }

        // Count vertices with odd degree
        int oddDegreeVertex = 0;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0) {
                oddDegreeVertex++;
            }
        }

        // If more than 2 vertices have odd degree => No Euler Path/Circuit
        if (oddDegreeVertex > 2) return 0;

        // If exactly 2 vertices have odd degree => Euler Path exists
        if (oddDegreeVertex == 2) return 1;

        // If 0 odd degree vertices => Euler Circuit exists
        if (oddDegreeVertex == 0) return 2;

        return 0; // fallback (shouldn't reach here logically)
    }
};

int main() {
    // You can add your test cases here if needed
    return 0;
}
