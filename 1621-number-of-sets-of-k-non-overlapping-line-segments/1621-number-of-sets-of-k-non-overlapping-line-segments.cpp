class Solution {

    int MOD = 1e9 + 7;
    int dp[1005][1005][2];

    int solve(int i, int k, int isStarted, int n) {
        if (k == 0)
            return 1;
        if (i == n)
            return 0;

        if (dp[i][k][isStarted] != -1)
            return dp[i][k][isStarted];

        long long ans = 0;
        if (isStarted == 0) {
            ans = (ans + solve(i + 1, k, 0, n)) % MOD;
            ans = (ans + solve(i + 1, k, 1, n)) % MOD;
        } else {
            ans = (ans + solve(i + 1, k, 1, n)) % MOD;
            ans = (ans + solve(i, k - 1, 0, n)) % MOD;
        }
        return dp[i][k][isStarted] = ans;
    }

public:
    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, k, 0, n);
    }
};

