#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int col, vector<int>& color, vector<int> adj[]) {
    color[node] = col;
    
    for(auto neighbor : adj[node]) {
        if(color[neighbor] == -1) {
            if(!dfs(neighbor, 1 - col, color, adj))
                return false;
        } else if(color[neighbor] == col) {
            return false;
        }
    }
    return true;
}

bool isBipartiteDFS(int V, vector<int> adj[]) {
    vector<int> color(V, -1);
    
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            if(!dfs(i, 0, color, adj))
                return false;
        }
    }
    return true;
}
