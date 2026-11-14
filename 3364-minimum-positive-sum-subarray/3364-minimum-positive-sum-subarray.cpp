class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;

        for (int i = 0; i < n; i++) {
            int currentSum = 0;
            for (int j = i; j < n; j++) {
                currentSum += nums[j];
                int len = j - i + 1;
                if (len >= l && len <= r && currentSum > 0) {
                    minSum = min(minSum, currentSum);
                }
            }
        }

        return (minSum == INT_MAX) ? -1 : minSum;
    }
};