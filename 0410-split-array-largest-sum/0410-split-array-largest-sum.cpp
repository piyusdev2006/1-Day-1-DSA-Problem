class Solution {
private:
    bool isPossible(vector<int>& nums, int k, int max_sum_limit) {
        int subarrays = 1;
        int current_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max_sum_limit)
                return false;

            if (current_sum + nums[i] <= max_sum_limit) {
                current_sum += nums[i];
            } else {
                subarrays++;
                current_sum = nums[i];
            }
        }

        return subarrays <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;

        for (int i = 0; i < nums.size(); i++) {
            low = max(low, nums[i]);
            high += nums[i];
        }

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};