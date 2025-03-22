#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS and return the farthest node and its distance from the source
pair<int, int> bfs(unordered_map<int, vector<int>> adj, int source) {
    queue<int> q;
    q.push(source);
    unordered_map<int, bool> visited;
    visited[source] = true;

    int distance = 0;
    int farthestNode = source;

    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            int curr = q.front();
            q.pop();
            farthestNode = curr;

            for (auto &neighbour : adj[curr]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        if (!q.empty()) distance++;
    }

    return {farthestNode, distance};
}

int findDia(unordered_map<int, vector<int>> adj){
    // Find the farthest node from a random node --> 0
    auto [farthestNode, dist] = bfs(adj, 0);
    // Farthest node we got is one end of diameter
    // Find the farthest node from the node we got above that will be the other end of dia
    auto[otherNode, diameter] = bfs(adj, farthestNode); 
    return diameter;
}

