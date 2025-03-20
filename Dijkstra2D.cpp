#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        typedef pair<int, pair<int,int>> p;
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        int dijkstra2D(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
    
            priority_queue<p, vector<p>, greater<p>> pq;
            auto isSafe = [&](int x, int y){
                return x >= 0 && x < m && y >= 0 && y < n;
            };
            vector<vector<int>> result(m, vector<int>(n, INT_MAX));
    
            result[0][0] = grid[0][0];
            pq.push({grid[0][0], {0, 0}});
    
            while(!pq.empty()) {
                int cost = pq.top().first;
                auto coordinate = pq.top().second;
                pq.pop();
                int x = coordinate.first;
                int y = coordinate.second;
    
                for(auto &dir : dirs) {
                    int X = x + dir[0];
                    int Y = y + dir[1];
    
                    if(isSafe(X, Y)) {
                        int newCost = cost + grid[X][Y];
                        if(result[X][Y] > newCost) {
                            result[X][Y] = newCost;
                            pq.push({newCost, {X, Y}});
                        }
                    }
                }
            }
    
            return result[m-1][n-1];
        }
    };
    