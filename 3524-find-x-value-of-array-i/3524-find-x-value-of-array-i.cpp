class Solution {
private:
    vector<long long> solve(int i, vector<int>& nums, int k, vector<vector<long long>>& memo, vector<bool>& visited) {
        if (i == nums.size()) {
            return vector<long long>(k, 0);
        }
        
        if (visited[i]) {
            return memo[i];
        }
        
        vector<long long> current_res(k, 0);
        long long numMod = nums[i] % k;
        
        current_res[numMod] += 1;
        
        vector<long long> next_res = solve(i + 1, nums, k, memo, visited);
        
        for (int r = 0; r < k; r++) {
            if (next_res[r] > 0) {
                int newMod = (r * numMod) % k;
                current_res[newMod] += next_res[r]; 
            }
        }
        
        visited[i] = true;
        return memo[i] = current_res;
    }

public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<vector<long long>> memo(n, vector<long long>(k, 0));
        vector<bool> visited(n, false);
        vector<long long> ans(k, 0);
        
        solve(0, nums, k, memo, visited);
        
        for (int i = 0; i < n; i++) {
            for (int r = 0; r < k; r++) {
                ans[r] += memo[i][r];
            }
        }
        
        return ans;
    }
};