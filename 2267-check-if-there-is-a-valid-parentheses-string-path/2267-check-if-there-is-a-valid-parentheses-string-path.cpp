class Solution {

    int dp[105][105][205];

    bool solve(int i, int j, int bal, vector<vector<char>>& grid, int m,
               int n) {
        if (i >= m || j >= n)
            return false;

        bal += (grid[i][j] == '(' ? 1 : -1);

        if (bal < 0 || bal > (m + n) / 2)
            return false;

        if (i == m - 1 && j == n - 1)
            return bal == 0;

        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        return dp[i][j][bal] = solve(i + 1, j, bal, grid, m, n) ||
                               solve(i, j + 1, bal, grid, m, n);
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, grid, m, n);
    }
};