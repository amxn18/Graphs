// Bellman-Ford Algorithm - Single Source Shortest Path
// Time Complexity: O(V * E), where V = number of vertices, E = number of edges
// Handles negative weights and detects negative weight cycles

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
            // Step 1: Initialize distances from src to all vertices as infinite (1e8) / INT_MAX
            vector<int> dist(V, 1e8);
            dist[src] = 0;
    
            // Step 2: Relax all edges (V - 1) times
            for (int i = 1; i <= V - 1; i++) {
                for (auto &edge : edges) {
                    int u = edge[0];
                    int v = edge[1];
                    int wt = edge[2];
    
                    if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
    
            // Step 3: Check for negative-weight cycles
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
    
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    // Negative cycle detected
                    return { -1 };
                }
            }
    
            return dist;
        }
    };
    