#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &stk) {
    vis[node] = true;
    for (int &v : adj[node]) {
        if (!vis[v]) {
            dfs(v, adj, vis, stk);
        }
    }
    stk.push(node); // Push after visiting all neighbours
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    stack<int> stk;

    for (int i = 0; i < V; ++i) {
        if (!vis[i]) {
            dfs(i, adj, vis, stk);
        }
    }

    vector<int> result;
    while (!stk.empty()) {
        result.push_back(stk.top());
        stk.pop();
    }

    return result;
}
