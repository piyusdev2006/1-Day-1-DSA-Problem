class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        vector<int> count(32, 0);
        
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                if ((num >> i) & 1) {
                    count[i]++;
                }
            }
        }
        
        long long ans = 0;
        
        for (int i = 0; i < k; i++) {
            long long currentNum = 0;
            for (int j = 0; j < 32; j++) {
                if (count[j] > 0) {
                    currentNum |= (1LL << j);
                    count[j]--;
                }
            }
            ans = (ans + (currentNum * currentNum) % MOD) % MOD;
        }
        
        return ans;
    }
};