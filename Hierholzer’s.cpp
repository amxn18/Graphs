#include <bits/stdc++.h>
using namespace std;
// To find Euler Path 
class Solution {
    public:
        vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
            // Building adj list
            unordered_map<int, vector<int>> adj;
            // Building indegree and outdegree
            unordered_map<int,int> indegree, outdegree;
            // Key --> Node
            // Value --> indeg/outdeg
    
            for(auto &edge : pairs){
                int u = edge[0];
                int v = edge[1];
    
                // u --> v
                adj[u].push_back(v); 
                outdegree[u]++;
                indegree[v]++;
            }
            // Finding starting Node of Euler path
            int startNode = pairs[0][0];
            for(auto &it : adj){
                int node = it.first;
                if(outdegree[node] - indegree[node] == 1) {
                    startNode = node;
                    break;
                }
            }
    
            // Dfs
            vector<int> eulerPath;
            stack<int> st;
            st.push(startNode);
    
            while(!st.empty()){
                int curr = st.top();
                // If there are more then one nodes in {} adh list so we are storing that in neighbour and pop_back means a--> {x,y} so pop_back y then x and push that y first then x in stack
                if(!adj[curr].empty()){
                    int neighbour = adj[curr].back();
                    adj[curr].pop_back();
                    st.push(neighbour);
                } else {
                    eulerPath.push_back(curr);
                    st.pop();
                }
            }
            reverse(begin(eulerPath), end(eulerPath));
            vector<vector<int>> result;
            for(int i=0; i<eulerPath.size()-1; i++){
                result.push_back({eulerPath[i], eulerPath[i+1]});
            }
            return result;
        }
    };
