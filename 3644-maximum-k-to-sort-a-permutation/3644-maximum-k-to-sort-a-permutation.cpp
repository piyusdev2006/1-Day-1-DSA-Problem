class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;
        bool isSorted = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                isSorted = false;
                k &= nums[i];
            }
        }
        if (isSorted) {
            return 0;
        }
        return k;
    }
};