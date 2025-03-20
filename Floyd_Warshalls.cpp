#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();

        // Step 1: Convert -1 to a large number (1e9) to represent 'infinity'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == -1)
                    mat[i][j] = 1e9;
                if (i == j)
                    mat[i][j] = 0;
            }
        }

        // Step 2: Floyd-Warshall Algorithm core logic
        for (int via = 0; via < n; ++via) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (mat[i][via] < 1e9 && mat[via][j] < 1e9)
                        mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }

        // Step 3: Convert large number back to -1 to indicate no path
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1e9)
                    mat[i][j] = -1;
            }
        }
    }
};