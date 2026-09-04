class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // Step 1: Precompute Suffix Minimum
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        //traverse left to right and track Prefix Maximum
        int prefixMax = INT_MIN;
        for (int i = 0; i < n; i++) {
            prefixMax = std::max(prefixMax, nums[i]); // Update left max

            //Calculate instability score and check stability
            if (prefixMax - suffixMin[i] <= k) {
                return i; // First stable index found
            }
        }

        return -1; 
    }
};
