//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void dfsFill(int u, vector<vector<int>> &adj, vector<bool> &visited,  stack<int> &st){
        visited[u] = true;
        for(int &v : adj[u]){
            if(!visited[v]) {
                dfsFill(v, adj, visited, st);
            }
        }
        st.push(u);
    }
    
    void dfsTraversal(int u, vector<vector<int>> &revAdj,  vector<bool> &visited ){
        visited[u] = true;
        for(int &v : revAdj[u]){
            if(!visited[v]){
                dfsTraversal(v, revAdj, visited);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // Store order of dfs in stack
        int v = adj.size();
        stack<int> st;
        vector<bool> visited(v, false);
        for(int i=0; i<v; i++){
            if(!visited[i]){
                dfsFill(i, adj, visited, st);
            }
        }
        
        // Make a reverse graph
        vector<vector<int>> revAdj(v);
        for(int u=0; u<v; u++){
            for(int &v : adj[u]){
                revAdj[v].push_back(u);
            }
        }
        
        // call dfs based on stack order
        int ctrSCC = 0;
        // update visited
        visited = vector<bool>(v, false);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                dfsTraversal(node, revAdj, visited);
                ctrSCC++;
            }
        }
        return ctrSCC;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

