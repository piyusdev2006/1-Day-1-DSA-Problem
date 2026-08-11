class Solution {
public:
    int solve(string& s, int index, int last, int k, vector<vector<int>>& dp) {
        if (index == s.size())
            return 0;

        if (dp[index][last + 1] != -1)
            return dp[index][last + 1];

        // Skip
        int skip = solve(s, index + 1, last, k, dp);

        // Take
        int take = 0;

        if (last == -1 || abs(s[index] - s[last]) <= k) {
            take = 1 + solve(s, index + 1, index, k, dp);
        }

        return dp[index][last + 1] = max(take, skip);
    };

    int longestIdealString(string s, int k) {
         vector<int> dp(26, 0);

        int ans = 0;

        for (char ch : s) {

            int curr = ch - 'a';

            int best = 0;

            for (int prev = 0; prev < 26; prev++) {

                if (abs(curr - prev) <= k) {
                    best = max(best, dp[prev]);
                }
            }

            dp[curr] = best + 1;

            ans = max(ans, dp[curr]);
        }

        return ans;
    }
};