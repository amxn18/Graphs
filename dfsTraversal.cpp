#include <bits/stdc++.h>
using namespace std;

void dfsHelper(int node, vector<bool>& visited, vector<int> adj[], vector<int>& dfs) {
    visited[node] = true;
    dfs.push_back(node);

    for(auto neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfsHelper(neighbor, visited, adj, dfs);
        }
    }
}

vector<int> dfsTraversal(int V, vector<int> adj[]) {
    vector<int> dfs;
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfsHelper(i, visited, adj, dfs);
        }
    }

    return dfs;
}

