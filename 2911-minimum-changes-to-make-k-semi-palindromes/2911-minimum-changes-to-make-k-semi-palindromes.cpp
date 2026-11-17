class Solution {
public:
    int getSemiCost(string &s, int start, int end) {
        int len = end - start + 1;
        if (len < 2) return 1e9;
        int minChanges = 1e9;

        for (int d = 1; d < len; d++) {
            if (len % d == 0) {
                int changes = 0;
                for (int rem = 0; rem < d; rem++) {
                    int l = start + rem;
                    int r = end - d + 1 + rem;
                    while (l < r) {
                        if (s[l] != s[r]) changes++;
                        l += d;
                        r -= d;
                    }
                }
                minChanges = min(minChanges, changes);
            }
        }
        return minChanges;
    }

    int solve(int i, int k, int n, vector<vector<int>> &cost, vector<vector<int>> &dp) {
        if (i == n) return (k == 0) ? 0 : 1e9;
        if (k == 0) return 1e9;
        if (dp[i][k] != -1) return dp[i][k];

        int ans = 1e9;
        for (int j = i + 1; j < n; j++) {
            int currCost = cost[i][j] + solve(j + 1, k - 1, n, cost, dp);
            ans = min(ans, currCost);
        }
        return dp[i][k] = ans;
    }

    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = getSemiCost(s, i, j);
            }
        }
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(0, k, n, cost, dp);
    }
};
