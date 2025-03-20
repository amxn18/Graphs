#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        typedef pair<int, int> p;
    
        
        int spanningTree(int V, vector<vector<int>> adj[]) {
            priority_queue<p, vector<p>, greater<p>> pq;
            pq.push({0, 0});
    
            vector<bool> inMst(V, false);
            vector<int> parent(V, -1); // Initialize parent array
            int sum = 0;
    
            while (!pq.empty()) {
                auto p = pq.top();
                pq.pop();
    
                int wt = p.first;
                int node = p.second;
    
                if (inMst[node] == true) continue;
    
                inMst[node] = true;
                sum += wt;
    
                for (auto &tp : adj[node]) {
                    int neighbour = tp[0];
                    int neighbourWt = tp[1];
    
                    if (inMst[neighbour] == false) {
                        pq.push({neighbourWt, neighbour});
                        parent[neighbour] = node; // Store the parent
                    }
                }
            }
    
            // Optional: parent[] now stores MST tree structure
            return sum;
        }
    };
    