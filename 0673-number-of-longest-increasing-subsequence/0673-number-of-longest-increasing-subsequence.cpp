class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        
        vector<int> length(n, 1);
        vector<int> count(n, 1);
        
        int max_len = 1;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    } else if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }
            max_len = max(max_len, length[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            if (length[i] == max_len) {
                ans += count[i];
            }
        }
        
        return ans;
    }
};