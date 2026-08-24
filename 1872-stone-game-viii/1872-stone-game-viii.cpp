class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        // Step 1: Compute prefix sums
        vector<int> prefix(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        
        // Step 2: Initialize result starting from the last valid choice
        int res = prefix[n - 1];
        
        // Step 3: Iterate backwards from n-2 down to 1
        for (int i = n - 2; i >= 1; --i) {
            res = max(res, prefix[i] - res);
        }
        
        return res;
    }
};