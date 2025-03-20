#include <bits/stdc++.h>
using namespace std;

bool isBipartiteBFS(int V, vector<int> adj[]) {
    vector<int> color(V, -1);
    
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while(!q.empty()) {
                int node = q.front(); q.pop();
                
                for(auto neighbor : adj[node]) {
                    if(color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if(color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
