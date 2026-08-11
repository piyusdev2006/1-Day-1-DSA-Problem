class Solution {
public:

    int dp[305][15];

    int solve(int index, int days, vector<int>& jobs) {

        int n = jobs.size();

        // Last day gets all remaining jobs
        if (days == 1) {

            int mx = 0;

            for (int i = index; i < n; i++) {
                mx = max(mx, jobs[i]);
            }

            return mx;
        }

        if (dp[index][days] != -1) {
            return dp[index][days];
        }

        int ans = INT_MAX;
        int mx = 0;

        // Current day takes jobs[index ... i]
        for (int i = index; i <= n - days; i++) {

            mx = max(mx, jobs[i]);

            int next =
                solve(i + 1, days - 1, jobs);

            ans = min(
                ans,
                mx + next
            );
        }

        return dp[index][days] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {

        int n = jobDifficulty.size();

        if (n < d)
            return -1;

        memset(dp, -1, sizeof(dp));

        return solve(0, d, jobDifficulty);
    }
};