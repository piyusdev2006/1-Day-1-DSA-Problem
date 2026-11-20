class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxVal = nums.back() + 2;
        vector<int> dp(maxVal, 0);
        int ans = 1;

        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};