class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - x;
        
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        
        int n = nums.size();
        int left = 0;
        int currentSum = 0;
        int maxLen = -1;
        
        for (int right = 0; right < n; right++) {
            currentSum += nums[right];
            
            while (currentSum > target && left <= right) {
                currentSum -= nums[left];
                left++;
            }
            
            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen == -1 ? -1 : n - maxLen;
    }
};