#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BFS function to find the farthest node and distance from the given start node
    int bfs(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited, int& farthestNode) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        visited[start] = true;

        int maxDist = 0;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (dist > maxDist) {
                maxDist = dist;
                farthestNode = node;
            }

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, dist + 1});
                }
            }
        }
        return maxDist;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int n = 0; // number of nodes (we'll find max node index to size visited vector)

        // Build adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            n = max(n, max(u, v));
        }

        vector<bool> visited(n + 1, false);
        int farthestNode = -1;

        // First BFS to find farthest node from any starting point
        bfs(edges[0][0], adj, visited, farthestNode);

        // Second BFS from farthest node to find the diameter
        fill(visited.begin(), visited.end(), false); // reset visited
        int diameter = bfs(farthestNode, adj, visited, farthestNode);

        return diameter;
    }
};
