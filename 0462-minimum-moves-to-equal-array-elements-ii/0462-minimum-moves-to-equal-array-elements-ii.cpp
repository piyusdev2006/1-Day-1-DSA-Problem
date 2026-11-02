class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        
        int medianIdx = n / 2;
        
        nth_element(nums.begin(), nums.begin() + medianIdx, nums.end());
        
        int medianValue = nums[medianIdx];
        int totalMoves = 0;
        
        for (int num : nums) {
            totalMoves += abs(num - medianValue);
        }

        return totalMoves;
    }
};


