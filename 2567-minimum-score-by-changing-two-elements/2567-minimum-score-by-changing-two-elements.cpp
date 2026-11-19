class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int case1 = nums[n - 3] - nums[0];
        int case2 = nums[n - 1] - nums[2];
        int case3 = nums[n - 2] - nums[1];

        return min({case1, case2, case3});
    }
};