#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DFS traversal to check if all reachable vertices are visited
    void dfs(vector<int> adj[], int u, vector<bool> &visited) {
        visited[u] = true;
        for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
            int neighbour = *it;
            if(visited[neighbour] == false) {
                dfs(adj, neighbour, visited);
            }
        }
    }

    // Function to check if all vertices with non-zero degree are connected
    bool isConnected(int V, vector<int> adj[]) {
        int nonZeroVertex = -1;
        for(int i = 0; i < V; i++) {
            if(adj[i].size() != 0) {
                nonZeroVertex = i;
                break;
            }
        }

        // If all vertices have 0 degree (isolated nodes)
        if(nonZeroVertex == -1) return true;

        vector<bool> visited(V, false);
        dfs(adj, nonZeroVertex, visited);

        // If DFS does not visit all non-zero degree vertices, graph is not connected
        for(int i = 0; i < V; i++) {
            if(visited[i] == false && adj[i].size() > 0) {
                return false;
            }
        }

        return true;
    }

    // Function to check Euler Path or Circuit in a Directed Graph
    int isEulerDirected(int V, vector<int> adj[]) {
        if(isConnected(V, adj) == false) return 0;

        // Vectors to store in-degree and out-degree of each vertex
        vector<int> indeg(V, 0), outdeg(V, 0);

        // Fill in-degree and out-degree
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                outdeg[i]++;
                indeg[it]++;
            }
        }

        int startNodes = 0, endNodes = 0;

        for(int i = 0; i < V; i++) {
            if(outdeg[i] - indeg[i] == 1) startNodes++;
            else if(indeg[i] - outdeg[i] == 1) endNodes++;
            else if(indeg[i] != outdeg[i]) return 0; // Not balanced
        }

        // Euler Circuit: all indegree == outdegree
        if(startNodes == 0 && endNodes == 0) return 2;

        // Euler Path (not circuit): only one start and one end node
        if(startNodes == 1 && endNodes == 1) return 1;

        return 0; // Otherwise, not Eulerian
    }
};
