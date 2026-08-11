class Solution {
public:

    int dp[105][105];

    int solve(int i, int countA, vector<vector<int>>& costs) {

        int n = costs.size() / 2;

        if (i == costs.size()) {
            if (countA == n)
                return 0;

            return 1e9;
        }

        if (dp[i][countA] != -1) {
            return dp[i][countA];
        }

        int goA = 1e9;
        int goB = 1e9;

        // Can send to A only if A isn't full
        if (countA < n) {
            goA = costs[i][0]
                + solve(i + 1, countA + 1, costs);
        }

        // Number of people sent to B
        int countB = i - countA;

        // B must also have less than n
        if (countB < n) {
            goB = costs[i][1]
                + solve(i + 1, countA, costs);
        }

        return dp[i][countA] = min(goA, goB);
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, costs);
    }
};