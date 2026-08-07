class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(32);

        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < 32; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int ans = 0;
        int prev_bit = 0;

        for (int i = 30; i >= 0; i--) {

            if (n & (1 << i)) {

                // Put 0 instead of n's 1
                ans += dp[i];

                // Consecutive 1 detected
                if (prev_bit == 1) {
                    return ans;
                }

                prev_bit = 1;

            } else {
                prev_bit = 0;
            }
        }

        // n itself is valid
        return ans + 1;
    }
};