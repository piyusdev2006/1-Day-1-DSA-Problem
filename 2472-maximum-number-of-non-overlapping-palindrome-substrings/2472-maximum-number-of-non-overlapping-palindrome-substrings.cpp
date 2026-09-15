class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        for (int diff = 0; diff < n; diff++) {
            for (int i = 0; i + diff < n; i++) {
                int j = i + diff;
                if (s[i] == s[j]) {
                    if (diff <= 1) {
                        isPal[i][j] = true;
                    } 
                    else {
                        isPal[i][j] = isPal[i + 1][j - 1];
                    }
                }
            }
        }
        
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            
            for (int j = i - k; j >= 0; j--) {
                if (isPal[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n];
    }
};