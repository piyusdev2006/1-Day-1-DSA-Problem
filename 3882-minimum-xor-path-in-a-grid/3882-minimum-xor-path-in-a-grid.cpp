class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(2048, false)));
        
        dp[0][0][grid[0][0]] = true;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 2048; ++k) {
                    if (!dp[i][j][k]) continue;
                    
                    if (j + 1 < n) {
                        dp[i][j + 1][k ^ grid[i][j + 1]] = true;
                    }
                    if (i + 1 < m) {
                        dp[i + 1][j][k ^ grid[i + 1][j]] = true;
                    }
                }
            }
        }
        
        for (int k = 0; k < 2048; ++k) {
            if (dp[m - 1][n - 1][k]) {
                return k;
            }
        }
        
        return -1;
    }
};
