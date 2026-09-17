class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLen(n, INT_MAX); 
        
        int sum = 0;       
        int left = 0;      
        int ans = INT_MAX; 
        int best_so_far = INT_MAX; 
        
        for (int right = 0; right < n; ++right) {
            sum += arr[right]; 
            
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }
            
            if (sum == target) {
                int currLen = right - left + 1; 
                
                if (left > 0 && minLen[left - 1] != INT_MAX) {
                    ans = min(ans, currLen + minLen[left - 1]);
                }
                
                best_so_far = min(best_so_far, currLen);
            }
            
            minLen[right] = best_so_far;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};