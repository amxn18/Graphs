#include <bits/stdc++.h>
using namespace std;

vector<int> bfsTraversal(int V, vector<int> adj[]) {
    vector<int> bfs;
    vector<bool> visited(V, false);
    queue<int> q;
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) { // for disconnected components
            q.push(i);
            visited[i] = true;

            while(!q.empty()) {
                int node = q.front(); 
                q.pop();
                bfs.push_back(node);

                for(auto neighbor : adj[node]) {
                    if(!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    return bfs;
}
